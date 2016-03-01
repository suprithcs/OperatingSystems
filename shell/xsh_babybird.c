// **xsh_hello.c**

/*
Operating Systems - Assignment 3

Authors:
Suprith Chandrashekharachar(suprchan),
Dakshi Kumar(dakumar)

Description:
Program to simulate baby bird synchronization experiment.

*/

#include<baby_bird.h>

cond_t* cond_worms;
cond_t* cond_empty;	
volatile int worms;
volatile int babyBirds;
volatile mutex_t baby_mutex;
volatile mutex_t parent_mutex;
volatile int parent_itr;

shellcmd xsh_babybird(int nargs, char* args[]){
	
	
	if(nargs > 3){
		fprintf(stderr, "%s: too many arguments\n", args[0]);
	}
	else if(nargs < 3){
		fprintf(stderr, "%s: usage example\n", args[0]);
	}
	else if(nargs == 3){
		babyBirds = atoi(args[1]);
		worms = atoi(args[2]);
		baby_mutex = 0;
		parent_mutex = 0;
		parent_itr = 3;
		//mutex_create(&baby_mutex);
		//mutex_create(&parent_mutex);
		/*cond_t * temp = (cond_t *) getmem(sizeof(cond_t));
		if(temp != NULL){
			cond_init(temp);
			printf("temp->first:%d", temp->cqueue->first);
			printf("temp->last:%d", temp->cqueue->last);
			que_enque(temp->cqueue, 1);
			que_enque(temp->cqueue, 2);
			que_enque(temp->cqueue, 3);
			que_enque(temp->cqueue, 4);
			que_enque(temp->cqueue, 5);
			printf("que item: %d", que_deque(temp->cqueue));
			printf("que item: %d", que_deque(temp->cqueue));
			printf("que item: %d", que_deque(temp->cqueue));
		}
		*/	
						
		cond_worms = (cond_t *) getmem(sizeof(cond_t));
		cond_init(cond_worms);
		cond_empty = (cond_t *) getmem(sizeof(cond_t));
		cond_init(cond_empty);
		int i;
		
		pid32 pid = create(parentBirdProcess, 1024, 20, "parentbird", 0);
		resume(pid);		
		for(i=0; i < babyBirds; i++){
			//printf("Creating baby bird: %d", i);
			resume(create(babyBirdProcess, 1024, 20, "babybird", 1 , i));
		}


	}
	
}

