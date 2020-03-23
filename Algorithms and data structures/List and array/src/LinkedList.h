#ifndef LINKED_LIST_H
    #define LINKED_LIST_H

#include <iterator>

template<typename T>
struct LinkedListNode
{
    LinkedListNode() : previous(nullptr), next(nullptr){  };
    LinkedListNode(const T& data) : previous(nullptr), next(nullptr), data(data){  };

    LinkedListNode<T>* previous;
    T data;
    LinkedListNode<T>* next;
};


template<typename T>
class list_iterator;


template <typename T, typename Allocator = std::allocator<LinkedListNode<T>> >
class LinkedList
{
protected:
    LinkedListNode<T>* _head;
    LinkedListNode<T>* _tail;
    size_t _size;
    Allocator _allocator;

public:
    using iterator = list_iterator<T>;
    using const_iterator = list_iterator<const T>;

    using value_type = T;
    using allocator_type = Allocator;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = T*;
    using const_pointer = const T*;

    LinkedList();
    LinkedList(std::initializer_list<T>);
    LinkedList(const LinkedList<T, Allocator>&);
    ~LinkedList();

    iterator begin() const noexcept;
    iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    const T& back() const;
    T& back();
    const T& front() const;
    T& front();

    size_t size() const noexcept;
    bool empty() const noexcept;

    void push_front(const T&);
    void push_front(T&&);
    void push_back(const T&);
    void push_back(T&&);

    void pop_back();
    void pop_front();

    iterator insert(const_iterator, const T&);
    iterator insert(const_iterator, T&&);

    void remove(const T&);    
    void remove(const_iterator);
    void remove(const_iterator, const_iterator);

    void clear();
};


template <typename T>
class list_iterator
{
public:

    using real_type = typename std::remove_const<T>::type;
    friend class LinkedList<real_type>;

    //for stl methods
    using value_type = T;
    using reference = T&;
    using iterator_category = std::bidirectional_iterator_tag;
    using pointer = T*;
    using difference_type = int;

    list_iterator(LinkedListNode<real_type>*);
    list_iterator(const list_iterator&);

    value_type& operator*();
    value_type* operator->();
    list_iterator& operator++();
    list_iterator operator++(int);
    list_iterator& operator--();
    list_iterator operator--(int);

    list_iterator operator+(difference_type);
    list_iterator operator-(difference_type);

    bool operator==(const list_iterator&);
    bool operator!=(const list_iterator&);

private:
    LinkedListNode<real_type>* ptr;
};

#include "LinkedList.cpp"

#endif