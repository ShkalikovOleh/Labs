#include "CircularQueue.h"
#include <array>


template<typename T, int capacity, typename Allocator>
CircularQueue<T, capacity, Allocator>::CircularQueue() : _size(0), _head(0), _tail(-1)
{
    _data = _allocator.allocate(capacity);
}

template<typename T, int capacity, typename Allocator>
CircularQueue<T, capacity, Allocator>::CircularQueue(T* data, int size)
{
    _data = _allocator.allocate(capacity);
    std::copy(data, data + size, _data);
    _tail = _size - 1;
    _head = 0;
    _size = size;
}

template<typename T, int capacity, typename Allocator>
CircularQueue<T, capacity, Allocator>::CircularQueue(std::array<T, capacity> data)
{
    _data = _allocator.allocate(capacity);
    std::copy(data.cbegin(), data.cend(), _data);
    _tail = data.size - 1;
    _head = 0;
    _size = data.size;
}

template<typename T, int capacity, typename Allocator>
CircularQueue<T, capacity, Allocator>::CircularQueue(const CircularQueue& other)
{
    _data = _allocator.allocate(capacity);
    for(int i = 0; i < other._size; i++)
    {
        _data[i] = other._data[(other._head + i) % capacity];
    }
    _head = 0;
    _tail = other._size - 1;
    _size = other._size;
}

template<typename T, int capacity, typename Allocator>
CircularQueue<T, capacity, Allocator>::CircularQueue(std::initializer_list<T> values) : _size(0), _head(0), _tail(-1)
{
    _data = _allocator.allocate(capacity);
    if(values.size() > capacity)
        throw std::length_error("CircularQueue capacity less than init values");
    for (auto &&value : values)
    {
        push(value);
    }
}

template<typename T, int capacity, typename Allocator>
CircularQueue<T, capacity, Allocator>::~CircularQueue()
{
    _allocator.deallocate(_data, capacity);
}

template<typename T, int capacity, typename Allocator>
size_t CircularQueue<T, capacity, Allocator>::size() const noexcept
{
    return _size;
}

template<typename T, int capacity, typename Allocator>
bool CircularQueue<T, capacity, Allocator>::empty() const noexcept
{
    return _size == 0;
}

template<typename T, int capacity, typename Allocator>
T& CircularQueue<T, capacity, Allocator>::front()
{
    if(empty())
        throw std::length_error("CircularQueue is empty");
    return _data[_head];
}

template<typename T, int capacity, typename Allocator>
const T& CircularQueue<T, capacity, Allocator>::front() const
{
    if(empty())
        throw std::length_error("CircularQueue is empty");
    return _data[_head];
}

template<typename T, int capacity, typename Allocator>
T& CircularQueue<T, capacity, Allocator>::back()
{
    if(empty())
        throw std::length_error("CircularQueue is empty");
    return _data[_tail];
}

template<typename T, int capacity, typename Allocator>
const T& CircularQueue<T, capacity, Allocator>::back() const
{
    if(empty())
        throw std::length_error("CircularQueue is empty");
    return _data[_tail];
}

template<typename T, int capacity, typename Allocator>
void CircularQueue<T, capacity, Allocator>::push(T&& value)
{
    if(_size == capacity)
        throw std::length_error("CircularQueue is full");
    
    _tail = (_tail + 1) % capacity;
    _data[_tail] = std::move(value);
    _size++;
};

template<typename T, int capacity, typename Allocator>
void CircularQueue<T, capacity, Allocator>::push(const T& value)
{
    if(_size == capacity)
        throw std::length_error("CircularQueue is full");
    
    _tail = (_tail + 1) % capacity;
    _data[_tail] = value;
    _size++;
};

template<typename T, int capacity, typename Allocator>
void CircularQueue<T, capacity, Allocator>::pop()
{
    if(empty())
        throw std::length_error("CircularQueue is empty");

    _head = (_head + 1) % capacity;
    _size--;
};


