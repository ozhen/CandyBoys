#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>
#include <semaphore.h>
#include <math.h>

#include "bbuff.h"

//gcc -std=gnu99 -o0 candykids.c stats.c -o candykids -lrt

// void* candyFactory(void* factoryNum){
// 	int factory_num = *factoryNum;

// 	while(1){
// 		candy_t *candy = molloc(sizeof(candy_t));
// 		candy->factory_number = factory_num;
// 		candy->time_stamp_in_ms
// 	}
// }


int main(int argc, char *argv[]){
	int factories, kids, seconds;
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
	}
  

//   /* Check without threads */
// 	bbuff_init();

// 	candy_t candy1;
// 	candy1.factory_number =420;
// 	candy1.time_stamp_in_ms = 42.0;

// 	candy_t candy2;
// 	candy2.factory_number =421;
// 	candy2.time_stamp_in_ms = 42.1;

// 	candy_t candy3;
// 	candy3.factory_number =422;
// 	candy3.time_stamp_in_ms = 42.2;

// 	candy_t candy4;
// 	candy4.factory_number =423;
// 	candy4.time_stamp_in_ms = 42.3;

// 	candy_t candy5;
// 	candy5.factory_number =424;
// 	candy5.time_stamp_in_ms = 42.4;

// 	candy_t candy6;
// 	candy6.factory_number =425;
// 	candy6.time_stamp_in_ms = 42.5;

// 	candy_t candy7;
// 	candy7.factory_number =426;
// 	candy7.time_stamp_in_ms = 42.6;

// 	candy_t candy8;
// 	candy8.factory_number =427;
// 	candy8.time_stamp_in_ms = 42.7;

// 	candy_t candy9;
// 	candy9.factory_number =428;
// 	candy9.time_stamp_in_ms = 42.8;

// 	candy_t candy10;
// 	candy10.factory_number =429;
// 	candy10.time_stamp_in_ms = 42.9;

// 	candy_t candy11;
// 	candy11.factory_number =430;
// 	candy11.time_stamp_in_ms = 43.0;


// 	bbuff_blocking_insert(&candy1);
// 	printf(" called insert\n");
// 	_Bool apple1 = bbuff_is_empty();
// 	printf("%d \n", apple1);
// 	bbuff_print();
// 	printf(" called print\n");
	
// 	candy_t* candyx1 = bbuff_blocking_extract();
// 	printf(" called Extract\n");
// 	printf(" factory_number retrieved= %d\n", candyx1->factory_number);
// 	printf(" time_stamp_in_ms retrieved= %f\n", candyx1->time_stamp_in_ms);
// 	_Bool apple2 = bbuff_is_empty();
// 	printf("%d \n", apple2);
// 	bbuff_print();
// 	printf(" called print\n");
// 	candy_t* candyx2 = bbuff_blocking_extract();
// 	// printf(" factory_number retrieved= %d\n", candyx2->factory_number);
// 	// printf(" time_stamp_in_ms retrieved= %f\n", candyx2->time_stamp_in_ms);
// 	apple2 = bbuff_is_empty();
// 	printf("%d \n", apple2);
// 	bbuff_print();



// 		bbuff_blocking_insert(&candy1);
// 	printf(" called insert\n");
// 		bbuff_blocking_insert(&candy2);
// 	printf(" called insert\n");
// 		bbuff_blocking_insert(&candy3);
// 	printf(" called insert\n");
// 		bbuff_blocking_insert(&candy4);
// 	printf(" called insert\n");
// 		bbuff_blocking_insert(&candy5);
// 	printf(" called insert\n");
// 		bbuff_blocking_insert(&candy6);
// 	printf(" called insert\n");
// 		bbuff_blocking_insert(&candy7);
// 	printf(" called insert\n");
// 		bbuff_blocking_insert(&candy8);
// 	printf(" called insert\n");
// 		bbuff_blocking_insert(&candy9);
// 	printf(" called insert \n");
// 		bbuff_blocking_insert(&candy10);
// 	printf(" called insert\n");
// 		bbuff_blocking_insert(&candy11);
// 	printf(" called insert\n");



// /* Check with treads */









	//pthread_t factoriesArr[factories];

	//init factories arrays.
	// stats_init(factories);
	// stats_record_produced(1);

	// struct timespec start_time, end_time;
 // 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
 // 	/* begin timing */

 // 	 end timing 
 // 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);

 // 	printf("%f ms\n", timespec_to_ms(&end_time) - timespec_to_ms(&start_time));

 	// stats_display();

 	// stats_cleanup();


	return 0;


	
}