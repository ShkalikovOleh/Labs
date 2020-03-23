#include "LinkedList.h"

#pragma region LinkedList

template<typename T, typename Allocator>
LinkedList<T, Allocator>::LinkedList() : _size(0)
{
    _head = _allocator.allocate(1);
    new(_head) LinkedListNode<T>;
    _tail = _allocator.allocate(1);
    new(_tail) LinkedListNode<T>;

    _head->next = _tail;
    _tail->previous = _head;
}

template<typename T, typename Allocator>
LinkedList<T, Allocator>::LinkedList(std::initializer_list<T> values) : _size(0)
{
    _head = _allocator.allocate(1);
    new(_head) LinkedListNode<T>;
    _tail = _allocator.allocate(1);
    new(_tail) LinkedListNode<T>;

    _head->next = _tail;
    _tail->previous = _head;
    for (auto &&value : values)
    {
        push_back(value);
    } 
}

template<typename T, typename Allocator>
LinkedList<T, Allocator>::LinkedList(const LinkedList<T, Allocator>& other) : _size(0)
{
    _head = _allocator.allocate(1);
    new(_head) LinkedListNode<T>;
    _tail = _allocator.allocate(1);
    new(_tail) LinkedListNode<T>;

    _head->next = _tail;
    _tail->previous = _head;
    for (auto &&value : other)
    {
        push_back(value);
    }
    
}

template<typename T, typename Allocator>
LinkedList<T, Allocator>::~LinkedList()
{
    auto current = _head;
    LinkedListNode<T>* next;
    while(current)
    {
        next = current->next;
        _allocator.deallocate(current, 1);
        current = next;
    }
}

template<typename T, typename Allocator>
typename LinkedList<T, Allocator>::iterator LinkedList<T, Allocator>::begin() const noexcept
{
    return iterator(_head->next);
}

template<typename T, typename Allocator>
typename LinkedList<T, Allocator>::iterator LinkedList<T, Allocator>::end() const noexcept
{
    return iterator(_tail);
}

template<typename T, typename Allocator>
typename LinkedList<T, Allocator>::const_iterator LinkedList<T, Allocator>::cbegin() const noexcept
{
    return const_iterator(_head->next);
}

template<typename T, typename Allocator>
typename LinkedList<T, Allocator>::const_iterator LinkedList<T, Allocator>::cend() const noexcept
{
    return const_iterator(_tail);
}

template<typename T, typename Allocator>
const T& LinkedList<T, Allocator>::back() const
{
    if(_size == 0)
        throw std::length_error("Array is empty");
    return _tail->previous->data;
}

template<typename T, typename Allocator>
T& LinkedList<T, Allocator>::back()
{
    if(_size == 0)
        throw std::length_error("Array is empty");
    return _tail->previous->data;
}

template<typename T, typename Allocator>
const T& LinkedList<T, Allocator>::front() const
{
    if(_size == 0)
        throw std::length_error("Array is empty");
    return _head->next->data;
}

template<typename T, typename Allocator>
T& LinkedList<T, Allocator>::front()
{
    if(_size == 0)
        throw std::length_error("Array is empty");
    return _head->next->data;
}

template<typename T, typename Allocator>
size_t LinkedList<T, Allocator>::size() const noexcept
{
    return _size;
}

template<typename T, typename Allocator>
bool LinkedList<T, Allocator>::empty() const noexcept
{
    return _size == 0;
}

template<typename T, typename Allocator>
void LinkedList<T, Allocator>::push_front(const T& value)
{
    LinkedListNode<T>* node = _allocator.allocate(1);
    new(node) LinkedListNode<T>(value);

    node->previous = _head;
    _head->next->previous = node;
    node->next = _head->next;
    _head->next = node;

    _size++;
}

template<typename T, typename Allocator>
void LinkedList<T, Allocator>::push_front(T&& value)
{
    LinkedListNode<T>* node = _allocator.allocate(1);
    new(node) LinkedListNode<T>(std::move(value));

    node->previous = _head;
    _head->next->previous = node;
    node->next = _head->next;
    _head->next = node;

    _size++;
}

template<typename T, typename Allocator>
void LinkedList<T, Allocator>::push_back(const T& value)
{    
    LinkedListNode<T>* node = _allocator.allocate(1);
    new(node) LinkedListNode<T>(value);

    node->previous = _tail->previous;
    node->next = _tail;
    _tail->previous->next = node;
    _tail->previous = node;

    _size++;
}

template<typename T, typename Allocator>
void LinkedList<T, Allocator>::push_back(T&& value)
{
    LinkedListNode<T>* node = _allocator.allocate(1);
    new(node) LinkedListNode<T>(std::move(value));

    node->previous = _tail->previous;
    node->next = _tail;
    _tail->previous->next = node;
    _tail->previous = node;

    _size++;
}

template<typename T, typename Allocator>
void LinkedList<T, Allocator>::pop_back()
{
    if(empty())
        throw std::length_error("List is empty");
    remove(--cend());
}

template<typename T, typename Allocator>
void LinkedList<T, Allocator>::pop_front()
{
    if(empty())
        throw std::length_error("List is empty");
    remove(cbegin());
}

template<typename T, typename Allocator>
typename LinkedList<T, Allocator>::iterator LinkedList<T, Allocator>::insert(const_iterator position, const T& value)
{
    LinkedListNode<T>* node = _allocator.allocate(1);
    new(node) LinkedListNode<T>(value);

    node->previous = position.ptr;
    node->next = position.ptr->next;
    position.ptr->next->previous = node;
    position.ptr->next = node;

    _size++;
}

template<typename T, typename Allocator>
typename LinkedList<T, Allocator>::iterator LinkedList<T, Allocator>::insert(const_iterator position, T&& value)
{
    LinkedListNode<T>* node = _allocator.allocate(1);
    new(node) LinkedListNode<T>(std::move(value));

    node->previous = position.ptr;
    node->next = position.ptr->next;
    position.ptr->next->previous = node;
    position.ptr->next = node;

    _size++;
}

template<typename T, typename Allocator>
void LinkedList<T, Allocator>::remove(const T& value)
{
    for(auto it = cbegin(); it != cend(); it++)
    {
        if(*it == value)
        {
            remove(it);          
        }
    }
}

template<typename T, typename Allocator>
void LinkedList<T, Allocator>::remove(const_iterator position)
{
    position.ptr->previous->next = position.ptr->next;
    position.ptr->next->previous = position.ptr->previous;
    _allocator.deallocate(position.ptr, 1);
    _size--;
}

template<typename T, typename Allocator>
void LinkedList<T, Allocator>::remove(const_iterator first, const_iterator last)
{
    first.ptr->previous->next = last.ptr->next;
    last.ptr->next->previous = first.ptr->previous;
    for(auto it = first; it != last + 1; )
    {        
        _allocator.deallocate((it++).ptr, 1);
        _size--;
    }    
}

template<typename T, typename Allocator>
void LinkedList<T, Allocator>::clear()
{
    _head->next = _tail;
    _tail->previous = _head;
    for(auto it = cbegin(); it != cend();)
    {
        it++;
        _allocator.deallocate(it.ptr->previous, 1);
    }
    _size = 0;
}

#pragma endregion

#pragma region Iterator

template<typename T>
list_iterator<T>::list_iterator(LinkedListNode<list_iterator<T>::real_type>* node)
{
    ptr = node;
}

template<typename T>
list_iterator<T>::list_iterator(const list_iterator& other)
{
    ptr = other.ptr;
}

template<typename T>
typename list_iterator<T>::value_type& list_iterator<T>::operator*()
{
    return ptr->data;
}

template<typename T>
typename list_iterator<T>::value_type* list_iterator<T>::operator->()
{
    return &ptr->data;
}

template<typename T>
list_iterator<T>& list_iterator<T>::operator++()
{
    ptr = ptr->next;
    return *this;
}

template<typename T>
list_iterator<T> list_iterator<T>::operator++(int)
{    
    auto res = ptr;
    ptr = ptr->next;
    return list_iterator(res);
}

template<typename T>
list_iterator<T>& list_iterator<T>::operator--()
{
    ptr = ptr->previous;
    return *this;
}

template<typename T>
list_iterator<T> list_iterator<T>::operator--(int)
{    
    auto res = ptr;
    ptr = ptr->previous;
    return list_iterator(res);
}

template<typename T>
list_iterator<T> list_iterator<T>::operator+(list_iterator<T>::difference_type delta)
{    
    auto temp = this->ptr;
    for(int i = 0; i < delta; i++)
        temp = temp->next;
    return list_iterator(temp);
}

template<typename T>
list_iterator<T> list_iterator<T>::operator-(list_iterator<T>::difference_type delta)
{    
    auto temp = this->ptr;
    for(int i = 0; i < delta; i++)
        temp = temp->previous;
    return list_iterator(temp);
}

template<typename T>
inline bool list_iterator<T>::operator==(const list_iterator<T>& other)
{    
    return ptr == other.ptr;
}

template<typename T>
inline bool list_iterator<T>::operator!=(const list_iterator<T>& other)
{    
    return !operator==(other);
}

#pragma endregion