#pragma once
template <class ElemType>
struct TreeNode
{
	ElemType data;
	TreeNode<ElemType>* leftChild;
	TreeNode<ElemType>* rightChild;

	TreeNode();
	TreeNode(const ElemType& d, TreeNode<ElemType>* lChild = NULL, TreeNode<ElemType>* rChild = NULL);

};

template<class ElemType>
inline TreeNode<ElemType>::TreeNode()
{
	data = NULL;
	leftChild = rightChild = NULL;
}

template<class ElemType>
inline TreeNode<ElemType>::TreeNode(const ElemType& d, TreeNode<ElemType>* lChild, TreeNode<ElemType>* rChild)
{
	data = d;
	leftChild = lChild;
	rightChild = rChild;
}
