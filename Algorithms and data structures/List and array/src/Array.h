#ifndef ARRAY_H
    #define ARRAY_H

#include <iterator>

template <typename ValueType>
class base_iterator;

//Dynamic array
template<typename T>
class Array
{
private:
    
    using iterator = base_iterator<T>;
    using const_iterator = base_iterator<const T>;

    size_t capacity;
    size_t size;
    T* data;

    void resize(size_t);
    void increase();
    void decrease();

public:
    Array(size_t capacity = 10);    
    Array(std::initializer_list<T>);
    Array(const Array<T>&);
    ~Array();

    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;
    bool empty() const noexcept;

    iterator begin() const noexcept;
    iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    void push(const T&);
    void push(T&&);

    void remove(const_iterator);
    void remove(const_iterator, const_iterator);

    iterator insert(const_iterator, const T&);
    iterator insert(const_iterator, T&&);

    void clear() noexcept;   

    T& operator[](int);
    const T& operator[](int) const;
};

template <class T>
class base_iterator
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

    base_iterator(real_type*);
    base_iterator(const base_iterator&);

    value_type& operator*();
    value_type* operator->();
    base_iterator operator++();
    base_iterator operator++(int);
    base_iterator operator--();
    base_iterator operator--(int);

    base_iterator operator+(difference_type);
    base_iterator operator-(difference_type);
    base_iterator& operator+=(difference_type);
    base_iterator& operator-=(difference_type);

    base_iterator operator[](difference_type);

    difference_type operator-(const base_iterator&);

    bool operator==(const base_iterator&);
    bool operator!=(const base_iterator&);
    bool operator<(const base_iterator&);
    bool operator<=(const base_iterator&);
    bool operator>(const base_iterator&);
    bool operator>=(const base_iterator&);

private:
    real_type* ptr;
};

#include "Array.cpp"

#endif