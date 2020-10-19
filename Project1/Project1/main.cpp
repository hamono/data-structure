#include<iostream>
#include"sqList.h"

using namespace std;

int main() {
	SqList<int> test1(4),test2(3),test3,test4;
	test1.insert(8);
	test1.insert(9);
	test1.insert(1);
	test2.insert(4);
	test2.insert(8);
	test2.insert(7);
	test1.showItem();
	test2.showItem();
	test3 = test1.mergeList(test2);
	test3.showItem();
	test4=test3.delList(1, 10);
	test4.showItem();
//	cout << test1.getLength() << "	" << test2.getLength() << "	" << test3.getLength() << "	" << test4.getLength() << "	";
//	test1.delElement(8);
//	cout << test1.getLength() << "	" << test2.getLength() << "	" << test3.getLength() << "	" << test4.getLength() << "	";
}