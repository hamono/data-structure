#pragma once
#include<iostream>
using namespace std;

template <class T>
class SuqQueue
{
	int front, rear;
	int maxSize;
	T* elems;
public:
	SuqQueue(int size = 0);
	virtual ~SuqQueue();
	bool enQueue(const T e);
	bool delQueue(T& e);
	bool isEmpty() const;
	void show();
};

template<class T>
inline SuqQueue<T>::SuqQueue(int size)
{
	maxSize = size;
	if (elems != NULL) {
		delete[]elems;
	}
	elems = new T[size];
	rear = front = 0;
}

template<class T>
inline SuqQueue<T>::~SuqQueue()
{
	delete[]elems;
}

template<class T>
inline bool SuqQueue<T>::enQueue(const T e)
{
	if ((rear + 1) % maxSize == front) {
		cout << "\n队列已满！\n";
		return false;
	}
	elems[rear] = e;
	rear = (rear + 1) % maxSize;
//	cout << "\n入队成功！" << e << endl;
	return true;
}

template<class T>
inline bool SuqQueue<T>::delQueue(T& e)
{
	if (!isEmpty()) {
		e = elems[front];
		front = (front + 1) % maxSize;
//		cout << "\n出队成功！" << e << endl;
		return true;
	}
	else {
		cout << "\n出队失败！空队列" << e << endl;
		return false;
	}
}

template<class T>
inline bool SuqQueue<T>::isEmpty() const
{
	if (front == rear) {
		return true;
	}
	else {
		return false;
	}	
}

template<class T>
inline void SuqQueue<T>::show()
{
	if (isEmpty()) {
		return;
	}
	for (int i = front; i < rear; i++) {
		cout << elems[i] << "  ";
	}
}
