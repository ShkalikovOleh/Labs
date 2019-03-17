#ifndef ARRAY_H
#define ARRAY_H

#include <ostream>

template<class T>
class IContainer
{
  public:
    virtual size_t GetSize() const = 0;
    virtual void Clear() = 0;
    virtual const T& operator[](unsigned long) = 0;
};

template<class T>
class IAddable: public IContainer<T>
{
  public:
    virtual IAddable<T>& operator+(IAddable&) = 0;
};

template<class T>
class IProductable: public IContainer<T>
{
  public:
    virtual IProductable<T>& operator*(IProductable&) = 0;
};

template <class T>
class Array: public IAddable<T>, public IProductable<T>
{
  public:
    //ctors
    Array();
    Array(size_t);
    Array(const Array&);
    ~Array();

    //functionality
    size_t GetSize() const;    
    void Add(T&);
    void Remove(unsigned long);
    unsigned int Find(T&) const;
    void Clear();
    
    const T& operator[](unsigned long);
    IAddable<T>& operator+(IAddable<T>&);
    IProductable<T>& operator*(IProductable<T>&);

    friend std::ostream& operator<<(std::ostream&, const Array<T>&);
    friend std::istream& operator>>(std::istream&, Array<T>&);

  protected:
    T* data;
    size_t capacity;
    size_t size;
    void scale();
    void unscale();
};

class OverflowOffsetExeception{};
class DifferentSizeException{};

#include "Array.cpp"

#endif