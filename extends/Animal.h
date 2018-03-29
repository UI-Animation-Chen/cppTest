#ifndef Animal_h
#define Animal_h

#include<string>

using namespace std;

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
