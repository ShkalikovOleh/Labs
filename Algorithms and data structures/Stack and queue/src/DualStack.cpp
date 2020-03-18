#include "DualStack.h"

template<typename T, uint capacity, typename Allocator>
DualStack<T, capacity, Allocator>::DualStack() : _size1(0), _size2(0), state(State::NotSelected)
{
    _data = _allocator.allocate(capacity);
}

template<typename T, uint capacity, typename Allocator>
DualStack<T, capacity, Allocator>::DualStack(const DualStack& other) : state(State::NotSelected)
{
    _data = _allocator.allocate(capacity);
    for(int i = 0; i < other._size1; i++)
        _data[i] = other._data[i];

    for(int i = 0; i < other._size2; i++)
        _data[capacity - i] = other._data[capacity - i];

    _size1 = other._size1;
    _size2 = other._size2;
}

template<typename T, uint capacity, typename Allocator>
DualStack<T, capacity, Allocator>::~DualStack()
{
    _allocator.deallocate(_data, capacity);
}

template<typename T, uint capacity, typename Allocator>
void DualStack<T, capacity, Allocator>::checkState()
{
    if(state == State::NotSelected)
        throw std::exception(); //must select stack
}

template<typename T, uint capacity, typename Allocator>
DualStack<T, capacity, Allocator>& DualStack<T, capacity, Allocator>::first() noexcept
{
    state = State::First;
    return *this;
}

template<typename T, uint capacity, typename Allocator>
DualStack<T, capacity, Allocator>& DualStack<T, capacity, Allocator>::second() noexcept
{
    state = State::Second;
    return *this;
}

template<typename T, uint capacity, typename Allocator>
DualStack<T, capacity, Allocator>& DualStack<T, capacity, Allocator>::unset() noexcept
{
    state = State::NotSelected;
    return *this;
}

template<typename T, uint capacity, typename Allocator>
typename DualStack<T, capacity, Allocator>::State DualStack<T, capacity, Allocator>::getState() const noexcept
{
    return state;
}

template<typename T, uint capacity, typename Allocator>
bool DualStack<T, capacity, Allocator>::empty() const noexcept
{
    switch (state)
    {
    case State::First:
        return _size1 == 0;
    case State::Second:
        return _size2 == 0;
    case State::NotSelected:
        return _size1 + _size2 == 0;
    }
}

template<typename T, uint capacity, typename Allocator>
std::size_t DualStack<T, capacity, Allocator>::size() const noexcept
{
    switch (state)
    {
    case State::First:
        return _size1;        
    case State::Second:
        return _size2;        
    case State::NotSelected:
        return _size1 + _size2;
    }
}

template<typename T, uint capacity, typename Allocator>
T& DualStack<T, capacity, Allocator>::top()
{
    checkState();
    if(state == State::First)
        return _data[_size1 - 1];
    return _data[capacity - _size2];
}

template<typename T, uint capacity, typename Allocator>
void DualStack<T, capacity, Allocator>::push(const T& value)
{
    checkState();
    if(_size1 + _size2 == capacity)
        throw std::length_error("DualStack is full");

    if(state == State::First)
    {
         _data[_size1] = value;
         _size1++;
        return;
    }
    else
    {
        _data[capacity - _size2 - 1] = value;
        _size2++;
        return;
    }
}

template<typename T, uint capacity, typename Allocator>
void DualStack<T, capacity, Allocator>::push(T&& value)
{
    checkState();
    if(_size1 + _size2 == capacity)
        throw std::length_error("DualStack is full");

    if(state == State::First)
    {
         _data[_size1] = std::move(value);
         _size1++;
        return;
    }
    else
    {
        _data[capacity - _size2 - 1] = std::move(value);
        _size2++;
        return;
    }
}

template<typename T, uint capacity, typename Allocator>
void DualStack<T, capacity, Allocator>::pop()
{
    checkState();
    if(state == State::First)
    {
        if(_size1 == 0)
            throw std::length_error("First stack is empty");
         _size1--;
        return;
    }
    else
    {
        if(_size2 == 0)
            throw std::length_error("Second stack is empty");
         _size2--;
        return;
    }
}
