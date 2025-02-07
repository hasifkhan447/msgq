#include "msgq.h"

char __aligned(4) my_msgq_buffer[SIZE * sizeof(struct msg_t)];

struct k_msgq my_msgq;

