#include <iostream>
#include "SmallCat.h"

SmallCat::SmallCat(string name, int age): Cat(name, age) {
	
}

SmallCat::~SmallCat() {
	std::cout << "~SmallCat\n";
}

void SmallCat::speak() {
	std::cout << "small cat speak\n";
}
