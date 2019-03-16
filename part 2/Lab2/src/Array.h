#ifndef ARRAY_H
#define ARRAY_H

#include <ostream>

template<class T>
class IContainer
{
  public:
    virtual size_t GetSize() const = 0;
    virtual void Clear() = 0;
    virtual const T& operator[](size_t) = 0;
  protected:
    size_t size;
};

template<class T>
class IAddable
{
  public:
    virtual T& operator+(const IAddable&) = 0;
};

template<class T>
class IProductable
{
  public:
    virtual T& operator*(const IProductable&) = 0;
};

template <class T = int>
class Array: //public IContainer<T>, public IAddable<T>, public IProductable<T>
{
  public:
    //ctors
    Array();
    Array(size_t);
    Array(const Array &);
    ~Array();

//iterators
#pragma region Iterator

    class Iterator
    {
      template<class T>
      friend class Array<T>;

      public:
        Iterator();
        Iterator(unsigned long);
        Iterator(const Iterator &);        

        Iterator operator++();    //prefix
        Iterator operator++(int); //postfix

        Iterator operator--();    //prefix
        Iterator operator--(int); //postfix

        Iterator operator+(unsigned long offset);
        Iterator operator+=(unsigned long offset);
        Iterator operator-(unsigned long offset);
        Iterator operator-=(unsigned long offset);

        bool operator==(const Iterator &);
        bool operator!=(const Iterator &);
        T operator*();
        T *operator->();

      private:
        size_t position;
    };

#pragma endregion

    //iterators methods
    Iterator begin();
    Iterator end();

    //functionality
    size_t GetSize() const;
    Iterator GetAt(size_t);
    template<class...Type> 
    void Add(Type...);
    void Remove(Iterator &);    
    Iterator Find(T &) const;
    void Clear();

    friend std::ostream& operator<<(std::ostream&, const Array<T>& array);
    //friend std::istream& operator>>(std::istream&, Array<T>& array);

  protected:
    T* data;
    unsigned long capacity;
    unsigned long size;
    void scale();
    void unscale();
};

class OverflowOffsetExeception{};

#include "Array.cpp"

#endif