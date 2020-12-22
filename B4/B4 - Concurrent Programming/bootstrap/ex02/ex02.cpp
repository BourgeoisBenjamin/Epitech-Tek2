/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/
#include <bits/exception.h>
#include "ex02.hpp"

Mutex::Mutex()
{
    if (pthread_mutex_init(&_lock, nullptr) != 0) {
        throw std::exception();
    }
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&_lock);
}

void Mutex::lock()
{
    pthread_mutex_lock(&_lock);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&_lock);
}

void Mutex::trylock()
{

}

