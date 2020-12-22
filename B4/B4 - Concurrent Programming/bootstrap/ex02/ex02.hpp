/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#ifndef BOOTSTRAP_EX02_HPP
#define BOOTSTRAP_EX02_HPP

#include <pthread.h>

class IMutex {
public:
    virtual ~IMutex() = default;
    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual void trylock() = 0;
};

class Mutex : public IMutex
{
public:
    Mutex();
    ~Mutex() override;

    void lock() override;
    void unlock() override;
    void trylock() override;

private:
    pthread_mutex_t _lock;
};

#endif //BOOTSTRAP_EX02_HPP
