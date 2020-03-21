#ifndef STACK_H
#define STACK_H

template <typename T, typename Container>
class Stack
{
private:
    Container _container;

public:
    Stack();
    Stack(std::initializer_list<T>);
    Stack(const Container& container);
    Stack(const Stack& container);

    bool empty() const noexcept;
    std::size_t size() const noexcept;

    T& top();
    const T& top() const;    

    void push(T&&);
    void push(const T&);
    void pop();  
};

#include "Stack.cpp"

#endif