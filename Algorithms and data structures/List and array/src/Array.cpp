#include "Array.h"

#pragma region Array

template<class T>
Array<T>::Array(size_t capacity) : size(0), capacity(capacity)
{    
    data = reinterpret_cast<T*>(new char[capacity * sizeof(T)]);
}

template<class T>
Array<T>::Array(std::initializer_list<T> list): size(0)
{
    capacity = list.size();
    data = reinterpret_cast<T*>(new char[capacity * sizeof(T)]);
    for(auto& v : list)
    {
        push(v);
    }
}

template<class T>
Array<T>::Array(const Array<T>& other)
{
    size = other.size;
    capacity = other.size;
    data = reinterpret_cast<T*>(new char[capacity * sizeof(T)]);
    std::copy(other.data, other.data + size, data);
}

template<class T>
Array<T>::~Array()
{
    delete[] data;
}

template<class T>
inline size_t Array<T>::getSize() const noexcept
{
    return size;
}

template<class T>
inline size_t Array<T>::getCapacity() const noexcept
{
    return capacity;
}

template<class T>
inline bool Array<T>::empty() const noexcept
{
    return size == 0;
}

template<class T>
void Array<T>::resize(size_t newSize)
{
    if(size > newSize)
        throw std::exception();

    capacity = newSize;

    T* newData = reinterpret_cast<T*>(new char[newSize * sizeof(T)]);
    std::copy(data, data+size, newData);
}

template<class T>
inline void Array<T>::increase()
{
    resize(2 * capacity);
}

template<class T>
inline void Array<T>::decrease()
{
    resize(capacity / 2);
}

template<class T>
inline typename Array<T>::iterator Array<T>::begin() const noexcept
{
    return iterator(data);
}

template<class T>
inline typename Array<T>::iterator Array<T>::end() const noexcept
{
    return iterator(data + size);
}

template<class T>
inline typename Array<T>::const_iterator Array<T>::cbegin() const noexcept
{
    return const_iterator(data);
}

template<class T>
typename Array<T>::const_iterator Array<T>::cend() const noexcept
{
    return const_iterator(data + size);
}

template<class T>
void Array<T>::push(const T& value)
{
    if(size >= capacity)
        increase();
    
    data[size] = value;
    size++;
}

template<class T>
void Array<T>::push(T&& value)
{
    if(size >= capacity)
        increase();
    
    data[size] = std::move(value);
    size++;
}

template<class T>
void Array<T>::remove(const_iterator position)
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

template<class T>
void Array<T>::remove(const_iterator first, const_iterator last)
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

template<class T>
typename Array<T>::iterator Array<T>::insert(const_iterator position, const T& value)
{
    if(position >= cend() || position < cbegin())
        throw std::out_of_range("Iterators out of container");

    if(size >= capacity)
        increase();
    size++;

    for(auto it = cend() - 2; it != position ; it--)
    {        
        *(it + 1).ptr = *it;
    }        
    
    auto dest = (position + 1).ptr;
    *dest = value;

    return iterator(dest);
}

template<class T>
typename Array<T>::iterator Array<T>::insert(const_iterator position, T&& value)
{
    if(position >= cend() || position < cbegin())
        throw std::out_of_range("Iterators out of container");

    if(size >= capacity)
        increase();
    size++;

    for(auto it = cend() - 2; it != position ; it--)
    {        
        *(it + 1).ptr = *it;
    }        

    auto dest = (position + 1).ptr;
    *dest = std::move(value);

    return iterator(dest);
}

template<class T>
inline void Array<T>::clear() noexcept
{
    size = 0;    
}

template<class T>
T& Array<T>::operator[](int index)
{
    if(index >= size || index < 0)
        throw std::out_of_range("Iterators out of container");

    return data[index];
}

template<class T>
const T& Array<T>::operator[](int index) const
{
    if(index >= size || index < 0)
        throw std::out_of_range("Iterators out of container");

    return data[index];
}

#pragma endregion

#pragma region Iterator

template<class T>
base_iterator<T>::base_iterator(base_iterator<T>::real_type* pointer)
{
    if(pointer != nullptr)
        ptr = pointer;
    else
        throw std::exception();
}

template<class T>
base_iterator<T>::base_iterator(const base_iterator& other)
{
    ptr = other.ptr;    
}

template<class T>
inline typename base_iterator<T>::reference base_iterator<T>::operator*()
{
    return *ptr;
}

template<class T>
inline typename base_iterator<T>::pointer base_iterator<T>::operator->()
{
    return ptr;
}

template<class T>
base_iterator<T> base_iterator<T>::operator++()
{
    ptr++;
    return *this;
}

template<class T>
base_iterator<T> base_iterator<T>::operator++(int)
{
    base_iterator res = *this;
    ptr++;
    return res;
}

template<class T>
base_iterator<T> base_iterator<T>::operator--()
{
    ptr--;
    return *this;
}

template<class T>
base_iterator<T> base_iterator<T>::operator--(int)
{
    base_iterator res = *this;
    ptr--;
    return res;
}

template<class T>
base_iterator<T> base_iterator<T>::operator+(base_iterator<T>::difference_type n)
{
    return base_iterator(ptr + n);
}

template<class T>
base_iterator<T> base_iterator<T>::operator-(base_iterator<T>::difference_type n)
{
    return base_iterator(ptr - n);
}

template<class T>
base_iterator<T>& base_iterator<T>::operator+=(base_iterator<T>::difference_type n)
{
    ptr+=n;
    return *this;
}

template<class T>
base_iterator<T>& base_iterator<T>::operator-=(base_iterator<T>::difference_type n)
{
    ptr-=n;
    return *this;
}

template<class T>
base_iterator<T> base_iterator<T>::operator[](base_iterator<T>::difference_type n)
{
    return base_iterator(ptr + n);
}

template<class T>
inline typename base_iterator<T>::difference_type base_iterator<T>::operator-(const base_iterator<T>& other)
{    
    return ptr - other.ptr;
}

template<class T>
inline bool base_iterator<T>::operator==(const base_iterator& other)
{
    return ptr == other.ptr;
}

template<class T>
inline bool base_iterator<T>::operator!=(const base_iterator& other)
{
    return !operator==(other);
}

template<class T>
inline bool base_iterator<T>::operator<(const base_iterator& other)
{
    return ptr < other.ptr; //how if custom allocator is used?
}

template<class T>
inline bool base_iterator<T>::operator<=(const base_iterator& other)
{
    return operator<(other) || operator==(other);
}

template<class T>
inline bool base_iterator<T>::operator>(const base_iterator& other)
{
    return !operator<=(other);
}

template<class T>
inline bool base_iterator<T>::operator>=(const base_iterator& other)
{
    return !operator<(other);
}

#pragma endregion