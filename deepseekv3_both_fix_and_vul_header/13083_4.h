#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint16_t u16;

#define TIPC_SYSTEM_IMPORTANCE 0
#define GFP_ATOMIC 0
#define unlikely(x) (x)
#define likely(x) (x)
#define pr_warn printf
#define EMSGSIZE 1
#define ENOBUFS 2
#define link_rst_msg "Link reset"

struct sk_buff {
    struct sk_buff *next;
    struct sk_buff *prev;
    void *data;
    struct TIPC_SKB_CB *cb;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    unsigned int qlen;
};

struct tipc_msg {
    unsigned int importance;
    unsigned int size;
    unsigned int user;
    unsigned int type;
    u16 seqno;
    u16 ack;
    u16 bcast_ack;
};

struct tipc_link {
    struct sk_buff_head backlogq;
    struct sk_buff_head transmq;
    struct {
        struct sk_buff *target_bskb;
        int len;
        int limit;
    } backlog[4];
    struct {
        unsigned long sent_pkts;
        unsigned long sent_fragmented;
        unsigned long sent_fragments;
        unsigned long sent_bundles;
        unsigned long sent_bundled;
    } stats;
    u16 rcv_nxt;
    u16 snd_nxt;
    u16 window;
    unsigned int mtu;
    unsigned int ackers;
    unsigned int rcv_unacked;
    struct tipc_link *bc_rcvlink;
    char *name;
    int addr;
};

struct TIPC_SKB_CB {
    unsigned int ackers;
};

static inline struct tipc_msg *buf_msg(struct sk_buff *skb) { return (struct tipc_msg *)skb->data; }
static inline struct sk_buff *skb_peek(struct sk_buff_head *list) { return list->next; }
static inline int skb_queue_len(struct sk_buff_head *list) { return list->qlen; }
static inline struct sk_buff *__skb_dequeue(struct sk_buff_head *list) {
    struct sk_buff *skb = list->next;
    if (skb) {
        list->next = skb->next;
        if (list->next) list->next->prev = (struct sk_buff *)list;
        list->qlen--;
    }
    return skb;
}
static inline void __skb_queue_tail(struct sk_buff_head *list, struct sk_buff *skb) {
    skb->next = NULL;
    skb->prev = list->prev;
    if (list->prev) list->prev->next = skb;
    else list->next = skb;
    list->prev = skb;
    list->qlen++;
}
static inline void __skb_queue_purge(struct sk_buff_head *list) {
    while (__skb_dequeue(list));
}
static inline void skb_queue_splice_tail_init(struct sk_buff_head *list, struct sk_buff_head *head) {
    struct sk_buff *skb;
    while ((skb = __skb_dequeue(list))) {
        __skb_queue_tail(head, skb);
    }
}
static inline struct sk_buff *skb_clone(struct sk_buff *skb, int flags) {
    struct sk_buff *new_skb = malloc(sizeof(struct sk_buff));
    if (new_skb) {
        *new_skb = *skb;
        new_skb->cb = malloc(sizeof(struct TIPC_SKB_CB));
        if (new_skb->cb) *new_skb->cb = *skb->cb;
    }
    return new_skb;
}
static inline void kfree_skb(struct sk_buff *skb) { free(skb->cb); free(skb); }
static inline int msg_importance(struct tipc_msg *hdr) { return hdr->importance; }
static inline int msg_size(struct tipc_msg *hdr) { return hdr->size; }
static inline int msg_user(struct tipc_msg *hdr) { return hdr->user; }
static inline int msg_type(struct tipc_msg *hdr) { return hdr->type; }
static inline void msg_set_seqno(struct tipc_msg *hdr, u16 seqno) { hdr->seqno = seqno; }
static inline void msg_set_ack(struct tipc_msg *hdr, u16 ack) { hdr->ack = ack; }
static inline void msg_set_bcast_ack(struct tipc_msg *hdr, u16 bc_ack) { hdr->bcast_ack = bc_ack; }
static inline unsigned int tipc_link_mss(struct tipc_link *l) { return l->mtu; }
static inline void tipc_link_set_skb_retransmit_time(struct sk_buff *skb, struct tipc_link *l) {}
static inline int tipc_msg_try_bundle(struct sk_buff *bskb, struct sk_buff **skb, unsigned int mss, int addr, bool *new_bundle) { return 0; }
static inline int link_schedule_user(struct tipc_link *l, struct tipc_msg *hdr) { return 0; }
static inline struct TIPC_SKB_CB *TIPC_SKB_CB(struct sk_buff *skb) { return skb->cb; }