
#include<baby_bird.h>



void parentBirdProcess(){	
		
	while(done != 1){	
		mutex_lock(&mutex);
		//wait here for the signal
		if(worms > 0)
			cond_wait(cond_empty, &mutex);
		
		if(worms <= 0 && done != 1){
			worms = global_worms;
			printf("Parent bird filled the dish with %d worms\n", global_worms);
			cond_signal(cond_worms);
		}
		mutex_unlock(&mutex);
	}
}

