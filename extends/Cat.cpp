#include <iostream>

#include "Cat.h"

Cat::Cat(string name, int age): Animal(name, age) {
}

Cat::~Cat() {
	std::cout << "~Cat\n";
}

void Cat::speak() {
	cout << "name: " << Animal::getName() << ", age: " << Animal::getAge()
	<< ", miao~\n";
}
