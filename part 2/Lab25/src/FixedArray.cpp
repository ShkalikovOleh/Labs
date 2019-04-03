#include "FixedArray.h"

template<class T>
FixedArray<T>::FixedArray(T min, T max) : min(min), max(max){}

template<class T>
FixedArray<T>::FixedArray(T min, T max, size_t capacity) : min(min), max(max)
{
	this->capacity = capacity;
}

template<class T>
FixedArray<T>::FixedArray(const FixedArray<T>& array)
{
	this->capacity = array.capacity;
	this->size = array.size;
	delete[] this->data;
	this->data = new T[this->capacity];
	for(int i = 0; i < this->size; i++)
	{
		if(array.data[i] > min && array.data[i] < max)
		{
			this->data[i] = array.data[i];			
		}
		else
		{
			this->data[i] = min;
		}
	}
}

template<class T>
void FixedArray<T>::Add(T& item)
{
    if(item >= min && item <= max)
    {
    	this->Array<T>::Add(item);
    }
}

template<class T>
void FixedArray<T>::Update(Iterator<T> iterator, T& item)
{
	if(item >= min && item <= max)
	{
		this->Array<T>::Update(iterator, item);
	}		
}

template<class T>
void FixedArray<T>::operator=(IContainer<T>& container)
{
	delete[] this->data;
	this->capacity = this->size = container.GetSize();
	this->data = new T[this->capacity];
	for(int i = 0; i < container.GetSize(); i++)
	{
		if(container[i] > min && container[i] < max)
		{
			this->data[i] = container[i];			
		}
		else
		{
			this->data[i] = min;
		}		
	}	
}

template<class T>
IAddable<T>& FixedArray<T>::operator+(IAddable<T>& array)
{
	if(array.GetSize() != this->size)
		throw DifferentSizeException();
	FixedArray<T>* result = new FixedArray<T>(min, max, array.GetSize());
	for(int i = 0; i < result->size; i++)
	{		
		T temp = array[i] + this->data[i];
		if(temp < min || temp > max)
		{
			result->data[i] = min;
		}
		else
		{
			result->data[i] = temp;
		}
		result->size++;
	}
	return *result;
}

template<class T>
IProductable<T>& FixedArray<T>::operator*(IProductable<T>& array)
{	
	if(array.GetSize() != this->size)
		throw DifferentSizeException();
	FixedArray<T>* result = new FixedArray<T>(min, max, array.GetSize());
	for(int i = 0; i < result->size; i++)
	{		
		T temp = array[i] * this->data[i];
		if(temp < min || temp > max)
		{
			result->data[i] = min;
		}
		else
		{
			result->data[i] = temp;
		}
		result->size++;
	}
	return *result;
}