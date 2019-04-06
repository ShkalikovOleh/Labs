#include "Array.h"
#include <ostream>
#include <cstring>

#pragma region IteratorImpl

template<class T>
Iterator<T>::Iterator(T* data):data(data){}

template<class T>
Iterator<T>& Iterator<T>::operator++()
{
	++data;
	return *this;
}

template<class T>
Iterator<T> Iterator<T>::operator++(int)
{
	auto temp = *this;
    ++*this;
    return temp;
}

template<class T>
Iterator<T>& Iterator<T>::operator--()
{
	--data;
	return *this;
}

template<class T>
Iterator<T> Iterator<T>::operator--(int)
{
	auto temp = *this;
    --*this;
    return temp;
}

template<class T>
bool Iterator<T>::operator==(const Iterator& iterator)
{
	return (data == iterator.data);
}

template<class T>
bool Iterator<T>::operator!=(const Iterator& iterator)
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
Iterator<T> Array<T>::begin() const
{
	return Iterator<T>(data);
}

template<class T>
Iterator<T> Array<T>::end() const
{
	return Iterator<T>(data + size);
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
void Array<T>::Remove(Iterator<T> iterator)
{	
	unsigned long position = (iterator.data - data);
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
void Array<T>::Update(Iterator<T> iterator, T& item)
{
	if(iterator != end())
		*iterator = item;
}

template<class T>
Iterator<T> Array<T>::Find(T& item) const
{
	for(int i = 0; i < this->size; i++)
	{
		if(data[i] == item)
			return Iterator<T>(data + i);
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
	if(position > this->size || this->size <= 0)
		throw OverflowSizeExeception();
	
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
			result->size++;
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
			result->size++;
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
		stream << array.data[i] << std::endl;
	}
	return stream;
}

template<class U>
std::istream& operator>>(std::istream& stream, Array<U>& array)
{
	U item = U();
	int tt = 0;
	while(array.size < array.capacity)
	{	
		stream >> item;	
		if(stream.fail())
		{			
			stream.clear();		
			stream.ignore();
			if(stream.eof())
				break;
			continue;
		}					
		array.Add(item);		
	}
	return stream;
}

#pragma endregion