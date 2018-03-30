#include<iostream>
#include<unistd.h>
#include<pthread.h>

#define STR_SIZE 32

inline void setName(char *str, int baseSize, int i) {
	str[STR_SIZE - 1] = '\0';
	str[baseSize] = '0' + i;
	str[baseSize+1] = '\0';
}

void * run(void *arg) {
	char *tname;
	tname = (char *)arg;
	std::cout << "tname:" << tname << ".\n";
	pthread_t tid;
	tid = pthread_self();
	//std::cout << "pthread_self  :" << tid << ".\n";
	return NULL;
}

int main() {
	pthread_t pthreads[3];
	for (int i = 0; i < 3; i++) {
		int baseSize = 11;
		char str[STR_SIZE] = "new_thread_";
		setName(str, baseSize, i);
		// run instantly after created.
		pthread_create(&pthreads[i], NULL, run, (void *)str);

		pthread_join(pthreads[i], NULL);

		/* pthreads[i] == pthread_self() */
		//std::cout << "pthread_create:" << pthreads[i] << ".\n";
	}
	//sleep(1);
	std::cout << "main exit\n";
}

