//
// Created by Alex on 2023/4/23.
//

#ifndef CPPTHREADPOOL_THREADPOOL_H
#define CPPTHREADPOOL_THREADPOOL_H
#include "TaskQueue.h"
#include "../Src/TaskQueue.cpp"
#include "iostream"

template <typename T>
class ThreadPool {
public:
    ThreadPool(int min, int max);
    ~ThreadPool();

    // 添加任务
    void addTask(Task<T> task);
    // 获取忙线程的个数
    int getBusyNumber();
    // 获取活着的线程个数
    int getAliveNumber();

private:
    // 工作的线程的任务函数
    static void* worker(void* arg);
    // 管理者线程的任务函数
    static void* manager(void* arg);
    //single thread exit
    void threadExit();

private:

    pthread_mutex_t m_lock{};
    pthread_cond_t m_notEmpty{};// 任务队列是不是空了
    pthread_t* m_threadIDs;
    pthread_t m_managerID{};
    TaskQueue<T>* m_taskQ;

    int m_minNum;
    int m_maxNum;

    int m_busyNum;//the num of busy thread
    int m_aliveNum;//the num of alive thread
    int m_exitNum{};

    bool m_shutdown = false; //whether to destroy the threadpool

};


#endif //CPPTHREADPOOL_THREADPOOL_H
