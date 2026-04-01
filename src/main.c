#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "scheduler.h"
#include "workload.h"
#include "metrics.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <num_threads> <mode>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    int mode = atoi(argv[2]);

    clock_t start = clock();

    // Create workload
    create_workload(num_threads);

    // Wait for all threads
    join_all_threads();

    clock_t end = clock();
    double exec_time = (double)(end - start) / CLOCKS_PER_SEC;

    print_metrics(exec_time, num_threads, mode);

    cleanup_scheduler();
    return 0;
}
