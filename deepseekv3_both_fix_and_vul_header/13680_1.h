#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_MGMT_PKT_SIZE 2048
#define ERR_ZONE 1
#define DATA_TX_ZONE 2
#define MGMT_BEACON_Q 0
#define ENOMEM 12
#define EINVAL 22

typedef uint8_t u8;

struct sk_buff {
    unsigned char *data;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct rsi_common {
    struct sk_buff_head tx_queue[1];
    struct {
        unsigned long event;
    } tx_thread;
};

struct sk_buff *dev_alloc_skb(unsigned int size);
void skb_pull(struct sk_buff *skb, unsigned int len);
void skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newsk);
void rsi_set_event(unsigned long *event);
int rsi_prepare_beacon(struct rsi_common *common, struct sk_buff *skb);
void rsi_dbg(int zone, const char *fmt, ...);