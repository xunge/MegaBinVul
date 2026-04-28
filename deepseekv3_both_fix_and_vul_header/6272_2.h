#include <stdatomic.h>
#include <pthread.h>

struct hci_dev {
    char *name;
    int id;
};

struct sk_buff {
    // minimal definition
};

struct sock {
    int sk_err;
    int sk_state;
    void (*sk_state_change)(struct sock *sk);
    struct sock *next;
};

struct hci_ev_si_device {
    int event;
    int dev_id;
};

struct hci_sk_list {
    pthread_rwlock_t lock;
    struct sock *head;
};

struct hci_pi {
    struct hci_dev *hdev;
};

extern struct hci_sk_list hci_sk_list;
extern atomic_int monitor_promisc;

#define BT_OPEN 0
#define EPIPE 32
#define HCI_CHANNEL_MONITOR 0
#define HCI_SOCK_TRUSTED 0
#define HCI_DEV_DOWN 0
#define HCI_DEV_UNREG 0
#define HCI_EV_SI_DEVICE 0

#define BT_DBG(fmt, ...) 
#define atomic_read(v) atomic_load_explicit(v, memory_order_relaxed)
#define bh_lock_sock_nested(sk) 
#define bh_unlock_sock(sk) 
#define hci_dev_put(dev) 
#define hci_pi(sk) ((struct hci_pi *)(sk))
#define hci_send_to_channel(ch, skb, flags, sock) 
#define hci_si_event(sk, ev, len, ptr) 
#define kfree_skb(skb) 
#define read_lock(lock) pthread_rwlock_rdlock(lock)
#define read_unlock(lock) pthread_rwlock_unlock(lock)
#define sk_for_each(sk, head) for ((sk) = (head); (sk) != NULL; (sk) = (sk)->next)

struct sk_buff *create_monitor_event(struct hci_dev *hdev, int event);