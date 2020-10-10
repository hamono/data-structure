#pragma once
#include<iostream>
using namespace std;
template <class T>
class SqList
{
	T* data;
	int length;
	int listsize;
public:
	SqList();
	SqList(int maxLen);
	~SqList();
	bool insert(T e);
	bool delElement(T e);
	SqList mergeList(SqList &list);
	SqList delList(T elem1, T elem2);
	void showItem();
	SqList operator =(const SqList& b);
	int getLength();
};

template<class T>
inline SqList<T>::SqList()
{
}

template<class T>
inline SqList<T>::SqList(int maxLen)
{
	data = new T[maxLen];
	length = 0;
	listsize = maxLen;
}

template<class T>
inline SqList<T>::~SqList()
{
}

template<class T>
inline bool SqList<T>::insert(T e)
{
	if (length == 0) {
		data[0] = e;
		length++;
		cout << "\n添加成功！(" << e << ")\n";
	}
	else {
		if (length+1 > listsize) {
			cout << "\n顺序表越界！添加失败。\n";
			return false;
		}
		for (int i = length-1;; i--) {	
			if (i < 0) 
			{
				data[0] = e;
				break;
			}
			if (e >= data[i]) 
			{
				data[i + 1] = e;
				break;
			}
			else
			{
				data[i + 1] = data[i];
			}	
		}
		length++;
		cout << "\n添加成功！(" << e << ")\n";
	}
	return true;
}

template<class T>
inline bool SqList<T>::delElement(T e)
{
	int temp = length;
	if (length == 0) {
		cout << "\n删除失败，顺序表为空！\n";
		return false;
	}
	for (int i = 0; i < temp; i++) {
		if (data[i] == e) {
			for (int j = i; j <temp; j++) {
				data[j] = data[j+1];
			}
			length--;
		}
	}
	if (length == temp) {
		cout << "\n删除失败，顺序表中不含此元素！("<<e<<")\n";
		return false;
	}
	else {
		cout << "\n删除成功，共删除"<<temp-length<<"个元素！("<<e<<")\n";
	}
	return true;
}

template<class T>
inline SqList<T> SqList<T>::mergeList(SqList &list)
{
	SqList<T> temp(this->length + list.length);
	temp.length = this->length + list.length;
	int pop1=0, pop2=0;
	for (int i = 0; i < temp.length; i++) {
		if (pop1<this->length && pop2<list.length) {
			if (data[pop1] <= list.data[pop2]) {
				temp.data[i] = this->data[pop1];
				pop1++;
			}
			else
			{
				temp.data[i] = list.data[pop2];
				pop2++;
			}
		}
		else {
			if (pop1>this->length) {
				temp.data[i] = list.data[pop2];
				pop2++;
			}
			else 
			{
				temp.data[i] = data[pop1];
				pop1++;
			}
		}
	}
	cout << "\n合并成功！\n";
	return temp;
}

template<class T>
inline SqList<T> SqList<T>::delList(T elem1, T elem2)
{
	int i, j;
	if (elem1 >= elem2) {
		cout << "\n无效的参数！\n";
		return *this;
	}
	if (length == 0) {
		cout << "\n顺序表无数据！\n";
		return *this;
	}
	for (i = 0; i < length; i++) {
		if (data[i] > elem1) {
			break;
		}
	}
	for (j = length-1; j >= 0; j--) {
		if (data[j] < elem2) {
			break;
		}
	}
	if (i > j) {
		cout << "\n搜索不到数据，请检查参数！\n";
		return *this;
	}
	length = length - j + i - 1;
	for (;i<length;i++,j++) {
		data[i] = data[j+1];
	}	
	return *this;
}

template<class T>
inline void SqList<T>::showItem()
{
	if (length != 0) {
		for (int i = 0; i < length; i++) {
			cout << data[i]<<"  ";
		}
	}
	else
	{
		cout << "顺序表无数据！";
	}
	cout << "\n";
}

template<class T>
inline SqList<T> SqList<T>::operator=(const SqList& b)
{
	this->data = b.data;
	this->length = b.length;
	this->listsize = b.listsize;
	return *this;
}

template<class T>
inline int SqList<T>::getLength()
{
	return length;
}
