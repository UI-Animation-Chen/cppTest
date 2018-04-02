#include "Hobby.h"

class Person {
	Hobby h;
	const int i;

public:	
	static const int sci = 7;

	Person();
	Person(const Person&);
	~Person();

	Person & operator=(const Person &p);
};
