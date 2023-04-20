#include <stdio.h>
#include <threads.h>

int run(void *arg) {
    thrd_t id = thrd_current();
    printf((const char *) arg, id);
    return thrd_success;
}

int thread_proc(void *arg) {
    unsigned cnt = 5;
    struct timespec interv = {1, 0};

    thrd_t id = thrd_current();

    while (cnt--) {
        printf("%lu-%s\n", id, (char *) arg);
        thrd_sleep(&interv, 0);
    }
    return 0;
}

int main(void) {
#ifndef __STDC_NO_THREADS__
    thrd_t t0, t1;

    thrd_create(&t0, thread_proc, "A");
    thrd_create(&t1, thread_proc, "b");

    thrd_detach(t0);
    thrd_detach(t1);

    printf("+\n");
    thrd_sleep(&(struct timespec) {1, 500000000}, 0);
    printf("+\n");
    thrd_exit(0);
#endif
    return 0;
}

