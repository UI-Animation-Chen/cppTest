#ifndef PtrGen_h
#define PtrGen_h 1

template<typename T> class PtrGen {
	T *pt;
public:
	PtrGen(T*);
	T* operator->();
	PtrGen & operator++();
	PtrGen operator++(int);
	PtrGen & operator--();
	PtrGen operator--(int);
};

template<typename T> PtrGen<T>::PtrGen(T *_pt) {
	pt = _pt;
}

template<typename T> T* PtrGen<T>::operator->() {
	return pt;
}

template<typename T> PtrGen<T> & PtrGen<T>::operator++() {
	pt++;
	return *this;
}

template<typename T> PtrGen<T> PtrGen<T>::operator++(int) {
	pt++;
	return PtrGen<T>(pt);
}

template<typename T> PtrGen<T> & PtrGen<T>::operator--() {
	pt--;
	return *this;
}

template<typename T> PtrGen<T> PtrGen<T>::operator--(int) {
	pt--;
	return PtrGen<T>(pt);
}

#endif //PtrGen_h
