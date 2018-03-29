#include<iostream>

#include "FnObj.h"

using namespace std;

void FnObj::operator()(int a) {
	cout << "arg from fn obj:" << arg << ".\n";
	cout << "arg from the caller:" << a << ".\n";
}
