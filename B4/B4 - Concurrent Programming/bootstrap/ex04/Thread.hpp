/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#ifndef BOOTSTRAP_THREAD_HPP
#define BOOTSTRAP_THREAD_HPP

#include <pthread.h>

class Thread
{
public:
    Thread(void*(*ft)(void *), void *arg);
    ~Thread();

    void wait();

private:
    pthread_t _thread;
};

#endif //BOOTSTRAP_THREAD_HPP
