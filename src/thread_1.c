#include "zephyr/kernel.h"
#include "semh.h"
#include "thread_1.h"
#include "msgq.h"


void thread1_callback(void)
{
    struct msg_t data;
	while(1) {
        //TODO: Need to change TID from printing pointer to digit
        // printf("I'm running the thread1 callback. My TID is %p, and my iter number is %d\n", k_current_get(), ++i);
        // k_msleep(100);

        struct msg_t data = {1}; 

        if (k_sem_take(&my_sem, K_MSEC(50)) != 0){
            printk("Input data not available!");
        } else {
            printk("Was able to obtain semaphore (I am here)");
            while (k_msgq_put(&my_msgq, &data, K_NO_WAIT) != 0)
            {
                k_msgq_purge(&my_msgq);
            }
            printf("I've sent you %d\n", data.num);
            k_msleep(100);
        }


	}
}

