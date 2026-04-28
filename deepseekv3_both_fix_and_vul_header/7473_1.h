#include <stddef.h>

#define NCI_UNREG 0

struct list_head {
    struct list_head *next, *prev;
};

struct nci_dev;
struct nci_conn_info;
struct nfc_dev;
struct workqueue_struct;

struct nci_dev {
    unsigned long flags;
    struct workqueue_struct *cmd_wq;
    struct workqueue_struct *rx_wq;
    struct workqueue_struct *tx_wq;
    struct list_head conn_info_list;
    struct nfc_dev *nfc_dev;
};

struct nci_conn_info {
    struct list_head list;
};

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (head); pos = n)

static inline void list_del(struct list_head *entry) {
    (void)entry;
}

void nci_close_device(struct nci_dev *ndev);
void nfc_unregister_device(struct nfc_dev *nfc_dev);
void destroy_workqueue(struct workqueue_struct *wq);
void set_bit(int nr, volatile unsigned long *addr);