#include "zephyr/kernel.h"
#include "thread_2.h"
#include "msgq.h"

void thread2_callback(void)
{
    struct msg_t data;
    while (1)
    {
        k_msgq_get(&my_msgq, &data, K_FOREVER);
        printf("I recieved %d\n", data.num);
        k_msleep(100);
    }
}
