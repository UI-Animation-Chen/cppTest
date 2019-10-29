#include "Cat.h"

class SmallCat: public Cat {
public:
	SmallCat(string, int);
	virtual ~SmallCat();
	virtual void speak();
private:
	static string mStr; // 这里是声明，还必须定义。
};
