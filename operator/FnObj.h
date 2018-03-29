#ifndef FnObj_h
#define FnObj_h 1

class FnObj {
	int arg;
public:
	FnObj(int a) {arg = a;}
	void operator()(int);
};

#endif //FnObj_h
