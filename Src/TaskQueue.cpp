//
// Created by Alex on 2023/4/23.
//

#include "../Headers/TaskQueue.h"
#include "iostream"

template<typename T>
TaskQueue<T>::TaskQueue() {
    std::cout<<"Task queue starting"<<std::endl;
    pthread_mutex_init(&m_mutex_queue, NULL);
}

template<typename T>
TaskQueue<T>::~TaskQueue() {
    pthread_mutex_destroy(&m_mutex_queue);
}

template<typename T>
void TaskQueue<T>::add_task(Task<T> task) {
    std::cout<<"Adding a task into the queue..."<<std::endl;
    pthread_mutex_lock(&m_mutex_queue);
    m_queue.push(task);
    pthread_mutex_unlock(&m_mutex_queue);
}

template<typename T>
void TaskQueue<T>::add_task(callback function, void *arg) {
    std::cout<<"Adding a task into the queue..."<<std::endl;
    pthread_mutex_lock(&m_mutex_queue);
//    m_queue.emplace(function,arg);
    m_queue.push(Task<T>(function,arg));
    pthread_mutex_unlock(&m_mutex_queue);
}

template<typename T>
Task<T> TaskQueue<T>::take_task() {
    std::cout<<"Taking a task from the queue..."<<std::endl;
    Task<T> temp;
    pthread_mutex_lock(&m_mutex_queue);
    if (m_queue.size() > 0){
        temp = m_queue.front();
        m_queue.pop();
    }
    pthread_mutex_unlock(&m_mutex_queue);
    return temp;
}


