#include<iostream>

#include "Animal.h"

Animal::Animal(string aName, int anAge): name(aName), age(anAge) {
	
}

Animal::~Animal() {}

string Animal::getName() {
	return name;
}

void Animal::setName(string aName) {
	name = aName;
}

int Animal::getAge() {
	return age;
}
