#ifndef Cat_h
#define Cat_h

#include "Animal.h"

class Cat: public Animal {
public:
	Cat(string, int);
	~Cat();
	void speak();
};

#endif // Cat_h
