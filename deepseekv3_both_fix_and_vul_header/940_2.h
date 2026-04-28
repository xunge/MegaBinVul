#include <stdlib.h>

#define LLC_SAP_EV_TYPE_PDU 0

struct sk_buff {
    void *sk;
    void (*destructor)(void *);
};

struct sock;

struct llc_sap;

struct llc_sap_state_ev {
    int type;
    int reason;
};

void skb_orphan(struct sk_buff *skb);
void sock_hold(struct sock *sk);
void sock_efree(void *);
struct llc_sap_state_ev *llc_sap_ev(struct sk_buff *skb);
void llc_sap_state_process(struct llc_sap *sap, struct sk_buff *skb);