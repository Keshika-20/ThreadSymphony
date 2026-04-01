#include "usf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREADS 64

static usf_thread threads[MAX_THREADS];
static int num_threads = 0;
static int mode = 0; // 0 = cooperative, 1 = round-robin

void usf_init(int sched_mode) {
    mode = sched_mode;
    num_threads = 0;
    printf("[USF] Initialized, mode=%s\n", mode==0?"SCHED_COOP":"Round-Robin");
}

void usf_register(pthread_t tid, int id) {
    threads[id].tid = tid;
    threads[id].id = id;
    threads[id].active = 1;
    threads[id].blocked = 0;
    num_threads++;
}

void usf_block(int id) {
    threads[id].blocked = 1;
    printf("[USF] Thread %d blocked\n", id);
}

void usf_unblock(int id) {
    threads[id].blocked = 0;
    printf("[USF] Thread %d unblocked\n", id);
}

void usf_run() {
    for(int i=0; i<num_threads; i++) {
        if(threads[i].active && !threads[i].blocked) {
            if(mode==1) {
                sched_yield(); // round-robin preemption
            }
            // cooperative: threads yield voluntarily
        }
    }
}

void usf_cleanup() {
    printf("[USF] Cleanup complete.\n");
}
