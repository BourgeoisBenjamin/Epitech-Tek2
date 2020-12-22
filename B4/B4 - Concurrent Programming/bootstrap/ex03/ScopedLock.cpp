/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(Mutex &mutex) : _mutex(mutex)
{
    _mutex.lock();
}

ScopedLock::~ScopedLock()
{
    _mutex.unlock();
}