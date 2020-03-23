#ifndef STACK_H
    #define STACK_H

#include "IStack.h"

template <typename T, typename Container>
class Stack : public IStack<T>
{    
private:
    Container _container;

public:
    using container_type = Container;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using reference	= typename Container::reference;
    using const_reference = typename Container::const_reference;

    Stack();
    Stack(std::initializer_list<T>);
    Stack(const Container& container);
    Stack(const Stack& container);

    bool empty() const noexcept override;
    std::size_t size() const noexcept override;

    T& top() override;
    const T& top() const;

    void push(T&&) override;
    void push(const T&) override;
    void pop() override;
};

#include "Stack.cpp"

#endif