#include<iostream>
#include"SuqQueue.h"
using namespace std;

void triangle(int num);

int main() {
	triangle(10);
}

void triangle(int num) {
	cout << 1;
	SuqQueue<int> test(num);
	int elem_1 = 1;
	int elem_0 = 0;
	int row, next_row;
	int temp = 0;
	test.enQueue(elem_1);
	test.enQueue(elem_1);
	for (int r = 1; r <num-2; r++)
	{
		cout << endl;
		test.enQueue(elem_0);
		for (int c = 1; c <= r + 2; c++)
		{
			test.delQueue(row);
			next_row = row + temp;
			test.enQueue(next_row);
			temp = row;
			if (c != r + 2)
				cout << temp << " ";
		}
	}
}