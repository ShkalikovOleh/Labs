#ifndef IQUEUE_H
    #define IQUEUE_H

template<typename T>
class IQueue
{
public:
    virtual bool empty() const noexcept = 0;
    virtual std::size_t size() const noexcept = 0;

    virtual T& front() = 0;
    virtual const T& front() const = 0;
    virtual T& back() = 0;
    virtual const T& back() const = 0;

    virtual void push(T&&) = 0;
    virtual void push(const T&) = 0;
    virtual void pop() = 0;
};

#endif