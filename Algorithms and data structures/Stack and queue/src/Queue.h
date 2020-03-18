#ifndef QUEUE_H
#define QUEUE_H

template <typename T, typename Container>
class Queue
{
private:
    Container _container;

public:
    Queue(std::initializer_list<T>);
    Queue(const Container& container);
    Queue(const Queue& container);

    bool empty() const noexcept;
    std::size_t size() const noexcept;

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    void push(T&&);
    void push(const T&);
    void pop();  
};

#include "Queue.cpp"

#endif
