#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>
#include "stats.h"

//gcc -std=gnu99 -o0 candykids.c stats.c -o candykids -lrt

// void* candyFactory(void* factoryNum){
// 	int factory_num = *factoryNum;

// 	while(1){
// 		candy_t *candy = molloc(sizeof(candy_t));
// 		candy->factory_number = factory_num;
// 		candy->time_stamp_in_ms
// 	}
// }

typedef struct Candy{
	int factory_num;
	double time_stamp_in_ms;
}Candy;

int main(int argc, char *argv[]){
	int factories, kids, seconds;
	// Candy candy;
	// candy.factory_num = 0;
	//1.Extract Arguments

	//check if the argument meets the requirements
	if(argc == 4){
		for(int i = 1; i < argc; i++){
			if(atoi(argv[i]) < 0) {
				printf("input is smaller than 0\n");
				exit(0);
			}
		}

		//assign each variable with cmd arguments
		factories = atoi(argv[1]);
    	kids = atoi(argv[2]);
    	seconds = atoi(argv[3]);

		printf("factories : %d \n", factories);
	    printf("kids : %d \n", kids);
	    printf("seconds : %d \n", seconds);
	}

	else{
		printf("Invaild arguments\n");
		exit(0);
	}
  
	//pthread_t factoriesArr[factories];

	//init factories arrays.
	stats_init(factories);
	struct timespec start_time, end_time;

	//Add 3 candies to factory #0
	for(int i = 0; i < 3; i++){
		stats_record_produced(0);
		//testing only
		
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
		printf("factory #0: %f\n",timespec_to_ms(&start_time));
		//timespec_to_ms(&start_time) should be replaced with candy->stamptime
		stats_record_consumed(0,timespec_to_ms(&start_time));
	}
	

	//Add 2 candies to factory #1
	for(int i = 0; i < 2; i++){
		stats_record_produced(1);
		//testing only
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
		//timespec_to_ms(&start_time) should be replaced with candy->stamptime
		stats_record_consumed(1,timespec_to_ms(&start_time));
	}

	//Add 1 candies to factory #2
	stats_record_produced(2);
	//testing only
 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
 	//timespec_to_ms(&start_time) should be replaced with candy->stamptime
	stats_record_consumed(2,timespec_to_ms(&start_time));


	
 // 	/* begin timing */

 // 	 end timing 
 // 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);

 // 	printf("%f ms\n", timespec_to_ms(&end_time) - timespec_to_ms(&start_time));

 	stats_display();

 	stats_cleanup();

	return 0;

}