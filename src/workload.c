#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include "workload.h"
#include "scheduler.h"
#include "metrics.h"

// CPU-bound task
void cpu_task(int id) {
    int primes_found = 0;
    for (int num = 2; num < 500000; num++) {
        int is_prime = 1;
        for (int div = 2; div <= sqrt(num); div++) {
            if (num % div == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) primes_found++;
    }
    printf("[Thread %d] Finished CPU task, primes=%d\n", id, primes_found);

    record_task();
    yield_cpu();
}

// I/O-like task
void io_task(int id) {
    for (int i = 0; i < 20; i++) {
        usleep(200000); // 200ms sleep
    }
    printf("[Thread %d] Finished I/O task\n", id);

    record_task();
    yield_cpu();
}

// Workload creator
void create_workload(int num_threads) {
    for (int i = 0; i < num_threads; i++) {
        if (i % 2 == 0) {
            add_thread(cpu_task, i);
        } else {
            add_thread(io_task, i);
        }
    }
}
