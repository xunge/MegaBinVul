#include <pthread.h>
#include <sys/time.h>

#define QUEUE_FLAG_NOMERGES 0
#define QUEUE_FLAG_NOXMERGES 1
#define QUEUE_FLAG_DYING 2
#define QUEUE_FLAG_DEAD 3

struct timer_list {
    struct timeval expires;
    void (*function)(unsigned long);
    unsigned long data;
};

struct percpu_ref {
    unsigned long count;
};

struct backing_dev_info {
    struct timer_list laptop_mode_wb_timer;
};

struct elevator_queue {
    void *ops;
};

struct request_queue {
    pthread_mutex_t sysfs_lock;
    unsigned long queue_flags;
    struct backing_dev_info *backing_dev_info;
    struct elevator_queue *elevator;
    struct percpu_ref q_usage_counter;
};

void mutex_lock(pthread_mutex_t *mutex);
void mutex_unlock(pthread_mutex_t *mutex);
int del_timer_sync(struct timer_list *timer);
void percpu_ref_exit(struct percpu_ref *ref);

void blk_set_queue_dying(struct request_queue *q);
void blk_queue_flag_set(int flag, struct request_queue *q);
void blk_freeze_queue(struct request_queue *q);
void rq_qos_exit(struct request_queue *q);
void blk_flush_integrity(void);
void blk_sync_queue(struct request_queue *q);
int queue_is_mq(struct request_queue *q);
void blk_mq_exit_queue(struct request_queue *q);
void blk_mq_sched_free_requests(struct request_queue *q);
void blk_put_queue(struct request_queue *q);