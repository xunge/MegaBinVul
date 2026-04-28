#include <stdint.h>
#include <stdlib.h>

struct km_event {
    void *net;
    uint32_t portid;
    uint32_t seq;
    struct {
        uint8_t proto;
    } data;
};

struct sk_buff {
    void *data;
    unsigned int len;
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

#define PF_KEY_V2 2
#define SADB_FLUSH 8
#define GFP_ATOMIC 0
#define BROADCAST_ALL 0
#define ENOBUFS 105

static struct sk_buff *alloc_skb(unsigned int size, int priority) { return malloc(size); }
static void *skb_put(struct sk_buff *skb, unsigned int len) { return skb->data; }
static int pfkey_proto2satype(uint8_t proto) { return 0; }
static void pfkey_broadcast(struct sk_buff *skb, int allocation, int broadcast_flags, void *sk, void *net) {}