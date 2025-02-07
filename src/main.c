#include <zephyr/kernel.h>
#include "thread_1.h"
#include "thread_2.h"
#include "msgq.h"

/* size of stack area used by each thread */
#define STACKSIZE 1024

/* scheduling priority used by each thread */
#define PRIORITY 7

K_THREAD_DEFINE(thread1_id, STACKSIZE, thread1_callback, NULL, NULL, NULL, PRIORITY, 0, 0);
K_THREAD_DEFINE(thread2_id, STACKSIZE, thread2_callback, NULL, NULL, NULL, PRIORITY, 0, 0);

int main()
{
    // k_tid_t thread3_id = k_thread_create(&thread3_data, thread3_stack,
    //                                      K_THREAD_STACK_SIZEOF(thread3_stack),
    //                                      thread3_callback,
    //                                      NULL, NULL, NULL,
    //                                      PRIORITY, 0, K_NO_WAIT);


    k_msgq_init(&my_msgq, my_msgq_buffer, sizeof(struct msg_t), SIZE);

}