
#include<baby_bird.h>



void babyBirdProcess(int babyId){	
	volatile int myshare = eat_share;
	//int status = 0;	
	while(myshare > 0){
		
		mutex_lock(&baby_mutex); //do nothing, wait for the lock to be false
		
		//wait here if worms are less than or equal to zero
		if(worms <= 0)
			cond_wait(cond_worms, &baby_mutex);
		
	
		if(worms > 0){		
			worms--;
			myshare--;
			printf("Baby bird %d ate a worm, worm count: %d\n", babyId, worms);
		
			if(myshare > 0 && worms <= 0){
			//		printf("signalling by baby bird %d\n", babyId);
					cond_signal(cond_empty);
			
			}
		}
		if(worms <= 0){
			//		printf("signalling by baby bird %d\n", babyId);
					cond_signal(cond_empty);
			
		}
		mutex_unlock(&baby_mutex); //release lock
		
	}
	
	done = done >> 1;
	
	
}

