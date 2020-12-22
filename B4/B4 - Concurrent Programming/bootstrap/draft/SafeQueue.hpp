/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#ifndef BOOTSTRAP_SAFEQUEUE_HPP
#define BOOTSTRAP_SAFEQUEUE_HPP

#include <cstddef>
#include <condition_variable>
#include <list>

template <typename T>
class SafeQueue
{
    public:
        // Returns whether could push/pop or queue was closed.  Currently, we only implemented the blocking
        // operations.
        enum QueueResult
        {
            OK,
            CLOSED
        };

        // Initialize the queue with a maximal size.
        explicit SafeQueue(size_t maxSize = 0) : _state(State::OPEN), _currentSize(0), _maxSize(maxSize) {};

        // Push v to queue.  Blocks if queue is full.
        void push(T const & v)
        {
            // Create temporary queue.
            decltype(_list) tmpList;
            tmpList.push_back(v);

            // Pushing with lock, only using list<>::splice().
            {
                std::unique_lock<std::mutex> lock(_mutex);

                // Wait until there is space in the queue.
                while (_currentSize == _maxSize)
                    _cvPush.wait(lock);

                // Check that the queue is not closed and thus pushing is allowed.
                if (_state == State::CLOSED)
                    throw std::runtime_error("Trying to push to a closed queue.");

                // Push to queue.
                _currentSize += 1;
                _list.splice(_list.end(), tmpList, tmpList.begin());

                // Wake up one popping thread.
                if (_currentSize == 1)
                    _cvPop.notify_one();
            }
        }

        // Pop value from queue and write to v.
        //
        // If this succeeds, OK is returned.  CLOSED is returned if the queue is empty and was closed.
        QueueResult pop(T & v)
        {
            decltype(_list) tmpList;

            // Pop into tmpList which is finally written out.
            {
                std::unique_lock<std::mutex> lock(_mutex);

                // If there is no item then we wait until there is one.
                while (_list.empty() && _state != State::CLOSED)
                    _cvPop.wait(lock);

                // If the queue was closed and the list is empty then we cannot return anything.
                if (_list.empty() && _state == State::CLOSED)
                    return CLOSED;

                // If we reach here then there is an item, get it.
                _currentSize -= 1;
                tmpList.splice(tmpList.begin(), _list, _list.begin());
                // Wake up one pushing thread.
                _cvPush.notify_one();
            }

            // Write out value.
            v = tmpList.front();

            return OK;
        }

        // Pushing data is not allowed any more, when the queue is
        void close() noexcept
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _state = State::CLOSED;

            // Notify all consumers.
            _cvPop.notify_all();
        }

    private:
        // Whether the queue is running or closed.
        enum class State
        {
            OPEN,
            CLOSED
        };

        // The current state.
        State _state;
        // The current size.
        size_t _currentSize;
        // The maximal size.
        size_t _maxSize;
        // The condition variables to use for pushing/popping.
        std::condition_variable _cvPush;
        std::condition_variable _cvPop;
        // The mutex for locking the queue.
        std::mutex _mutex;
        // The list that the queue is implemented with.
        std::list<T> _list;
};

#endif //BOOTSTRAP_SAFEQUEUE_HPP
