/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#ifndef BOOTSTRAP_SAFEQUEUE_HPP
#define BOOTSTRAP_SAFEQUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class ISafeQueue
{
    public:
        virtual ~ISafeQueue() = default;
        virtual void push(const T &value) = 0;
        virtual bool tryPop(T &value) = 0;
};

template <typename T>
class SafeQueue : public ISafeQueue<T>
{
    public:
        SafeQueue() = default;
        ~SafeQueue() = default;
        SafeQueue(const SafeQueue &) = delete;
        SafeQueue &operator=(const SafeQueue&) = delete;

        void push(const T &value)
        {
            {
                std::unique_lock<std::mutex> lock(_mutex);
                _queue.push(value);
            }
            _cV.notify_one();
        }

        bool tryPop(T &value)
        {
            std::unique_lock<std::mutex> lock(_mutex);
            while (_queue.empty())
                _cV.wait(lock);
            value = _queue.front();
            _queue.pop();
        }

    private:
        std::queue<T> _queue;
        std::mutex _mutex;
        std::condition_variable _cV;

};

#endif //BOOTSTRAP_SAFEQUEUE_HPP