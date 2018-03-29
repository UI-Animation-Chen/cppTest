#ifndef MyException_h
#define MyException_h

class MyException {
public:
	MyException();
	MyException(const MyException &);
	
	MyException & operator=(const MyException &);
};

#endif // MyException_h
