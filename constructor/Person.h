#include "Hobby.h"

class Person {
	Hobby h;

public:
	Person();
	Person(const Person&);
	~Person();

	Person & operator=(const Person &p);
};
