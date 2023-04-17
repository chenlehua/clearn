#include <stdio.h>
#include <threads.h>

#define THREAD_COUNT 20
#define THREAD_LOOP 100000000

long counter = 0;


int run(void *data) {
    for (int i = 0; i < THREAD_LOOP; i++)
        counter++;
    printf("Thread %d terminates.\n", *((int *) data));
    return thrd_success;
}

int main(void) {
#ifndef __STDC_NO_THREADS__
    int ids[THREAD_COUNT];
    thrd_t threads[THREAD_COUNT];
    for (int i =0;i<THREAD_COUNT;i++){
        ids[i]=i+1;
        thrd_create(&threads[i],run,ids+i);
    }

    for(int i=0;i<THREAD_COUNT;i++)
        thrd_join(threads[i],NULL);
    printf("Counter value is: %d.\n",counter);

#endif
    return 0;
}

