#include "zephyr/kernel.h"
#include "thread_2.h"
#include "mutexh.h"
#include "msgq.h"

void thread2_callback(void)
{
    struct msg_t data;
    while (1)
    {

        if (k_mutex_lock(&my_mutex, K_FOREVER) != 0) {
            printk("I, thread 2, am unable to get the mutex\n");
        } else {
            printk("I, thread 2, got the mutex\n");
            k_msgq_get(&my_msgq, &data, K_FOREVER);
            printf("I recieved %d\n", data.num);
            k_msleep(100);
            k_mutex_unlock(&my_mutex);

        }
    }
}
