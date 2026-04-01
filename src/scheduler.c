#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include "scheduler.h"

#define MAX_THREADS 128
static pthread_t threads[MAX_THREADS];
static int thread_count = 0;

// Wrapper so pthreads can call tasks with int argument
static void *thread_wrapper(void *arg) {
    void (**func_and_id)(int) = arg;
    void (*task)(int) = func_and_id[0];
    int id = (int)(intptr_t)func_and_id[1];
    free(func_and_id);

    task(id);
    return NULL;
}

// Add a new thread running the given task
void add_thread(void (*task)(int), int id) {
    if (thread_count >= MAX_THREADS) {
        fprintf(stderr, "Too many threads!\n");
        return;
    }

    void (**func_and_id)(int) = malloc(2 * sizeof(void *));
    func_and_id[0] = (void (*)(int))task;
    func_and_id[1] = (void (*)(int))(intptr_t)id;

    pthread_create(&threads[thread_count], NULL, thread_wrapper, func_and_id);
    thread_count++;
}

// Wait for all threads to finish
void join_all_threads() {
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
    thread_count = 0;
}

// Cooperative yield
void yield_cpu() {
    sched_yield();
}

// Cleanup scheduler state
void cleanup_scheduler() {
    thread_count = 0;
}
