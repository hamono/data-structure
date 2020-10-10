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
		cout << "\n��ӳɹ���(" << e << ")\n";
	}
	else {
		if (length+1 > listsize) {
			cout << "\n˳���Խ�磡���ʧ�ܡ�\n";
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
		cout << "\n��ӳɹ���(" << e << ")\n";
	}
	return true;
}

template<class T>
inline bool SqList<T>::delElement(T e)
{
	int temp = length;
	if (length == 0) {
		cout << "\nɾ��ʧ�ܣ�˳���Ϊ�գ�\n";
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
		cout << "\nɾ��ʧ�ܣ�˳����в�����Ԫ�أ�("<<e<<")\n";
		return false;
	}
	else {
		cout << "\nɾ���ɹ�����ɾ��"<<temp-length<<"��Ԫ�أ�("<<e<<")\n";
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
	cout << "\n�ϲ��ɹ���\n";
	return temp;
}

template<class T>
inline SqList<T> SqList<T>::delList(T elem1, T elem2)
{
	int i, j;
	if (elem1 >= elem2) {
		cout << "\n��Ч�Ĳ�����\n";
		return *this;
	}
	if (length == 0) {
		cout << "\n˳��������ݣ�\n";
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
		cout << "\n�����������ݣ����������\n";
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
		cout << "˳��������ݣ�";
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
