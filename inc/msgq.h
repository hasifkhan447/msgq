#ifndef MY_MSGQ
#define MY_MSGQ

#include <zephyr/kernel.h>


#define SIZE 10

struct msg_t {
    int num;
}; 

extern struct k_msgq my_msgq;
extern char my_msgq_buffer[SIZE * sizeof(struct msg_t)];


#endif