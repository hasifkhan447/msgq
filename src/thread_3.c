#include "zephyr/kernel.h"
#include "thread_3.h"


void thread3_callback(void)
{
    int i = 0;
	while(1) {
        //TODO: Need to change TID from printing pointer to digit
        printf("I'm running the thread3 callback. My TID is %p, and my iter number is %d\n", k_current_get(), ++i);
        k_msleep(100);

	}
}
