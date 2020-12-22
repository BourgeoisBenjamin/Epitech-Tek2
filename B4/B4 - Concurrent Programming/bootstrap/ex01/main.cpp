#include <iostream>
#include <pthread.h>
#include <cstring>

pthread_t tid[5];
pthread_mutex_t lock;

void incrementCounter(int &counter)
{
    for (int i = 0; i < 500000; i++)
        counter++;
}

void *threadFunction(void *arg)
{
    pthread_mutex_lock(&lock);
    int *i = reinterpret_cast<int*>(arg);
    incrementCounter(*i);
    pthread_mutex_unlock(&lock);
    return (NULL);
}

int main(void)
{
    int i = 0;
    int err;
    int counter = 0;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

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

    pthread_mutex_destroy(&lock);
    return 0;
}