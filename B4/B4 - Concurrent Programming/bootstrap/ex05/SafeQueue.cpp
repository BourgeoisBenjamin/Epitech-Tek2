/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#include "SafeQueue.hpp"
#include <iostream>
#include <sstream>
#include <thread>
#include <functional>

#define CONSUMERS 4
#define CONSUME 3
#define STOCK CONSUMERS * CONSUME

void print(std::string x)
{
    static std::mutex mutex;
    std::unique_lock<std::mutex> locker(mutex);
    std::cout << x << "\n";
}

void produce(SafeQueue<int> &queue)
{
    for (int i = 1; i <= STOCK; i++) {
        std::ostringstream tmp;
        tmp << "--> " << i;
        print(tmp.str());
        queue.push(i);
    }
}

void consume(SafeQueue<int> &queue, unsigned int id)
{
    for (int i = 0; i < CONSUME; i++) {
        int item;
        queue.tryPop(item);
        std::ostringstream tmp;
        tmp << "        " << item << " --> C" << id;
        print(tmp.str());
    }
}

int main()
{
    SafeQueue<int> queue;

    // Start the producer thread.
    std::thread prod1(std::bind(produce, std::ref(queue)));

    // Start the consumer threads.
    std::vector<std::thread> consumers;

    for (int i = 0; i < CONSUMERS; i++) {
        std::thread consumer(std::bind(consume, std::ref(queue), i + 1));
        consumers.push_back(std::move(consumer));
    }

    prod1.join();

    for (auto& consumer : consumers) {
        consumer.join();
    }

}
