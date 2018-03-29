void f() {
	int array[2], *parr;
	for (parr = array; parr < array+2;)
		*parr++ = 0;
}
