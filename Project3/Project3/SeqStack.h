#pragma once
#include<iostream>
using namespace std;

template <class T>
class SeqStack
{
	int topL;
	int topR;
	int maxSize;
	T* elems;
public:
	SeqStack(int size=0);
	virtual ~SeqStack();
	bool push(int k,const T e);
	bool pop(int k,T& e);
	bool isEmpty(int k) const;
	bool isFull() const;
	void show();
};

template<class T>
inline SeqStack<T>::SeqStack(int size)
{
	maxSize = size;
	if (elems != NULL) {
		delete[]elems;
	}
	elems = new T[maxSize];
	topL = -1;
	topR = maxSize;
}

template<class T>
inline SeqStack<T>::~SeqStack()
{
	delete[]elems;
}

template<class T>
inline bool SeqStack<T>::push(int k, const T e)
{
	if (k == 1) {
		if (topL + 1 == topR) {
			cout << "添加失败！栈已满";
			return false;
		}
		elems[++topL] = e;
		cout << "\n栈1添加成功！(" << e << ")\n";
		return true;
	}
	else if (k == 2) {
		if (topR -1 == topL) {
			cout << "添加失败！栈已满";
			return false;
		}
		elems[--topR] = e;
		cout << "\n栈1添加成功！(" << e << ")\n";
		return true;
	}
	else {
		cout << "\n请输入正确的栈编号！\n";
		return false;
	}
}

template<class T>
inline bool SeqStack<T>::pop(int k,T& e)
{
	if (k == 1) {
		if (isEmpty(k)) {
			cout << "\n栈为空!\n";
			return false;
		}
		e = elems[topL--];
		cout << "\n出栈成功！(" << e << ")\n";
		return true;
	}
	else if (k == 2) {
		if (isEmpty(k)) {
			cout << "\n栈为空!\n";
			return false;
		}
		e = elems[topR++];
		cout << "\n出栈成功！(" << e << ")\n";
		return true;
	}
	else {
		cout << "\n请输入正确的栈编号！\n";
	}
}

template<class T>
inline bool SeqStack<T>::isEmpty(int k) const
{
	if (k == 1) {
		if (topL == -1) {
			return true;
		}
		else {
			return false;
		}
	}else if (k == 2) {
		if (topR == maxSize) {
			return true;
		}
		else {
			return false;
		}
	}
}

template<class T>
inline bool SeqStack<T>::isFull() const
{
	if (topL + 1 == topR - 1) {
		cout << "\n共享栈已满！\n";
		return true;
	}
	else {
		cout << "\n共享栈未满！\n";
		return false;
	}
	
}

template<class T>
inline void SeqStack<T>::show()
{
	if (isEmpty(1)&&!isEmpty(2)) {
		for (int i = maxSize; i >= topR; i--) {
			cout << elems[i] << "  ";
		}
	}
	else if (isEmpty(2)&&!isEmpty(1)) {
		for (int i = 0; i <= topL; i++) {
			cout<<elems[i]<<"  ";
		}
	}
	else if (isEmpty(2) && isEmpty(1)) {
		cout << "栈为空！";
	}
	else {
		for (int i = 0; i <= topL; i++) {
			cout << elems[i] << "  ";
		}
		cout << "\n";
		for (int i = maxSize-1; i >= topR; i--) {
			cout << elems[i] << "  ";
		}
	}
}
