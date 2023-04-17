#include <stdio.h>
#include <threads.h>

int run(void *arg) {
    thrd_t id = thrd_current();
    printf((const char *) arg, id);
    return thrd_success;
}

int main(void) {
#ifndef __STDC_NO_THREADS__
    thrd_t thread;
    int result;

    thrd_create(&thread, run, "Hello C11 thread with id: %lu.\n");
    if (thrd_join(thread, &result) == thrd_success) {
        printf("Thread returns %d at the end.\n", result);
    }
#endif
    return 0;
}

