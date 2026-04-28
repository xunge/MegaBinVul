#include <stdint.h>
#include <stddef.h>

#define GFP_ATOMIC 0
#define ENOBUFS 105
#define BROADCAST_ALL 0
#define PF_KEY_V2 2
#define SADB_X_SPDFLUSH 0
#define SADB_SATYPE_UNSPEC 0

struct km_event {
    unsigned int seq;
    unsigned int portid;
    void *net;
};

struct sk_buff {
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

struct sk_buff *alloc_skb(unsigned int size, int flags);
void *skb_put(struct sk_buff *skb, unsigned int len);
void pfkey_broadcast(struct sk_buff *skb, int flags, int broadcast, void *one, void *net);