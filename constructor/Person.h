#include "Hobby.h"

class Person {
	Hobby h;
	const int i;

public:
	static const int sci = 7;

	Person();
	Person(const Person&); // 拷贝构造
	~Person();

	Person & operator=(const Person &p); // 赋值构造
};
