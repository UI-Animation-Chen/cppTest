#include "Cat.h"

#include<iostream>

using namespace std;

int main(int argc, char *argv[]) {
	Cat c = Cat("xiaomi", 1);
	Animal &a = c;
	a.speak();
	Animal *pa = &c;
	pa->speak();

	int i = 7;
	int *pi = &i;
	int *&rpi = pi;
	cout << "rpi: " << rpi << ".\n";

	//int &*j;

	return 0;
}
