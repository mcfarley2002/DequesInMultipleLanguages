#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <deque>

template <typename T>
class Queue
{
public:
    Queue() = default;

    void enqueue(const T &item)
    {
        container.push_back(item);
    }

    T dequeue()
    {
        if (container.empty())
        {
            throw std::out_of_range("Queue is empty");
        }
        T front_item = container.front();
        container.pop_front();
        return front_item;
    }

    bool empty() const
    {
        return container.empty();
    }

private:
    std::deque<T> container;
};

#endif