#include "Stack.h"

template<typename T, typename Container>
Stack<T, Container>::Stack(){   }

template<typename T, typename Container>
Stack<T, Container>::Stack(std::initializer_list<T> values)
{
    for (auto &&value : values)
    {
        push(value);
    }  
}

template<typename T, typename Container>
Stack<T, Container>::Stack(const Container& container)
{
    _container = container;
}

template<typename T, typename Container>
Stack<T, Container>::Stack(const Stack<T, Container>& other)
{
    _container = other._container;
}

template<typename T, typename Container>
std::size_t Stack<T, Container>::size() const noexcept
{
    _container.size();
}

template<typename T, typename Container>
bool Stack<T, Container>::empty() const noexcept
{
    _container.empty();
}

template<typename T, typename Container>
T& Stack<T, Container>::top()
{
    _container.back();
}

template<typename T, typename Container>
const T& Stack<T, Container>::top() const
{
    _container.back();
}

template<typename T, typename Container>
void Stack<T, Container>::push(T&& value)
{
    _container.push_back(value);
}

template<typename T, typename Container>
void Stack<T, Container>::push(const T& value)
{
    _container.push_back(value);
}

template<typename T, typename Container>
void Stack<T, Container>::pop()
{
    _container.pop_back();
}