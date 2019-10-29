#include <iostream>
#include "SmallCat.h"

// 这里是定义。只能有一个，否则报错重复定义。
// 但是私有成员变量不能直接在外界访问。
string SmallCat::mStr = "chen";

SmallCat::SmallCat(string name, int age): Cat(name, age) {
	
}

SmallCat::~SmallCat() {
	std::cout << "~SmallCat\n";
}

void SmallCat::speak() {
	std::cout << "small cat speak -- " << mStr << "\n";
}
