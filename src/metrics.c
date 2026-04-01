#include <stdio.h>
#include <time.h>
#include "metrics.h"

static clock_t start_time;
static int tasks_completed = 0;

void start_timer() { start_time = clock(); }
void record_task() { tasks_completed++; }

void print_metrics() {
    clock_t end_time = clock();
    double exec_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double throughput =(double) tasks_completed / exec_time;

    printf("\n=== Performance Metrics ===\n");
    printf("Execution Time: %.4f seconds\n", exec_time);
    printf("Tasks Completed: %d\n", tasks_completed);
    printf("Throughput: %.2f tasks/sec\n", throughput);
}
