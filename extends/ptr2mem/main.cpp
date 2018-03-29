#include<iostream>

#include "Cat.h"

using namespace std;

typedef int (Cat::*MEM_FN)();

int main(int argc, char *argv[]) {
	Cat c(1);
	MEM_FN mf = &Cat::getAge;
	int age = (c.*mf)();
	cout << "age is:" << age << ".\n";
	// 指向成员的指针并不是指针，他可能是一个结构里的偏移量，
	// 或是一个数组里的下标。所以不能赋给常规函数指针。
	// 只要布局一样，这种指针可以跨地址空间（进程）传递。
	MEM_FN mf2 = &Cat::getI;
	cout << "mf2:" << mf2 << ".\n";
	return 0;
}
