#include<iostream>
#include"list.h"
#include"node.h"
using namespace std;

int main() {
	List<int> test1;
	test1.insert(2);
	test1.insert(4);
	test1.insert(1);
	test1.insert(8);
	test1.insert(8);
	test1.insert(8);
	test1.insert(10);
	test1.showItem();
	test1.countItem(8);
//	test1.searchItem(8);
}