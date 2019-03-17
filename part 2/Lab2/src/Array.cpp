#include "Array.h"
#include <ostream>
#include <cstring>

template<class T>
Array<T>::Array():Array(10){}

template<class T>
Array<T>::Array(size_t capacity):size(0)
{
	data = new T[capacity];
	this->capacity = capacity;
}

template<class T>
Array<T>::Array(const Array<T>& array)
{
	capacity = array.capacity;
	this->size = array.size;
	delete[] data;
	data = new T[capacity];
	memcpy(data, array.data, size);
}

template<class T>
Array<T>::~Array()
{
	delete[] data;
}

template<class T>
void Array<T>::scale()
{
	T* newData = new T[(int)(capacity * 1.5)];
	memcpy(newData, data, this->size);
	delete[] data;
	data = newData;
}

template<class T>
void Array<T>::unscale()
{
	T* newData = new T[(int)(capacity / 2)];
	memcpy(newData, data, this->size);
	delete[] data;
	data = newData;
}

template<class T>
size_t Array<T>::GetSize() const
{
	return this->size;
}

template<class T>
void Array<T>::Add(T& item)
{
	if(size >= capacity)
		scale();
	data[this->size] = item;
	size++;
}

template<class T>
void Array<T>::Remove(unsigned long position)
{	
	if(position < this->size)
	{
		for(int i = position; i < this->size - 1; i++)
		{
			data[i] = data[i+1];
		}
		this->size--;
	}

	if(this->size / capacity < 3)
		unscale();
}

template<class T>
unsigned int Array<T>::Find(T& item) const
{
	for(int i = 0; i < this->size; i++)
	{
		if(data[i] == item)
			return i;
	}
	return -1;
}

template<class T>
void Array<T>::Clear()
{
	delete[] data;
	data = new T[10];
	capacity = 10;
	this->size = 0;
}

template<class T>
const T& Array<T>::operator[](unsigned long position)
{
	if(position >= this->size && this->size < 0)
		throw OverflowOffsetExeception();
	
	return data[position];
}

template<class T>
IAddable<T>& Array<T>::operator+(IAddable<T>& array)
{
	if(array.GetSize() == this->size)
	{
		Array<T> result = Array<T>(this->size);
		for(int i = 0; i < this->size; i++)
		{
			result.data[i] = data[i] + array[i];
		}
		return result;
	}
	throw DifferentSizeException();
}

template<class T>
IProductable<T>& Array<T>::operator*(IProductable<T>& array)
{
	if(array.GetSize() == this->size)
	{
		Array<T> result = Array<T>(this->size);
		for(int i = 0; i < this->size; i++)
		{
			result.data[i] = data[i] * array[i];
		}
		return result;
	}
	throw DifferentSizeException();
}

template<class T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& array)
{
	for(int i = 0; i < array.size; i++)
	{
		stream << i + 1 + ". " + array.data[i] + std::endl;
	}
}

template<class T>
std::istream& operator>>(std::istream& stream, Array<T>& array)
{
	T item = T();
	while(stream >> item)
	{		
		array.Add(item);
	}
	return stream;
}