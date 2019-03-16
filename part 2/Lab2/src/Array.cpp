#include "Array.h"
#include <ostream>

#pragma region IteratorImpl

template<typename T>
Array<T>::Iterator::Iterator(){
    position = 0;
}

template<typename T>
Array<T>::Iterator::Iterator(const Array<T>::Iterator& iter) {
	position = iter.position;
}

template<typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator++() {
	return end();
}

template<typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator++(int) {
	auto res = this;
	res.position++;
	return res;
}

template<typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator--() {
	position++;
	return this;
}

template<typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator--(int) {
	if(position > 1)
        auto res = Iterator();
	return res;
}

template<typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator+(unsigned long offset) {	
	auto temp = position - offset;
    if(size < temp)
        position = temp;
	return *this;
}

template<typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator+=(unsigned long offset) {
	auto temp = offset + position;
    if(size < temp)
        return Array<T>::Iterator(temp);
    else
        throw OverflowOffsetExeception;
}

template<typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator-(unsigned long offset) {
	auto temp = position - offset;
    if(temp > 0)
        return Array<T>::Iterator(temp);
    else
        throw OverflowOffsetExeception;
}

template<typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator-=(unsigned long offset) {
	auto temp = position - offset;
    if(temp > 0)
        position = temp;
	return *this;
}

template<typename T>
bool Array<T>::Iterator::operator==(const Array<T>::Iterator& iter) {
	return iter.position == position;
}

template<typename T>
bool Array<T>::Iterator::operator!=(const Array<T>::Iterator& iter) {
	return !operator==(iter);
}

template<typename T>
T Array<T>::Iterator::operator*() {
	return data[position];
}

template<typename T>
T* Array<T>::Iterator::operator->() {
	return *data[position];
}

#pragma endregion

template<class T>
void copyData(T* destination, T* source, unsigned int size)
{
	for(int i = 0; i < size; i++)
		destination[i] = source[i];
}

#pragma region Array Implementation

template<class T>
Array<T>::Array():Array(10){}

template<class T>
Array<T>::Array(size_t capacity):size(0)
{
	data = new T[capacity];
	this.capacity = capacity;
}

template<class T>
Array<T>::Array(const Array<T>& array)
{
	capacity = array.capacity;
	size = array.size;
	delete[] data;
	data = new T[capacity];
	copyData(data, array.data, size);
}

template<class T>
Array<T>::~Array()
{
	delete[] data;
}

template<class T>
void Array<T>::scale()
{
	T* newData = new T[capacity * 1.5]
	copyData(data, newData, size);
	delete[] data;
	data = newData;
}

template<class T>
void Array<T>::unscale()
{
	T* newData = new T[(int)(capacity / 2)]
	copyData(data, newData, size);
	delete[] data;
	data = newData;
}

template<class T>
size_t Array<T>::GetSize() const
{
	return size;
}

template<class T>
typename Array<T>::Iterator Array<T>::GetAt(size_t position)
{
	if(position >= size)
		throw OverflowOffsetExeception();
	
	return begin() + position;
}

template<class T>
template<class...Type>
void Array<T>::Add(Type... items)
{
	if(size >= capacity)
		scale();
	data[size] = items;
	Add(...)
}

template<class T>
void Array<T>::Remove(Array<T>::Iterator& iterator)
{
	iterator++;
	for(iterator < end(); iterator++)
	{
		*iterator-- = *iterator;
	}	

	if(size / capacity < 3)
		unscale();
}

template<class T>
typename Array<T>::Iterator Array<T>::Find(T& item) const
{
	for(auto it = begin(); i < end(); i++)
	{
		if(*it == item)
			return it;
	}
	return end();
}

template<class T>
void Array<T>::Clear()
{
	delete[] data;
	data = new T[10];
	capacity = 10;
	size = 0;
}

template<class T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& array)
{
	for(int i = 0; i < size; i++)
	{
		ostream << i + 1 + ". " + array.data[i] + std::endl;
	}
	stream << "#" << endl;
}

#pragma endregion