#include <stddef.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct sk_buff_head {
    struct list_head head;
};

struct net_device;

struct j1939_priv {
    struct net_device *ndev;
};

struct j1939_session {
    bool transmission;
    bool err;
    struct j1939_priv *priv;
    struct list_head sk_session_queue_entry;
    struct list_head active_session_list_entry;
    struct sk_buff_head skb_queue;
};

enum {
    J1939_ERRQUEUE_TX_ABORT,
    J1939_ERRQUEUE_TX_ACK,
    J1939_ERRQUEUE_RX_ABORT
};

void j1939_sk_errqueue(struct j1939_session *session, int type);
void __j1939_session_drop(struct j1939_session *session);
void j1939_priv_put(struct j1939_priv *priv);
void skb_queue_purge(struct sk_buff_head *list);
void netdev_dbg(const struct net_device *dev, const char *fmt, ...);
bool list_empty(const struct list_head *head);
void WARN_ON_ONCE(bool condition);
void kfree(void *ptr);