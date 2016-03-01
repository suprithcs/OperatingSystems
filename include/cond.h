#ifndef COND_H
#define COND_H
#include <xinu.h>
#include <mutex.h>
#include <myqueue.h>

struct cond{
	queue* cqueue;
	int16 var;
};

typedef struct cond cond_t;


extern syscall cond_init(cond_t*);

extern syscall cond_wait(cond_t*, volatile mutex_t*);
extern syscall cond_signal(cond_t*);
#endif
