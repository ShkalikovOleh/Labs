#ifndef LIST_H
#define LIST_H

template<typename T>
class ListItem{
public:
    ListItem();
    ListItem(T&);
    T GetValue();
    bool IsBeforeExist();
    bool IsNextExist();    
    void SetBefore(ListItem*);
    void SetNext(ListItem*);    
private:
    T value;
    ListItem* next;
    ListItem* before;

    template<typename T> friend class List;
    template<typename T> friend class List<T>::Iterator;
};

template<typename T>
class List{
public:
    //ctors
    List();
    List(T&);
    List(const List&);    
    ~List();

    //iterators
    #pragma region Iterator

    class Iterator{
    public:
        Iterator();
		Iterator(const Iterator&);
		Iterator(ListItem<T>*);
		Iterator(ListItem<T>&);        

		Iterator operator++();			//prefix
		Iterator operator++(int);	    //postfix

		Iterator operator--();			//prefix
		Iterator operator--(int);		//postfix
		
		Iterator operator+(unsigned long offset);
		Iterator operator+=(unsigned long offset);
		Iterator operator-(unsigned long offset);
		Iterator operator-=(unsigned long offset);

		bool operator==(const Iterator&);
		bool operator!=(const Iterator&);
		T operator*();
        T* operator->();
    private:
        ListItem<T>* pointer;

        template<typename T> friend class List<T>;
    };

    #pragma endregion

    //iterators methods
    Iterator begin();
    Iterator end();

    //functionality
    unsigned long GetSize();
    Iterator GetAt(unsigned long);
    void AddItemBefore(T& value, Iterator&);
    void AddItemAfter(T& value, Iterator&);
    void Remove(Iterator&);
    Iterator Find(T&);    
    void Clear();
private:
    ListItem<T>* head;
    unsigned long size;            
};

#include "List.cpp";

#endif