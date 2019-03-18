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
class Array: public IAddable<T>, public IProductable<T>
{
  public:
    //ctors
    Array();
    Array(size_t);
    Array(const Array&);
    ~Array();
    
    class Iterator
    {
      public:
        Iterator(T*);

        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator==(const Iterator&);
        bool operator!=(const Iterator&);
        T* operator->(){return data;}
        T& operator*(){return *data;}
      private:        
        const T* data;
    };

    Iterator& begin();
    Iterator& end();

    //functionality
    size_t GetSize() const;    
    void Add(T&);
    void Remove(Iterator&);
    Iterator& Find(T&) const;
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

template<class T>
class FixedArray: public Array<T>
{
  public:
    FixedArray(T min, T max): min(min), max(max){}    

    void Add(T& item)
    {
      if(item >= min && item <= max)
      {
        this->Array<T>::Add(item);
      }
    }

  private:
    T min;
    T max;
};

class OverflowOffsetExeception{};
class DifferentSizeException{};

#include "Array.cpp"

#endif