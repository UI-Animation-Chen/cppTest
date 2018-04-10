#ifndef List_h
#define List_h 1

#include<iostream>

using namespace std;

template<typename T> class List {
    T t;
public:
	void add(T);
};

template<typename T> void List<T>::add(T t) {
	typename T::age age = 7;
	cout << "added successfully.\n";
}

#endif // List_h
