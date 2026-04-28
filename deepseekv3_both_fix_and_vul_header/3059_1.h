#include <stdint.h>
#include <stdlib.h>

struct km_event {
    uint32_t seq;
    uint32_t portid;
    void *net;
};

struct sk_buff {
    unsigned int len;
    void *data;
};

struct sadb_msg {
    uint8_t sadb_msg_version;
    uint8_t sadb_msg_type;
    uint8_t sadb_msg_errno;
    uint8_t sadb_msg_satype;
    uint16_t sadb_msg_len;
    uint16_t sadb_msg_reserved;
    uint32_t sadb_msg_seq;
    uint32_t sadb_msg_pid;
};

#define SADB_X_SPDFLUSH 16
#define PF_KEY_V2 2
#define SADB_SATYPE_UNSPEC 0
#define GFP_ATOMIC 0
#define BROADCAST_ALL 0
#define ENOBUFS 105

static struct sk_buff *alloc_skb(unsigned int size, int flags) { return malloc(size); }
static void *skb_put(struct sk_buff *skb, unsigned int len) { return skb->data; }
static void pfkey_broadcast(struct sk_buff *skb, int flags, int type, void *a, void *b) {}