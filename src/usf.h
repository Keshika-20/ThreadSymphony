#ifndef USF_H
#define USF_H

#include <pthread.h>

typedef struct {
    pthread_t tid;
    int id;
    int active;
    int blocked;
} usf_thread;

void usf_init(int mode);
void usf_register(pthread_t tid, int id);
void usf_block(int id);
void usf_unblock(int id);
void usf_run();
void usf_cleanup();

#endif
