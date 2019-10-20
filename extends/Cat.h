#ifndef Cat_h
#define Cat_h

#include "Animal.h"

class Cat: public Animal {
public:
	Cat(string, int);
	virtual ~Cat();
	virtual void speak();
};

#endif // Cat_h
