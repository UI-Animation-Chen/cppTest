#include<iostream>
#include<unistd.h>
#include<pthread.h>

void * run(void *arg) {
    char *tname;
    tname = (char *)arg;
    //std::cout << "tname:" << tname << ".\n";
    long tid_real;
    tid_real = pthread_self();
    std::cout << "tid:" << tid_real << ".\n";
    return NULL;
}

int main() {
    int i = 7;
    auto fn = [=]() mutable ->void {i = 777;std::cout << "i in: " << i << ".\n";};
    fn();
    std::cout << "i out: " << i << ".\n";
    signed char sch; //-128~127
    unsigned char uch; //0～255
    char ch = 48; //unkown, one or another
    std::cout << "ch: " << ch << ".\n";
    std::cout << "char size:" << sizeof(char) << ".\n";
    pthread_t pthreads[3];
    for (int i = 0; i < 3; i++) {
        char str[] = "new thread";
        pthread_create(&pthreads[i], NULL, run, (void *)str);
        //pthread_join(pthreads[i], NULL);

        /* pthreads[i] == pthread_self() */
        std::cout << "pthread_t: " << pthreads[i] << ".\n";
    }
    sleep(1);
    std::cout << "main exit\n";
}

