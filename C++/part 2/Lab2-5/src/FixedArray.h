#ifndef FIXED_ARRAY_H
#define FIXED_ARRAY_H

#include "Array.h"

template<class T>
class FixedArray: public Array<T>
{
  public:
    FixedArray(T, T);
    FixedArray(T, T, size_t);
    FixedArray(const FixedArray&);

    void Add(T&);
    void Update(Iterator<T>, T&);

    void operator=(IContainer<T>&);
    IAddable<T>& operator+(IAddable<T>&);
    IProductable<T>& operator*(IProductable<T>&);

  private:
    T min;
    T max;
};

#include "FixedArray.cpp"

#endif