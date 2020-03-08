#include "LinkedList.h"

#pragma region LinkedList

template<typename T>
LinkedList<T>::LinkedList()
{
    head = new LinkedListNode<T>();
    tail = new LinkedListNode<T>();
    head->next = tail;
    tail->previous = head;
}

template<typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> values)
{
    head = new LinkedListNode<T>();
    tail = new LinkedListNode<T>();
    head->next = tail;
    tail->previous = head;
    for (auto &value : values)
    {
        push_back(value);
    } 
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    head = new LinkedListNode<T>();
    tail = new LinkedListNode<T>();
    head->next = tail;
    tail->previous = head;
    for (auto &value : other)
    {
        push_back(value);
    }
    
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    auto current = head;
    LinkedListNode<T>* next;
    while(current)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin() const noexcept
{
    return iterator(head->next);
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::end() const noexcept
{
    return iterator(tail);
}

template<typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::cbegin() const noexcept
{
    return const_iterator(head->next);
}

template<typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::cend() const noexcept
{
    return const_iterator(tail);
}

template<typename T>
size_t LinkedList<T>::getSize() const noexcept
{
    return size;
}

template<typename T>
bool LinkedList<T>::empty() const noexcept
{
    return size == 0;
}

template<typename T>
void LinkedList<T>::push_front(const T& value)
{
    auto node = new LinkedListNode(value);
    node->previous = head;
    head->next->previous = node;
    node->next = head->next;
    size++;
}

template<typename T>
void LinkedList<T>::push_front(T&& value)
{
    auto node = new LinkedListNode(std::move(value));
    node->previous = head;
    head->next->previous = node;
    node->next = head->next;
    size++;
}

template<typename T>
void LinkedList<T>::push_back(const T& value)
{
    auto node = new LinkedListNode(value);
    node->previous = tail->previous;
    tail->previous->next = node;
    tail->previous = node;
    size++;
}

template<typename T>
void LinkedList<T>::push_back(T&& value)
{
    auto node = new LinkedListNode(std::move(value));
    node->previous = tail->previous;
    tail->previous->next = node;
    tail->previous = node;
    size++;
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator position, const T& value)
{
    auto node = new LinkedListNode(value);
    node->previous = position.ptr;
    node->next = position.ptr->next;
    position.ptr->next = node;
    position.ptr->next->previous = node;
    size++;
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator position, T&& value)
{
    auto node = new LinkedListNode(std::move(value));
    node->previous = position.ptr;
    node->next = position.ptr->next;
    position.ptr->next = node;
    position.ptr->next->previous = node;
    size++;
}

template<typename T>
void LinkedList<T>::remove(const T& value)
{
    for(auto it = cbegin(); it != cend(); it++)
    {
        if(*it == value)
        {
            remove(it);            
        }
    }
}

template<typename T>
void LinkedList<T>::remove(const_iterator position)
{
    position.ptr->previous->next = position.ptr->next;
    position.ptr->next->previous = position.ptr->previous;
    delete position.ptr;
    size--;
}

template<typename T>
void LinkedList<T>::remove(const_iterator first, const_iterator last)
{
    first.ptr->previous->next = last.ptr->next;
    last.ptr->next->previous = first.ptr->previous;
    for(auto it = first; it != last++; it++)
    {
        delete it.ptr;
        size--;
    }    
}

template<typename T>
void LinkedList<T>::clear()
{
    head->next = tail;
    tail->previous = head;
    for(auto it = cbegin(); it != cend(); it++)
    {
        delete it.ptr;
    }
    size = 0;
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
    return list_iterator(ptr->next);
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
    return list_iterator(ptr->previous);
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