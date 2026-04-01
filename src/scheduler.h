#ifndef SCHEDULER_H
#define SCHEDULER_H

void add_thread(void (*task)(int), int id);
void join_all_threads();
void yield_cpu();
void cleanup_scheduler();

#endif
