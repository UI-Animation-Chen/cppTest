#include "MyException.h"

#include<iostream>

using namespace std;

MyException::MyException() {
	cout << "MyException\n";
}

MyException::MyException(const MyException &e) {
	cout << "MyException assign\n";
}

MyException & MyException::operator=(const MyException &e) {
	cout << "MyException =\n";
}

