#ifndef ISTACK_H
    #define ISTACK_H

template<typename T>
class IStack
{
public:
    virtual bool empty() const noexcept = 0;
    virtual std::size_t size() const noexcept = 0;

    virtual T& top() = 0;    

    virtual void push(T&&) = 0;
    virtual void push(const T&) = 0;
    virtual void pop() = 0;
};

#endif