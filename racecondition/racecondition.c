#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <time.h>

#define THREAD_COUNT 10

atomic_int accountA = 100000000;
atomic_int accountB = 0;

int run(void *v) {
    int _amount = *((int *) v);
    for (;;) {
        if (accountA < _amount) return thrd_error;
        atomic_fetch_add(&accountB, _amount);
        atomic_fetch_sub(&accountA, _amount);
    }
}

int main(void) {
#ifndef __STDC_NO_THREADS__
    int ids[THREAD_COUNT];
    thrd_t threads[THREAD_COUNT];
    srand(time(NULL));
    for (int i = 0; i < THREAD_COUNT; i++) {
        int amount = rand() % 50;
        thrd_create(&threads[i], run, &amount);
    }

    for (int i = 0; i < THREAD_COUNT; i++)
        thrd_join(threads[i], NULL);
    printf("A: %d\nB: %d", accountA, accountB);

#endif
    return 0;
}

