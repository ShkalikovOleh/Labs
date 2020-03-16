#ifndef ARRAY_H
    #define ARRAY_H

#include <iterator>

template <typename ValueType>
class array_iterator;

//Dynamic array
template<typename T, typename Allocator = std::allocator<T> >
class Array
{
    using iterator = array_iterator<T>;
    using const_iterator = array_iterator<const T>;

protected:
    size_t capacity;
    size_t size;
    T* data;
    Allocator allocator;

    void resize(size_t);
    void increase();
    void decrease();

public:
    Array(size_t capacity = 10);    
    Array(std::initializer_list<T>);
    Array(const Array<T, Allocator>&);
    ~Array();

    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;
    bool empty() const noexcept;

    void shrinkToFit() noexcept;

    iterator begin() const noexcept;
    iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    void push(const T&);
    void push(T&&);

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