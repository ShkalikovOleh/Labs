#include "Queue.h"

template<typename T, typename Container>
Queue<T, Container>::Queue(){   }

template<typename T, typename Container>
Queue<T, Container>::Queue(std::initializer_list<T> values)
{
    for (auto &&value : values)
    {
        push(value);
    }    
}

template<typename T, typename Container>
Queue<T, Container>::Queue(const Container& container)
{
    _container = container;
}

template<typename T, typename Container>
Queue<T, Container>::Queue(const Queue<T, Container>& other)
{
    _container = other._container;
}

template<typename T, typename Container>
std::size_t Queue<T, Container>::size() const noexcept
{
    _container.size();
}

template<typename T, typename Container>
bool Queue<T, Container>::empty() const noexcept
{
    _container.empty();
}

template<typename T, typename Container>
T& Queue<T, Container>::front()
{
    _container.front();
}

template<typename T, typename Container>
T& Queue<T, Container>::back()
{
    _container.back();
}

template<typename T, typename Container>
const T& Queue<T, Container>::front() const
{
    _container.front();
}

template<typename T, typename Container>
const T& Queue<T, Container>::back() const
{
    _container.back();
}

template<typename T, typename Container>
void Queue<T, Container>::push(T&& value)
{
    _container.push_back(value);
}

template<typename T, typename Container>
void Queue<T, Container>::push(const T& value)
{
    _container.push_back(value);
}

template<typename T, typename Container>
void Queue<T, Container>::pop()
{
    _container.pop_front();
}