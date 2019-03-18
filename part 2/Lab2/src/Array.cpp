#include "Array.h"
#include <ostream>
#include <cstring>

#pragma region IteratorImpl

template<class T>
Array<T>::Iterator::Iterator(T* data):data(data){}

template<class T>
typename Array<T>::Iterator& Array<T>::Iterator::operator++()
{
	++data;
	return *this;
}

template<class T>
typename Array<T>::Iterator Array<T>::Iterator::operator++(int)
{
	auto temp = *this;
    ++*this;
    return temp;
}

template<class T>
typename Array<T>::Iterator& Array<T>::Iterator::operator--()
{
	--data;
	return *this;
}

template<class T>
typename Array<T>::Iterator Array<T>::Iterator::operator--(int)
{
	auto temp = *this;
    --*this;
    return temp;
}

template<class T>
bool Array<T>::Iterator::operator==(const Iterator& iterator)
{
	return (data == iterator.data);
}

template<class T>
bool Array<T>::Iterator::operator!=(const Iterator& iterator)
{
	return (data != iterator.data);
}

#pragma endregion

#pragma region ArrayImpl

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
typename Array<T>::Iterator& Array<T>::begin()
{
	return Iterator(data);
}

template<class T>
typename Array<T>::Iterator& Array<T>::end()
{
	return Iterator(data + size);
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
void Array<T>::Remove(Array<T>::Iterator& iterator)
{	
	unsigned long position = (iterator.data - begin().data) / sizeof(T);
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
typename Array<T>::Iterator& Array<T>::Find(T& item) const
{
	for(int i = 0; i < this->size; i++)
	{
		if(data[i] == item)
			return Iterator(data + i);
	}
	return end();
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
void Array<T>::operator=(IContainer<T>& container)
{
	delete[] data;
	capacity = size = container.GetSize();
	data = new T[capacity];
	for(int i = 0; i < container.GetSize(); i++)
	{
		data[i] = container[i];
	}
}

template<class T>
IAddable<T>& Array<T>::operator+(IAddable<T>& array)
{
	if(array.GetSize() == this->size)
	{
		Array<T>* result = new Array<T>(this->size);
		for(int i = 0; i < this->size; i++)
		{
			result->data[i] = data[i] + array[i];
		}
		return *result;
	}
	throw DifferentSizeException();
}

template<class T>
IProductable<T>& Array<T>::operator*(IProductable<T>& array)
{
	if(array.GetSize() == this->size)
	{
		Array<T>* result = new Array<T>(this->size);
		for(int i = 0; i < this->size; i++)
		{
			result->data[i] = data[i] * array[i];
		}
		return *result;
	}
	throw DifferentSizeException();
}

template<class U>
std::ostream& operator<<(std::ostream& stream, const Array<U>& array)
{
	for(int i = 0; i < array.size; i++)
	{
		stream << i + 1 + ". " + array.data[i] + std::endl;
	}
}

template<class U>
std::istream& operator>>(std::istream& stream, Array<U>& array)
{
	U item = U();
	while(stream >> item)
	{		
		array.Add(item);
	}
	return stream;
}

#pragma endregion