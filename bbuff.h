#ifndef BBUF_H

#define BBUF_H


#define BUFFER_SIZE 10

typedef struct {
	int factory_number;
	double time_stamp_in_ms;
}candy_t;

void wait_empty(void);

void wait_full(void);

void signal_empty(void);

void signal_full(void);

void bbuff_init(void);

void bbuff_blocking_insert(void* item);

void* bbuff_blocking_extract(void);

_Bool bbuff_is_empty(void);

void bbuff_print(void);

#endif
