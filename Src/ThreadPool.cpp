//
// Created by Alex on 2023/4/23.
//

#include <cstring>
#include <unistd.h>
#include "../Headers/ThreadPool.h"


template <typename T>
ThreadPool<T>::ThreadPool(int minNum, int maxNum) {
    // 实例化任务队列
    m_taskQ = new TaskQueue<T>();
    do {
        //initialize the thread pool
        m_minNum = minNum;
        m_maxNum = maxNum;
        m_busyNum = 0;
        m_aliveNum = minNum;

        // 根据线程的最大上限给线程数组分配内存
        m_threadIDs = new pthread_t[m_maxNum];
        if (m_threadIDs == nullptr){
            std::cout<<"malloc thread_t[] failed"<<std::endl;
            break;
        }
        // 初始化
        memset(m_threadIDs,0,sizeof(pthread_t) * m_maxNum);
        if (pthread_mutex_init(&m_lock, nullptr)!=0 || pthread_cond_init(&m_notEmpty, nullptr))
        {
            std::cout << "init mutex or condition fail..." << std::endl;
            break;
        }

        /////////////////// 创建线程 //////////////////
        // 根据最小线程个数, 创建线程
        for (int i = 0; i < m_minNum; ++i) {
            pthread_create(&m_threadIDs[i], nullptr,worker, nullptr);
            std::cout<<"creating son thread, id: "<<std::to_string(m_threadIDs[i])<<std::endl;
        }
        //create the single manager thread
        pthread_create(&m_managerID, nullptr,manager, nullptr);

    } while (false);

}

template <typename T>
ThreadPool<T>::~ThreadPool() {
    m_shutdown=true;
    // 销毁管理者线程
    pthread_join(m_managerID,nullptr);
    // 唤醒所有消费者线程
    for (int i = 0; i < m_aliveNum; ++i) {
        pthread_cond_signal(&m_notEmpty);
    }

    if (m_taskQ) delete m_taskQ;
    if (m_threadIDs) delete m_threadIDs;
    pthread_mutex_destroy(&m_lock);
    pthread_cond_destroy(&m_notEmpty);
}

template <typename T>
void ThreadPool<T>::addTask(const Task<T> task) {
    //Judge the thread pool whether is on
    if (m_shutdown) perror("The thread pool has been shutdown");
    m_taskQ->add_task(task);
    // 唤醒工作的线程
    pthread_cond_signal(&m_notEmpty);
}

template <typename T>
int ThreadPool<T>::getBusyNumber() {
    int busyNum = 0;
    pthread_mutex_lock(&m_lock);
    busyNum = m_busyNum;
    pthread_mutex_unlock(&m_lock);
    return busyNum;
}

template <typename T>
int ThreadPool<T>::getAliveNumber() {
    int threadNum = 0;
    pthread_mutex_lock(&m_lock);
    threadNum = m_aliveNum;
    pthread_mutex_unlock(&m_lock);
    return threadNum;
}

template <typename T>
void *ThreadPool<T>::worker(void *arg) {
    auto* pool = static_cast<ThreadPool*>(arg);
    while(true){
        // 访问任务队列(共享资源)加锁
        pthread_mutex_lock(&pool->m_lock);
        // 判断任务队列是否为空, 如果为空工作线程阻塞
        while(pool->m_taskQ->tasknumber() == 0 && !pool->m_shutdown){
            std::cout<<"thread"<<std::to_string(pthread_self())<<"waiting..."<<std::endl;
            // 阻塞worker线程
            pthread_cond_wait(&pool->m_notEmpty,&pool->m_lock);
        }
        // 判断线程池是否被关闭了
        if (pool->m_shutdown){
            pthread_mutex_unlock(&pool->m_lock);
            pool->threadExit();
        }
        // 从任务队列中取出一个任务
        Task<T> task = pool->m_taskQ->take_task();
        // 工作的线程+1
        pthread_mutex_lock(&pool->m_lock);
        pool->m_busyNum++;
        // 线程池解锁
        pthread_mutex_unlock(&pool->m_lock);
        // 执行任务
        std::cout << "thread " << std::to_string(pthread_self()) << " start working..." << std::endl;
        task.function(task.arg);
        delete task.arg;
        task.arg = nullptr;

        // 任务处理结束
        std::cout << "thread " << std::to_string(pthread_self()) << " end working...";
        pthread_mutex_lock(&pool->m_lock);
        pool->m_busyNum--;
        pthread_mutex_unlock(&pool->m_lock);
    }
    return nullptr;
}

// 管理者线程任务函数
template <typename T>
void* ThreadPool<T>::manager(void* arg)
{
    auto* pool = static_cast<ThreadPool*>(arg);
    // 如果线程池没有关闭, 就一直检测
    while (!pool->m_shutdown)
    {
        // 每隔5s检测一次
        sleep(5);
        // 取出线程池中的任务数和线程数量
        //  取出工作的线程池数量
        pthread_mutex_lock(&pool->m_lock);
        int queueSize = pool->m_taskQ->tasknumber();
        int liveNum = pool->m_aliveNum;
        int busyNum = pool->m_busyNum;
        pthread_mutex_unlock(&pool->m_lock);

        // 创建线程
        const int NUMBER = 2;
        // 当前任务个数>存活的线程数 && 存活的线程数<最大线程个数
        if (queueSize > liveNum && liveNum < pool->m_maxNum)
        {
            // 线程池加锁
            pthread_mutex_lock(&pool->m_lock);
            int num = 0;
            for (int i = 0; i < pool->m_maxNum && num < NUMBER
                            && pool->m_aliveNum < pool->m_maxNum; ++i)
            {
                if (pool->m_threadIDs[i] == 0)
                {
                    pthread_create(&pool->m_threadIDs[i], nullptr, worker, pool);
                    num++;
                    pool->m_aliveNum++;
                }
            }
            pthread_mutex_unlock(&pool->m_lock);
        }

        // 销毁多余的线程
        // 忙线程*2 < 存活的线程数目 && 存活的线程数 > 最小线程数量
        if (busyNum * 2 < liveNum && liveNum > pool->m_minNum)
        {
            pthread_mutex_lock(&pool->m_lock);
            pool->m_exitNum = NUMBER;
            pthread_mutex_unlock(&pool->m_lock);
            for (int i = 0; i < NUMBER; ++i)
            {
                pthread_cond_signal(&pool->m_notEmpty);
            }
        }
    }
    return nullptr;
}

// 线程退出
template <typename T>
void ThreadPool<T>::threadExit()
{
    pthread_t tid = pthread_self();
    for (int i = 0; i < m_maxNum; ++i)
    {
        if (m_threadIDs[i] == tid)
        {
            std::cout << "threadExit() function: thread "
                 << std::to_string(pthread_self()) << " exiting..." << std::endl;
            m_threadIDs[i] = 0;
            break;
        }
    }
    pthread_exit(nullptr);
}

