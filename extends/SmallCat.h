#include "Cat.h"

class SmallCat: public Cat {
public:
	SmallCat(string, int);
	virtual ~SmallCat();
	virtual void speak();
};
