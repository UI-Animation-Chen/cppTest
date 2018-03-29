#include<iostream>
#include<typeinfo>

#include "Zi.h"

using namespace std;

int Zi::getInt() {
	Zi z;
	//Ye &y = z;
	return 0;
}

int main(int agrc, char *argv[]) {
	Zi z;
	Fu f;
	int i = f.pro;
	Ye y;
	cout << "name:" << typeid(y).name() << '\n';
	//Ye &y = z; // can't cast.
	//int i = z.pro; // can't access.
	return 0;
}
