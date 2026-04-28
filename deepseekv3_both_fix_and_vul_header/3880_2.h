#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

static inline void list_del_init(struct list_head *entry)
{
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
    INIT_LIST_HEAD(entry);
}

struct bus_type;
struct gendisk {
    void *queue;
};
struct rbd_device {
    int dev_id;
    struct list_head node;
    int lock;
    unsigned long flags;
    int open_count;
    struct gendisk *disk;
    void *dev;
};

static int rbd_dev_list_lock;
static LIST_HEAD(rbd_dev_list);
#define RBD_DEV_FLAG_REMOVING 0

#define spin_lock(lock) (void)0
#define spin_unlock(lock) (void)0
#define spin_lock_irq(lock) (void)0
#define spin_unlock_irq(lock) (void)0
#define test_and_set_bit(nr, addr) (0)
#define capable(cap) (1)
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

#define EPERM 1
#define EINVAL 2
#define ENOENT 3
#define EBUSY 4
#define EINPROGRESS 5

void blk_mq_freeze_queue(void *queue);
void blk_set_queue_dying(void *queue);
void del_gendisk(struct gendisk *disk);
void device_del(void *dev);
void rbd_dev_image_unlock(struct rbd_device *rbd_dev);
void rbd_dev_device_release(struct rbd_device *rbd_dev);
void rbd_dev_image_release(struct rbd_device *rbd_dev);
void rbd_dev_destroy(struct rbd_device *rbd_dev);