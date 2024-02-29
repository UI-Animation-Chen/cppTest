#ifndef PERSON_H
#define PERSON_H

#include "Hobby.h"

class Person {
	Hobby h;
	const int i;

public:
	static const int sci = 7;

	Person();
	Person(const Person&); // 拷贝构造
	virtual ~Person();

	Person & operator=(const Person &p); // 赋值构造
};

#endif // PERSON_H

