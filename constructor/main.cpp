#include<iostream>

#include "Person.h"

using namespace std;

Person getP() {
	Person p;
	cout << "getP: " << &p << ".\n";
	return p;
}

int main() {
	// 这种情况编译器会进行优化，并没有创建新对象来接收函数返回值，而是直接
	// 将这个匿名对象扶正。总之，这里只创建了一个对象。
	Person p = getP();
	cout << "main: " << &p << ".\n";

	Person p1; // 构造函数
	cout << "mian p: " << &p1 << ".\n";
	p1 = p; // 赋值构造

	Person p2 = p; // 拷贝构造
	return 0;
}

