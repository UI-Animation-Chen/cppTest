#ifndef PtrGen_h
#define PtrGen_h 1

template<typename T> class PtrGen {
	T t;
public:
	PtrGen(T);
	T* operator->();
};

template<typename T> PtrGen<T>::PtrGen(T _t) {
	t = _t;
}

template<typename T> T* PtrGen<T>::operator->() {
	return &t;
}

#endif //PtrGen_h
