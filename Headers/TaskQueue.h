//
// Created by Alex on 2023/4/23.
//

#ifndef CPPTHREADPOOL_TASKQUEUE_H
#define CPPTHREADPOOL_TASKQUEUE_H

#include "queue"
#include "thread"
#include "pthread.h"

using callback = void (*)(void *arg);

template<typename T>
struct Task{
    // 构造函数
    Task()
    {
        function=nullptr;
        arg= nullptr;
    };
    Task(callback f,T* arg)
    :function(f),arg(arg)
    {};

    callback function;
    T* arg;
};

template<typename T>
class TaskQueue {
public:
    TaskQueue();
    ~TaskQueue();

    //add the task into the queue
    void add_task(Task<T> task);
    void add_task(callback function,void *arg);
    //get the task from the head of the queue
    Task<T> take_task();
    //get the size of queue
    inline int tasknumber()
    {
        return m_task.size();
    }


private:
    std::queue<Task<T>> m_task;
private:
    pthread_mutex_t m_mutex{};

};


#endif //CPPTHREADPOOL_TASKQUEUE_H
