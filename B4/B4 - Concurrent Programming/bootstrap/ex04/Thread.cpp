/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#include "Thread.hpp"
#include <string.h>
#include <iostream>

Thread::Thread(void*(*ft)(void *), void *arg)
{
    int err = 0;
    err = pthread_create(&_thread, NULL, ft, arg);
    if (err != 0)
        std::cout << std::endl << "can't create thread :[" << strerror(err) << "]" << std::endl;
}

Thread::~Thread()
{
}

void Thread::wait()
{
    pthread_join(_thread, NULL);
}
