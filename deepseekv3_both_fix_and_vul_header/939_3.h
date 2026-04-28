#include <stddef.h>
#include <stdbool.h>

#define TCP_LISTEN 1
#define LLC_PACKET 0
#define unlikely(x) (x)

struct llc_addr {
    unsigned char mac[6];
    unsigned char lsap;
};

struct llc_sap;
struct sock {
    int sk_state;
    unsigned int sk_rcvbuf;
};
struct sk_buff {
    void *dev;
    struct sock *sk;
    void (*destructor)(struct sk_buff *);
};

void llc_pdu_decode_sa(struct sk_buff *skb, unsigned char *mac);
void llc_pdu_decode_ssap(struct sk_buff *skb, unsigned char *lsap);
void llc_pdu_decode_da(struct sk_buff *skb, unsigned char *mac);
void llc_pdu_decode_dsap(struct sk_buff *skb, unsigned char *lsap);
struct sock *__llc_lookup(struct llc_sap *sap, struct llc_addr *saddr, struct llc_addr *daddr);
void bh_lock_sock(struct sock *sk);
void bh_unlock_sock(struct sock *sk);
struct sock *llc_create_incoming_sock(struct sock *sk, void *dev, struct llc_addr *saddr, struct llc_addr *daddr);
void skb_set_owner_r(struct sk_buff *skb, struct sock *sk);
void skb_orphan(struct sk_buff *skb);
void sock_hold(struct sock *sk);
void sock_put(struct sock *sk);
bool sock_owned_by_user(struct sock *sk);
void llc_conn_rcv(struct sock *sk, struct sk_buff *skb);
void dprintk(const char *fmt, ...);
void llc_set_backlog_type(struct sk_buff *skb, int type);
bool sk_add_backlog(struct sock *sk, struct sk_buff *skb, unsigned int limit);
void kfree_skb(struct sk_buff *skb);
void sock_efree(struct sk_buff *skb);