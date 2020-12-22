#include <iostream>
#include <pthread.h>
#include <cstring>
#include "ex02.hpp"

pthread_t tid[5];
Mutex mutex;

void incrementCounter(int &counter)
{
    for (int i = 0; i < 50000; i++)
        counter++;
}

void *threadFunction(void *arg)
{
    mutex.lock();
    int *i = reinterpret_cast<int*>(arg);
    incrementCounter(*i);
    mutex.unlock();
    return (NULL);
}

int main(void)
{
    int i = 0;
    int err;
    int counter = 0;

    while(i < 5) {
        err = pthread_create(&(tid[i]), NULL, &threadFunction, &counter);
        if (err != 0)
            std::cout << std::endl << "can't create thread :[" << strerror(err) << "]" << std::endl;
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
    pthread_join(tid[4], NULL);

    std::cout << counter << std::endl;

    return 0;
}