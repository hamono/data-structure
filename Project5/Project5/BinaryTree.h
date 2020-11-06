#pragma once
#include"TreeNode.h"
#include<iostream>
#include<string>
#include<queue>

using namespace std;

template <class ElemType>
class BinaryTree
{
	TreeNode<ElemType>* root;
public:
	BinaryTree();
	~BinaryTree() {};
	void create(TreeNode<ElemType>* &e);
	int countLeave(TreeNode<ElemType>* e);
	int maxWidth(TreeNode<ElemType>* e);
	void inOrder(TreeNode<ElemType>* e);
};

template<class ElemType>
inline BinaryTree<ElemType>::BinaryTree()
{
}

template<class ElemType>
inline void BinaryTree<ElemType>::create(TreeNode<ElemType>* &e)
{
	char node;
	cin >> node;
	if (node == '#')
	{
		e = NULL;
	}
	else
	{
		e = (struct TreeNode<ElemType>*)malloc(sizeof(struct TreeNode<ElemType>));
		e->data = node;
		create(e->leftChild);
		create(e->rightChild);
	}
}

template<class ElemType>
inline int BinaryTree<ElemType>::countLeave(TreeNode<ElemType> *e)
{
	if (e == NULL) {
		return 0;
	}
	if (e->leftChild==NULL&&e->rightChild==NULL) {
		return 1;
	}
	return countLeave(e->leftChild) + countLeave(e->rightChild);
}

template<class ElemType>
inline int BinaryTree<ElemType>::maxWidth(TreeNode<ElemType> *e)
{
	if (e == NULL)
		return 0;
	int result = 0;

	queue<TreeNode<ElemType>*> q;
	q.push(e);
	while (!q.empty())
	{
		int count = q.size();

		result = max(count, result);

		while (count--)
		{
			TreeNode<ElemType>* temp = q.front();
			q.pop();
			if (temp->leftChild != NULL)
				q.push(temp->leftChild);
			if (temp->rightChild != NULL)
				q.push(temp->rightChild);
		}
	}

	return result;
}

template<class ElemType>
inline void BinaryTree<ElemType>::inOrder(TreeNode<ElemType>* e)
{
	if (e !=NULL) {
		
		inOrder(e->leftChild);
		cout << e->data;
		inOrder(e->rightChild);
	}
}
