#include <iostream>
#include <ctime>
#include "../Headers/ThreadPool.h"
#include "../Src/ThreadPool.cpp"

// 模拟任务所需的时间（以秒为单位）
const int TASK_TIME = 1;

void taskFunction(void* arg) {
    int taskId = *(int*)arg;
    printf("Thread %ld is working on task %d\n", pthread_self(), taskId);
    sleep(TASK_TIME);
    printf("Task %d is completed by thread %ld\n", taskId, pthread_self());
}

int main() {
    const int MIN_THREADS = 3;
    const int MAX_THREADS = 10;
    const int TOTAL_TASKS = 100;
    const int TASK_BATCH_SIZE = 5;

    ThreadPool<int> pool(MIN_THREADS, MAX_THREADS);

    srand(time(NULL));

    int currentTaskId = 0;
    while (currentTaskId < TOTAL_TASKS) {
        int batchSize = std::min(TASK_BATCH_SIZE, TOTAL_TASKS - currentTaskId);

        // 添加任务批次
        for (int i = 0; i < batchSize; ++i) {
            int* taskIdPtr = new int(currentTaskId);
            pool.addTask(Task<int>(taskFunction, taskIdPtr));
            currentTaskId++;
        }

        // 随机等待一段时间，以模拟实际工作负载
        sleep(rand() % 3 + 1);

        // 获取线程池的状态
        int busyThreads = pool.getBusyNumber();
        int aliveThreads = pool.getAliveNumber();

        printf("Busy threads: %d, Alive threads: %d\n", busyThreads, aliveThreads);
    }

    // 等待所有任务完成
    sleep(TOTAL_TASKS * TASK_TIME / MIN_THREADS + 5);

    return 0;
}
