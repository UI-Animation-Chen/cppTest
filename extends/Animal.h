#ifndef Animal_h
#define Animal_h

#include <string>

using namespace std;

/**
 * 父类的析构函数一定会调用，编译器强制规定的。
 * 父类变量引用子类对象，则需要多态才能调用子类析构函数，否则只调用父类的析构。
 */

class Animal {
	string name;
	int age;
public:
	Animal(string, int);
	~Animal();
	string getName();
	void setName(string);
	int getAge();
	virtual void speak() = 0;
};

#endif // Animal_h
