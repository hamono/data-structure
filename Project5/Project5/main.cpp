#include <iostream>
#include"BinaryTree.h"
#include"TreeNode.h"


using namespace std;
int main() {
	TreeNode<char>* e;
	BinaryTree<char> test;
	test.create(e);
	cout << test.countLeave(e);
	cout << endl;
	cout << test.maxWidth(e);
	cout << endl;
	test.inOrder(e);
}