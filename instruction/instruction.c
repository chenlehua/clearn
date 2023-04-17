#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>

#if !defined(__STC_NO_ATOMICS__)
atomic_int x = 0, y = 0;
#endif

int run(void *v) {
    x = 10;
    y = 20;
}

int observe(void *v) {
    while (y != 20);
    printf("%d", x);
}

int main(void) {
#ifndef __STDC_NO_THREADS__
    thrd_t threadA, threadB;
    thrd_create(&threadA, run, NULL);
    thrd_create(&threadB, observe, NULL);
    thrd_join(threadA, NULL);
    thrd_join(threadB, NULL);
#endif
    return 0;
}

