#include "List.h"

#pragma region ListItemImpl

template<typename T>
ListItem<T>::ListItem(){
    value = T();
    next = nullptr;
}

template<typename T>
ListItem<T>::ListItem(T& value){
    this->value = value;
    next = nullptr;
}

template<typename T>
T ListItem<T>::GetValue(){
   return value;
}

template<typename T>
bool ListItem<T>::IsNextExist(){
    return next;
}

template<typename T>
void ListItem<T>::SetNext(ListItem* item){
    if(item)
        next = item;
}

#pragma endregion

#pragma region IteratorImpl

template<typename T>
List<T>::Iterator::Iterator(){
    pointer = nullptr;
}

template<typename T>
List<T>::Iterator::Iterator(ListItem<T>* item) {
	pointer = item;
}

template<typename T>
List<T>::Iterator::Iterator(ListItem<T>& item) {
	pointer = &item;
}

template<typename T>
List<T>::Iterator::Iterator(const List<T>::Iterator& iter) {
	pointer = iter.pointer;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++() {
	pointer = pointer->next;	
	return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
	auto res = iterator(pointer->next);
	return res;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator--() {
	pointer = pointer->before;
	return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator--(int) {
	auto res = Iterator(pointer->before);
	return res;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator+(unsigned long offset) {	
	List<T>::Iterator res = *this;
	while (offset > 0) {
		res = res.pointer->next;
		offset--;
	}
	return res;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator+=(unsigned long offset) {
	while (offset > 0) {
		pointer = pointer->next;
		offset--;
	}
	return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator-(unsigned long offset) {
	List<T>::Iterator res = *this;
	while (offset > 0) {
		res = res.pointer->before;
		offset--;
	}
	return res;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator-=(unsigned long offset) {
	while (offset > 0) {
		pointer = pointer->before;
		offset--;
	}
	return *this;
}

template<typename T>
bool List<T>::Iterator::operator==(const List<T>::Iterator& iter) {
	return iter.pointer == pointer;
}

template<typename T>
bool List<T>::Iterator::operator!=(const List<T>::Iterator& iter) {
	return !operator==(iter);
}

template<typename T>
T List<T>::Iterator::operator*() {
	return pointer->value;
}

template<typename T>
T* List<T>::Iterator::operator->() {
	return &pointer->value;
}

#pragma endregion

#pragma region ListImpl

template<typename T>
List<T>::List(){
    head = nullptr;
    size = 0;
}

template<typename T>
List<T>::List(T& value){
    head = new ListItem<T>(value);
    size = 1;
}

template<typename T>
List<T>::List(const List<T>& list){
    ListItem<T>* currentInOther = list.head;
    ListItem<T>* currentInternal = head;
    while(currentInOther){
        currentInternal = new ListItem<T>(currentInOther->value);
        currentInternal->before = currentInOther->before;
        currentInOther = currentInOther->next;
    }
    size = list.size;
}

template<typename T>
List<T>::~List(){
    ListItem<T>* current = head;
    while(current){
        current = current->next;
        delete current->before;
    }
}

template<typename T>
typename List<T>::Iterator List<T>::begin(){
    return Iterator(head);
}

template<typename T>
typename List<T>::Iterator List<T>::end(){
    return Iterator(nullptr);
}

template<typename T>
unsigned long List<T>::GetSize(){
    return size;
}

template<typename T>
typename List<T>::Iterator List<T>::GetAt(unsigned long position){
    return begin()+=(position - 1);
}

template<typename T>
void List<T>::AddItemBefore(T& value, List<T>::Iterator& iter){
    ListItem<T>* newItem = new ListItem<T>(value);
    iter.pointer->before = newItem;
    newItem->next = iter.pointer;
    Iterator before = --iter;
    if(iter.pointer)
        before->next = newItem;
    size++;
}

template<typename T>
void List<T>::AddItemAfter(T& value, List<T>::Iterator& iter){
    ListItem<T>* newItem = new ListItem<T>(value);
    iter.pointer->next = newItem;
    newItem->before = iter.pointer;
    Iterator next = ++iter;
    if(iter.pointer)
        next->before = newItem;
    size++;
}

template<typename T>
void List<T>::Remove(List<T>::Iterator& iter){   
    if(iter.pointer->next && iter.pointer->before){
        iter.pointer->next->before = iter.pointer->before;
        iter.pointer->before->next = iter.pointer->next;
        delete iter.pointer;
        size--;
        return;
    }
    if(!iter.pointer->next){
        iter.pointer->before->next = nullptr;
        delete iter.pointer;
        size--;
        return;
    }
    if(iter == begin()){
        head = iter.pointer->next;
        delete iter.pointer;
        size--;
        return;
    }
}

template<typename T>
typename List<T>::Iterator List<T>::Find(T& value){
    ListItem<T>* current = head;
    while(current){
        if(current->value == value){
            return Iterator(current);            
        }
        current = current->next;
    }
}  

template<typename T>
void List<T>::Clear(){
    ListItem<T>* current = head;
    while(current){
        current = current->next;
        delete current->before;
    }
    size = 0;
}

#pragma endregion