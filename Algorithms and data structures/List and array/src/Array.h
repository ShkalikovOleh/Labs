#ifndef ARRAY_H
    #define ARRAY_H

#include <iterator>

template <typename ValueType>
class array_iterator;

//Dynamic array
template<typename T, typename Allocator = std::allocator<T> >
class Array
{
protected:
    size_t _capacity;
    size_t _size;
    T* _data;
    Allocator _allocator;

    void resize(size_t);
    void increase();
    void decrease();

public:
    using iterator = array_iterator<T>;
    using const_iterator = array_iterator<const T>;
    
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = T*;
    using const_pointer = const T*;

    Array(size_t capacity = 10);    
    Array(std::initializer_list<T>);
    Array(const Array<T, Allocator>&);
    ~Array();

    size_t size() const noexcept;
    size_t capacity() const noexcept;
    bool empty() const noexcept;

    void shrinkToFit() noexcept;

    iterator begin() const noexcept;
    iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    const T& front() const;
    T& front();    
    const T& back() const;
    T& back();

    void push_back(const T&);
    void push_back(T&&);
    void push_front(const T&);
    void push_front(T&&);

    void pop_back();
    void pop_front();

    void remove(const T&);
    void remove(const_iterator);
    void remove(const_iterator, const_iterator);

    iterator insert(const_iterator, const T&);
    iterator insert(const_iterator, T&&);

    void clear() noexcept;   

    T& operator[](int);
    const T& operator[](int) const;
};

template <class T>
class array_iterator
{
public:

    using real_type = typename std::remove_const<T>::type;
    friend class Array<real_type>;

    //for stl methods
    using value_type = T;
    using reference = T&;
    using iterator_category = std::random_access_iterator_tag; 
    using pointer = T*;
    using difference_type = int;

    array_iterator(real_type*);
    array_iterator(const array_iterator&);

    value_type& operator*();
    value_type* operator->();
    array_iterator& operator++();
    array_iterator operator++(int);
    array_iterator& operator--();
    array_iterator operator--(int);

    array_iterator operator+(difference_type);
    array_iterator operator-(difference_type);
    array_iterator& operator+=(difference_type);
    array_iterator& operator-=(difference_type);

    array_iterator operator[](difference_type);

    difference_type operator-(const array_iterator&);

    bool operator==(const array_iterator&);
    bool operator!=(const array_iterator&);
    bool operator<(const array_iterator&);
    bool operator<=(const array_iterator&);
    bool operator>(const array_iterator&);
    bool operator>=(const array_iterator&);

private:
    real_type* ptr;
};

#include "Array.cpp"

#endif