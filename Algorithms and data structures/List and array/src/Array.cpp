#include "Array.h"

#pragma region Array

template<typename T, typename Allocator>
Array<T, Allocator>::Array(size_t capacity) : size(0), capacity(capacity)
{   
    data = allocator.allocate(capacity);    
}

template<typename T, typename Allocator>
Array<T, Allocator>::Array(std::initializer_list<T> list): size(0)
{
    capacity = list.size();    
    data = allocator.allocate(capacity);
    for(auto& v : list)
    {
        push(v);
    }
}

template<typename T, typename Allocator>
Array<T, Allocator>::Array(const Array<T, Allocator>& other)
{
    size = other.size;
    capacity = other.size;
    data = allocator.allocate(capacity);
    std::copy(other.data, other.data + size, data);
}

template<typename T, typename Allocator>
Array<T, Allocator>::~Array()
{
    allocator.deallocate(data, capacity);
}

template<typename T, typename Allocator>
inline size_t Array<T, Allocator>::getSize() const noexcept
{
    return size;
}

template<typename T, typename Allocator>
inline size_t Array<T, Allocator>::getCapacity() const noexcept
{
    return capacity;
}

template<typename T, typename Allocator>
inline bool Array<T, Allocator>::empty() const noexcept
{
    return size == 0;
}

template<typename T, typename Allocator>
void Array<T, Allocator>::shrinkToFit() noexcept
{
    resize(size);
}

template<typename T, typename Allocator>
void Array<T, Allocator>::resize(size_t newSize)
{
    if(size > newSize)
        throw std::exception();

    capacity = newSize;

    T* newData = allocator.allocate(newSize);
    std::copy(data, data+size, newData);
    data = newData;
}

template<typename T, typename Allocator>
inline void Array<T, Allocator>::increase()
{
    resize(2 * capacity);
}

template<typename T, typename Allocator>
inline void Array<T, Allocator>::decrease()
{
    resize(capacity / 2);
}

template<typename T, typename Allocator>
inline typename Array<T, Allocator>::iterator Array<T, Allocator>::begin() const noexcept
{
    return iterator(data);
}

template<typename T, typename Allocator>
inline typename Array<T, Allocator>::iterator Array<T, Allocator>::end() const noexcept
{
    return iterator(data + size);
}

template<typename T, typename Allocator>
inline typename Array<T, Allocator>::const_iterator Array<T, Allocator>::cbegin() const noexcept
{
    return const_iterator(data);
}

template<typename T, typename Allocator>
typename Array<T, Allocator>::const_iterator Array<T, Allocator>::cend() const noexcept
{
    return const_iterator(data + size);
}

template<typename T, typename Allocator>
void Array<T, Allocator>::push(const T& value)
{
    if(size >= capacity)
        increase();
    
    data[size] = value;
    size++;
}

template<typename T, typename Allocator>
void Array<T, Allocator>::push(T&& value)
{
    if(size >= capacity)
        increase();
    
    data[size] = std::move(value);
    size++;
}

template<typename T, typename Allocator>
void Array<T, Allocator>::remove(const T& value)
{    
    for(auto it = cbegin(); it != cend(); it++)
    {
        if(*it == value)
        {        
            remove(it);    
            it--;
        }            
    }
}

template<typename T, typename Allocator>
void Array<T, Allocator>::remove(const_iterator position)
{   
    if(position >= cend() || position < cbegin())
        throw std::out_of_range("Iterators out of container"); 

    for(auto it = position + 1; it != cend(); it++, position++)
    {
        *(position.ptr) = *(it.ptr);
    }
    size--;

    if(size <= capacity / 3)
        decrease();
}

template<typename T, typename Allocator>
void Array<T, Allocator>::remove(const_iterator first, const_iterator last)
{
    if(first >= cend() || first < cbegin() || last >= cend() || first < cbegin())
        throw std::out_of_range("Iterators out of container");
    if(first > last)
        throw std::invalid_argument("First > last");

    auto current = first;
    for(auto it = last + 1; it != cend(); it++, current++)
    {
        *(current.ptr) = *(it.ptr);
    }
    size -= (last - first + 1);  //for last - first > newSize

    if(size <= capacity / 3)
        decrease();
}

template<typename T, typename Allocator>
typename Array<T, Allocator>::iterator Array<T, Allocator>::insert(const_iterator position, const T& value)
{
    if(position >= cend() || position < cbegin())
        throw std::out_of_range("Iterators out of container");

    if(size >= capacity)
        increase();
    size++;

    for(auto it = cend() - 2; it != position ; it--) //cend() - 2 is last item
    {        
        *(it + 1).ptr = *it;
    }        
    
    auto dest = (position + 1).ptr;
    *dest = value;

    return iterator(dest);
}

template<typename T, typename Allocator>
typename Array<T, Allocator>::iterator Array<T, Allocator>::insert(const_iterator position, T&& value)
{
    if(position >= cend() || position < cbegin())
        throw std::out_of_range("Iterators out of container");

    if(size >= capacity)
        increase();
    size++;

    for(auto it = cend() - 2; it != position ; it--) //cend() - 2 is last item
    {        
        *(it + 1).ptr = *it;
    }        

    auto dest = (position + 1).ptr;
    *dest = std::move(value);

    return iterator(dest);
}

template<typename T, typename Allocator>
inline void Array<T,Allocator>::clear() noexcept
{
    size = 0;    
}

template<typename T, typename Allocator>
T& Array<T, Allocator>::operator[](int index)
{
    if(index >= size || index < 0)
        throw std::out_of_range("Iterators out of container");

    return data[index];
}

template<typename T, typename Allocator>
const T& Array<T, Allocator>::operator[](int index) const
{
    if(index >= size || index < 0)
        throw std::out_of_range("Iterators out of container");

    return data[index];
}

#pragma endregion

#pragma region Iterator

template<typename T>
array_iterator<T>::array_iterator(array_iterator<T>::real_type* pointer)
{
    if(pointer != nullptr)
        ptr = pointer;
    else
        throw std::exception();
}

template<typename T>
array_iterator<T>::array_iterator(const array_iterator& other)
{
    ptr = other.ptr;    
}

template<typename T>
inline typename array_iterator<T>::reference array_iterator<T>::operator*()
{
    return *ptr;
}

template<typename T>
inline typename array_iterator<T>::pointer array_iterator<T>::operator->()
{
    return ptr;
}

template<typename T>
array_iterator<T>& array_iterator<T>::operator++()
{
    ptr++;
    return *this;
}

template<typename T>
array_iterator<T> array_iterator<T>::operator++(int)
{
    array_iterator res = *this;
    ptr++;
    return res;
}

template<typename T>
array_iterator<T>& array_iterator<T>::operator--()
{
    ptr--;
    return *this;
}

template<typename T>
array_iterator<T> array_iterator<T>::operator--(int)
{
    array_iterator res = *this;
    ptr--;
    return res;
}

template<typename T>
array_iterator<T> array_iterator<T>::operator+(array_iterator<T>::difference_type n)
{
    return array_iterator(ptr + n);
}

template<typename T>
array_iterator<T> array_iterator<T>::operator-(array_iterator<T>::difference_type n)
{
    return array_iterator(ptr - n);
}

template<typename T>
array_iterator<T>& array_iterator<T>::operator+=(array_iterator<T>::difference_type n)
{
    ptr+=n;
    return *this;
}

template<typename T>
array_iterator<T>& array_iterator<T>::operator-=(array_iterator<T>::difference_type n)
{
    ptr-=n;
    return *this;
}

template<typename T>
array_iterator<T> array_iterator<T>::operator[](array_iterator<T>::difference_type n)
{
    return array_iterator(ptr + n);
}

template<typename T>
inline typename array_iterator<T>::difference_type array_iterator<T>::operator-(const array_iterator<T>& other)
{    
    return ptr - other.ptr;
}

template<typename T>
inline bool array_iterator<T>::operator==(const array_iterator& other)
{
    return ptr == other.ptr;
}

template<typename T>
inline bool array_iterator<T>::operator!=(const array_iterator& other)
{
    return !operator==(other);
}

template<typename T>
inline bool array_iterator<T>::operator<(const array_iterator& other)
{
    return ptr < other.ptr; //how if custom allocator is used?
}

template<typename T>
inline bool array_iterator<T>::operator<=(const array_iterator& other)
{
    return operator<(other) || operator==(other);
}

template<typename T>
inline bool array_iterator<T>::operator>(const array_iterator& other)
{
    return !operator<=(other);
}

template<typename T>
inline bool array_iterator<T>::operator>=(const array_iterator& other)
{
    return !operator<(other);
}

#pragma endregion