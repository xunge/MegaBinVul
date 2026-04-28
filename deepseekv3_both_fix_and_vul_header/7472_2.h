#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#define NCI_UP 0
#define NCI_INIT 1
#define NCI_UNREG 2
#define NCI_RESET_TIMEOUT 1000
#define ENODEV 19

typedef struct {
    int dummy;
} mutex_t;

typedef struct {
    int dummy;
} timer_list;

typedef struct {
    int dummy;
} workqueue_struct;

typedef struct {
    int dummy;
} sk_buff_head;

struct nci_dev {
    unsigned long flags;
    mutex_t req_lock;
    timer_list cmd_timer;
    timer_list data_timer;
    sk_buff_head rx_q;
    sk_buff_head tx_q;
    sk_buff_head cmd_q;
    workqueue_struct *rx_wq;
    workqueue_struct *tx_wq;
    workqueue_struct *cmd_wq;
    atomic_int cmd_cnt;
    struct nci_ops *ops;
};

struct nci_ops {
    void (*close)(struct nci_dev *ndev);
};

void nci_req_cancel(struct nci_dev *ndev, int err);
void __nci_request(struct nci_dev *ndev, void *req, void *arg, unsigned long timeout);
void nci_reset_req(struct nci_dev *ndev, void *arg);
void mutex_lock(mutex_t *lock);
void mutex_unlock(mutex_t *lock);
bool test_and_clear_bit(int nr, unsigned long *addr);
void set_bit(int nr, unsigned long *addr);
void clear_bit(int nr, unsigned long *addr);
void del_timer_sync(timer_list *timer);
void skb_queue_purge(sk_buff_head *list);
void flush_workqueue(workqueue_struct *wq);
unsigned long msecs_to_jiffies(unsigned int msecs);
void atomic_set(atomic_int *v, int i);