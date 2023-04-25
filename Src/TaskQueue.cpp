//
// Created by Alex on 2023/4/23.
//

#include "../Headers/TaskQueue.h"
template<typename T>
TaskQueue<T>::TaskQueue() {
    pthread_mutex_init(&m_mutex, nullptr);
}

template<typename T>
TaskQueue<T>::~TaskQueue() {
    pthread_mutex_destroy(&m_mutex);
}

template<typename T>
void TaskQueue<T>::add_task(Task<T> task) {
    pthread_mutex_lock(&m_mutex);
    m_task.push(task);
    pthread_mutex_unlock(&m_mutex);
}

template<typename T>
void TaskQueue<T>::add_task(callback function, void *arg) {
    pthread_mutex_lock(&m_mutex);
    m_task.emplace(function,arg);
    pthread_mutex_unlock(&m_mutex);
}

template<typename T>
Task<T> TaskQueue<T>::take_task() {
    pthread_mutex_lock(&m_mutex);
    if (!m_task.empty()){
        Task<T> t = m_task.front();
        m_task.pop();
        return t;
    }
    pthread_mutex_unlock(&m_mutex);
    return Task<T>();
}


