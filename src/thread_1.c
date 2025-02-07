#include "zephyr/kernel.h"
#include "thread_1.h"
#include "mutexh.h"
#include "msgq.h"


void thread1_callback(void)
{
    struct msg_t data;
	while(1) {
        //TODO: Need to change TID from printing pointer to digit
        // printf("I'm running the thread1 callback. My TID is %p, and my iter number is %d\n", k_current_get(), ++i);
        // k_msleep(100);

        struct msg_t data = {1}; 

        if (k_mutex_lock(&my_mutex, K_MSEC(100)) != 0) {
            printk("I, thread 1, am unable to access the mutex\n");
        } else {
            printk("HOrray, thread 1, got the mutex\n");
            while (k_msgq_put(&my_msgq, &data, K_NO_WAIT) != 0)
            {
                k_msgq_purge(&my_msgq);
            }
            printf("I've sent you %d\n", data.num);
            k_msleep(100);
            k_mutex_unlock(&my_mutex);
        }


	}
}
