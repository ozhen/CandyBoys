#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>

#include "bbuff.h"

#define BBUFF_SIZE 10


pthread_mutex_t mutexarr;
sem_t haveData;
sem_t haveSpace;

int in_index =0;
int out_index =0;
int empty = 10;
int full = 0;
void** bbuff;

void wait_empty(void){
	while(1){
		if(empty > 0){
			sem_wait(&haveData);
		}
	}
}

void wait_full(void){
	while(1){
		if(full < 10 ){
			sem_wait(&haveSpace);
		}
	}
}

void signal_empty(void){
	sem_post(&haveData);
	empty--;
	full++;
}

void signal_full(void){
	sem_post(&haveSpace);
	empty++;
	full--;
}

void bbuff_init(void){

// initialize the two semaphores we need
sem_init(&haveData, 0, 1);
sem_init(&haveSpace, 0, 1);
bbuff = (void**) malloc (BBUFF_SIZE * sizeof(void*));

// initialize an array of void pointers dynamically


}

void bbuff_blocking_insert(void* item){
	wait_empty();
	pthread_mutex_lock(&mutexarr);

	// // without threads
	// if(full > 9){
	// 	printf("is full, cannot insert \n");
	// 	return;
	// }

	bbuff[in_index] = item;
	if(in_index == 9){
		in_index = 0;
	}
	else{
		in_index++;
	}
	// //without threads
	// full++;
	// empty--;
	pthread_mutex_unlock(&mutexarr);
	signal_empty();

}
// void* functions can return the address of item
void* bbuff_blocking_extract(void){

	//with threads
	wait_full();
	pthread_mutex_lock(&mutexarr);
	void* temp = bbuff[out_index];
	if(out_index == 9){
		out_index = 0;
	}
	else{
		out_index++;
	}
	pthread_mutex_unlock(&mutexarr);
	signal_full();
	return temp;
		
// // testing without threads
// 	if(empty > 9){
// 		printf("is empty, cannot extract \n");
// 		return 0;
// 	}
// 	else{
// 		// wait_full();
// 		// pthread_mutex_lock(&mutexarr);
// 		void* temp = bbuff[out_index];
// 		if(out_index == 9){
// 			out_index = 0;
// 		}
// 		else{
// 			out_index++;
// 		}
// 		//without threads
// 		full--;
// 		empty++;
// 		// pthread_mutex_unlock(&mutexarr);
// 		// signal_full();
// 		return temp;
// 	}
}

_Bool bbuff_is_empty(void){
	if(empty==10){
		return true;
	}
	else{
		return false;
	}
}


void bbuff_print(void){
	int checkexists = full;
	int startindex = out_index;
	while (checkexists > 0){

	candy_t* tempcandy = bbuff[startindex];
	int number1 = tempcandy->factory_number;
	double timestamp1 = tempcandy->time_stamp_in_ms;
	printf(" factory_number = %d\n", number1);
	printf(" time_stamp_in_ms = %f\n", timestamp1);
	if(startindex == 9){
		startindex = 0;
		}
	checkexists--;
	}
}