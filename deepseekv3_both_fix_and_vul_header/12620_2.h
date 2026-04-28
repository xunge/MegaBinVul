#include <stddef.h>

struct request_queue {
    void *elevator;
    void *backing_dev_info;
};

struct elevator_queue;

void ioc_clear_queue(struct request_queue *q);
void elevator_exit(struct request_queue *q, struct elevator_queue *e);
void blkcg_exit_queue(struct request_queue *q);
void bdi_put(void *bdi);