#ifndef DUAL_STACK_H
    #define DUAL_STACK_H

#include <memory>
#include "IStack.h"

template<typename T, uint capacity, typename Allocator = std::allocator<T>>
class DualStack : IStack<T>
{
    enum State
    {
        First,
        Second,
        NotSelected
    };

private:
    T* _data;
    int _size1;
    int _size2;    

    Allocator _allocator;

    State state;
    void checkState();

public:
    DualStack();
    DualStack(const DualStack& container);
    ~DualStack();

    DualStack& first() noexcept;
    DualStack& second() noexcept;
    DualStack& unset() noexcept;

    State getState() const noexcept;

    bool empty() const noexcept override;
    std::size_t size() const noexcept override;

    T& top() override;

    void push(T&&) override;
    void push(const T&) override;
    void pop() override;
};

#include "DualStack.cpp"

#endif