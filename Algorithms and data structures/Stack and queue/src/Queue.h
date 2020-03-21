#ifndef QUEUE_H
#define QUEUE_H

#include "IQueue.h"

template <typename T, typename Container>
class Queue : public IQueue<T>
{
private:
    Container _container;

public:
    Queue();
    Queue(std::initializer_list<T>);
    Queue(const Container& container);
    Queue(const Queue& container);

    bool empty() const noexcept override;
    std::size_t size() const noexcept override;

    T& front() override;
    const T& front() const override;
    T& back() override;
    const T& back() const override;

    void push(T&&) override;
    void push(const T&) override;
    void pop() override;
};

#include "Queue.cpp"

#endif
