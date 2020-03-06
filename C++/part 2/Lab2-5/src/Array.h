#ifndef ARRAY_H
#define ARRAY_H

#include <ostream>

template<class T>
class IContainer
{
  public:
    virtual size_t GetSize() const = 0;
    virtual void Clear() = 0;
    virtual void operator=(IContainer&) = 0;
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
class Array;

template<class T>
class Iterator
{
  public:
     Iterator(T*);
     Iterator<T>& operator++();
     Iterator<T> operator++(int);
     Iterator<T>& operator--();
     Iterator<T> operator--(int);
     bool operator==(const Iterator<T>&);
     bool operator!=(const Iterator<T>&);
     T* operator->(){return data;}
     T& operator*(){return *data;}
  private:
    friend class Array<T>;
    T* data;
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

    Iterator<T> begin() const;
    Iterator<T> end() const;

    //functionality
    size_t GetSize() const;    
    void Add(T&);
    void Remove(Iterator<T>);
    virtual void Update(Iterator<T>, T&);
    Iterator<T> Find(T&) const;
    void Clear();
    
    const T& operator[](unsigned long);
    void operator=(IContainer<T>&);
    IAddable<T>& operator+(IAddable<T>&);
    IProductable<T>& operator*(IProductable<T>&);
    
    template<class U> friend std::ostream& operator<<(std::ostream&, const Array<U>&);    
    template<class U> friend std::istream& operator>>(std::istream&, Array<U>&);

  protected:
    T* data;
    size_t capacity;
    size_t size;
    void scale();
    void unscale();
};

class OverflowSizeExeception{};
class DifferentSizeException{};

#include "Array.cpp"

#endif