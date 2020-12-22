#include <iostream>
#include <cstring>
#include "../ex03/ScopedLock.hpp"
#include "Thread.hpp"

Mutex mutex;

void incrementCounter(int &counter)
{
    for (int i = 0; i < 50000; i++)
        counter++;
}

void *threadFunction(void *arg)
{
    ScopedLock lock(mutex);
    int *i = reinterpret_cast<int*>(arg);
    incrementCounter(*i);
    return (NULL);
}

int main(void)
{
    int i = 0;
    int err;
    int counter = 0;

    Thread thread1(threadFunction, &counter);
    Thread thread2(threadFunction, &counter);
    Thread thread3(threadFunction, &counter);
    Thread thread4(threadFunction, &counter);
    Thread thread5(threadFunction, &counter);

    thread1.wait();
    thread2.wait();
    thread3.wait();
    thread4.wait();
    thread5.wait();

    std::cout << counter << std::endl;

    return 0;
}