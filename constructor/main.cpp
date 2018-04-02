#include<iostream>

#include "Person.h"

using namespace std;

Person getP() {
	Person p;
	cout << "getP: " << &p << ".\n";
	return p;
}

int main() {
	int i = Person::sci;
	cout << "main: " << &i << ".\n";
	// 这种情况编译器会进行优化，并没有创建新对象来接收函数返回值，而是直接
	// 将这个匿名对象扶正。总之，这里只创建了一个对象。
	Person p = getP();
	cout << "main: " << &p << ".\n";
	int j = 1;
	cout << "main: " << &j << ".\n";
	Person p1;
	cout << "mian p: " << &p1 << ".\n";
	p1 = p;
	return 0;
}

