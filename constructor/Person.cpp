#include<iostream>

#include "Person.h"

using namespace std;

Person::Person(): h(7), i(0) {
	cout << "Person().\n";
}

Person::Person(const Person &p): h(7), i(0) {
	cout << "Person cp.\n";
}

Person & Person::operator=(const Person &p) {
	cout << "Person =.\n";
	return *this;
}

Person::~Person() {
	cout << "~Person().\n";
}

