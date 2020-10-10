#pragma once
template <class T>
class Node
{	
public:
	T data;
	Node* next;
	Node(T data);
	Node();
	~Node();
};

template<class T>
inline Node<T>::Node(T data)
{
	this->data = data;
	this->next = NULL;
}

template<class T>
inline Node<T>::Node()
{
}

template<class T>
inline Node<T>::~Node()
{
}
