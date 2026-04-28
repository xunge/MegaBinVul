#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct work_struct {
    unsigned long data;
    struct list_head entry;
    void (*func)(struct work_struct *work);
};

struct net {
    struct list_head cleanup_list;
    struct work_struct work;
};

static struct list_head cleanup_list = { &cleanup_list, &cleanup_list };
static int cleanup_list_lock;
static void *netns_wq;
static struct work_struct net_cleanup_work;

void spin_lock_irqsave(int *lock, unsigned long flags);
void spin_unlock_irqrestore(int *lock, unsigned long flags);
void list_add(struct list_head *new, struct list_head *head);
void INIT_WORK(struct work_struct *work, void (*func)(struct work_struct *));
void queue_work(void *wq, struct work_struct *work);
void cleanup_net(struct work_struct *work);