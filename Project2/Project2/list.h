#pragma once
#include "node.h"
#include<iostream>
using namespace std;
template <class T>
class List
{
	Node<T>* head;
	int length;
public:
	List();
	~List();
	bool insert(T const& item);
	int* searchItem(T const& item);
	int countItem(T const& item);
	int getLength();
	void showItem();
};

template<class T>
inline List<T>::List()
{
	this->head = new Node<T>;
	length = 0;
}

template<class T>
inline List<T>::~List()
{
}

template<class T>
inline bool List<T>::insert(T const& item)
{
	Node<T>* p, * q;
	q =new Node<T>(item);
	for (p = head; p->next != NULL; p = p->next);
	p->next = q;
	length++;
	cout << "\n插入成功！(" << item << ")\n";
	return true;
}

template<class T>
inline int* List<T>::searchItem(T const& item)
{
	int arr[100];
	int position = 1,i=0;
	Node<T>* p = head->next;
	for (; p != NULL; p = p->next) {
		if (p->data == item) {
			arr[i] = position;
			i++;
		}
		position++;
	}
	if (i == 0) {
		cout << "\n定位失败！未找到元素(" << item << ")\n";
		arr[0] = 0;
		return arr;
	}
	else {
		cout << "\n定位成功！共定位到元素" << i  << "个 (" << item << ")\n";
		return  arr;
	}
}

template<class T>
inline int List<T>::countItem(T const& item)
{
	int i = 0;
	Node<T>* p = head->next;
	for (; p != NULL; p = p->next) {
		if (p->data == item) {
			i++;
		}
	}
	cout << "\n统计成功！共找到到元素" << i  << "个 (" << item << ")\n";
	return i;
}

template<class T>
inline int List<T>::getLength()
{
	return length;
}

template<class T>
inline void List<T>::showItem()
{
	Node<T>* p;
	for (p = head->next; p != NULL; p = p->next) {
		cout << p->data << "  ";
	}
}
