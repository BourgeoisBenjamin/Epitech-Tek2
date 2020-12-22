/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#ifndef BOOTSTRAP_SCOPEDLOCK_HPP
#define BOOTSTRAP_SCOPEDLOCK_HPP

#include "../ex02/ex02.hpp"

class ScopedLock
{
public:
    ScopedLock(Mutex &mutex);
    ~ScopedLock();

private:
    Mutex &_mutex;
};

#endif //BOOTSTRAP_SCOPEDLOCK_HPP
