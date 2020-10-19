#include"SeqStack.h"

int main() {
	SeqStack<int> test(20);
	int e;
	test.push(1, 2);
	test.push(1, 3);
	test.push(1, 4);
	test.push(1, 8);
	test.push(1, 383);
	test.push(2, 37);
	test.push(2, 38);
	test.push(2, 8);
	test.show();
	test.pop(1, e);
	test.pop(1, e);
	test.pop(2, e);
	test.show();
}
