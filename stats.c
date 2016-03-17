#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>

#include "stats.h"

int *numFactories, *numMade, *numEaten;
double *minDelay, *avgDelay, *maxDelay, *totalDelay;
struct timespec start_time, end_time;

//for the loop in display function
int num_factories;

double timespec_to_ms(struct timespec *ts){
	return ts->tv_sec*1000.0 + ts->tv_nsec/1000000.0;
}

void stats_init(int num_producers){
	//factory array
	numFactories = malloc(sizeof(int)*num_producers);
	// for (int i = 0; i < num_producers; i++){
	// 	numFactories[i] = i;
	// 	printf("Facotry # %d is created from stats.c\n", i);
	// }

	numMade = malloc(sizeof(int)*num_producers);

	numEaten = malloc(sizeof(int)*num_producers);
	
	minDelay = malloc(sizeof(double)*num_producers);
	
	avgDelay = malloc(sizeof(double)*num_producers);
	
	maxDelay = malloc(sizeof(double)*num_producers);
	
	totalDelay = malloc(sizeof(double)*num_producers);
	
	num_factories = num_producers;

}


void stats_record_produced(int factory_number){

	numMade[factory_number]++;

	/* begin timing */
 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
 	double tempTime = timespec_to_ms(&start_time);
 	avgDelay[factory_number] = tempTime;
 	printf("Candy created at: %f ms\n", tempTime);
 	

 	

 	//checking if the timing works
 	// printf("Start time from stats.c: %f ms\n", timespec_to_ms(&start_time));
 	// printf("End time from stats.c: %f ms\n", timespec_to_ms(&end_time));
 	// printf("%f ms\n", timespec_to_ms(&end_time) - timespec_to_ms(&start_time));

}

void stats_record_consumed(int factory_number, double delay_in_ms){
	//when a kid consumes a candy
	numEaten[factory_number]++;

	/* end timing */
 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
 	double totalTime = timespec_to_ms(&end_time) - delay_in_ms;

 	totalDelay[factory_number] = totalTime;

 	//check min delay
 	if(totalTime < minDelay[factory_number]){
 		minDelay[factory_number] = totalTime;
 	}

 	//check max delay
 	else if (totalTime > maxDelay[factory_number]){
 		maxDelay[factory_number] = totalTime;
 	
 	}

}

void stats_display(void){

	int made = 0;
	int eaten = 0;
	//compare the #Made column and #Eaten column

	printf("From stats.c\n");
	printf("%8s%10s%10s%20s%20s%20s%20s\n","Factory # ", "#Made:","#Eaten", 
					"Min Delay[ms]", "Avg Delay[ms]", "Max Delay[ms]", "total Delay[ms]");

	for(int i = 0; i < num_factories; i ++){

		if(numMade[i] == numEaten[i]){
			printf("%8d%10d%10d%20f%20f%20f%20f\n", i, numMade[i],numEaten[i], 
				minDelay[i], avgDelay[i], maxDelay[i], totalDelay[i]);
		}
	
		//else print the error message
		else{
			printf("“ERROR: Mismatch between number made and eaten.\n");
			break;
		}
	}

	
}

void stats_cleanup(){
	
	free(numFactories);
	//printf("numFactories is freed!\n");

	free(numMade);
	//printf("numMade is freed!\n");

	free(numEaten);
	//printf("numEaten is freed!\n");

	free(minDelay);
	//printf("minDelay is freed!\n");

	free(avgDelay);
	//printf("avgDelay is freed!\n");

	free(maxDelay);
	//printf("maxDelay is freed!\n");

	free(totalDelay);
	//printf("totalDelay is freed!\n");
	
}