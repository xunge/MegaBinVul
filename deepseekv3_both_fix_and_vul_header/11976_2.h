#include <stddef.h>

struct sk_buff {
    // minimal sk_buff definition
};

struct list_head {
    struct list_head *next, *prev;
};

struct Qdisc_ops {
    struct sk_buff* (*peek)(void*);
};

struct qdisc_queue {
    unsigned int qlen;
};

struct Qdisc {
    struct qdisc_queue q;
    struct Qdisc_ops *ops;
};

struct qfq_class {
    struct list_head alist;
    struct Qdisc *qdisc;
    int deficit;
};

struct qfq_aggregate {
    unsigned int lmax;
    struct list_head active;
};

static inline void list_del(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}

static inline void list_move_tail(struct list_head *list, struct list_head *head) {
    list_del(list);
    list->next = head;
    list->prev = head->prev;
    head->prev->next = list;
    head->prev = list;
}

static inline unsigned int qdisc_pkt_len(const struct sk_buff *skb) {
    return 0; // dummy implementation
}

static inline struct sk_buff *qdisc_dequeue_peeked(struct Qdisc *q) {
    return NULL; // dummy implementation
}