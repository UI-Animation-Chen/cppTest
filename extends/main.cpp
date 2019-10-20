#include<iostream>
#include "Cat.h"
#include "SmallCat.h"

using namespace std;

int main(int argc, char *argv[]) {
	Cat *c = new SmallCat("xiaomi", 1);
	Animal *a = c;
	a->speak();
	delete a;

	/*
	int i = 7;
	int *pi = &i;
	int *&rpi = pi; // pi指针的同名引用
	cout << "rpi: " << &rpi << ".\n";
	cout << " pi: " << &pi << ".\n";
	*/
	//int &*j;

	return 0;
}
