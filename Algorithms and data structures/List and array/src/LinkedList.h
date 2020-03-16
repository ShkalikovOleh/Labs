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


template <typename T>
class LinkedList
{
    using iterator = list_iterator<T>;
    using const_iterator = list_iterator<const T>;

private:
    LinkedListNode<T>* head;
    LinkedListNode<T>* tail;
    size_t size;
public:
    LinkedList();
    LinkedList(std::initializer_list<T>);
    LinkedList(const LinkedList<T>&);
    ~LinkedList();

    iterator begin() const noexcept;
    iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    size_t getSize() const noexcept;
    bool empty() const noexcept;

    void push_front(const T&);
    void push_front(T&&);
    void push_back(const T&);
    void push_back(T&&);

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