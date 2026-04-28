#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct sk_buff {
    // Minimal stub for compilation
    void* data;
};

struct net_device {
    int ifindex;
    // Other minimal fields
};

struct br_mdb_entry {
    // Minimal stub
    uint8_t dummy[128]; // Placeholder size
};

struct nlmsghdr {
    // Minimal stub
    uint32_t nlmsg_len;
    uint16_t nlmsg_type;
    uint16_t nlmsg_flags;
    uint32_t nlmsg_seq;
    uint32_t nlmsg_pid;
};

struct br_port_msg {
    unsigned short family;
    int ifindex;
};

struct nlattr {
    uint16_t nla_len;
    uint16_t nla_type;
};

#define AF_BRIDGE 7
#define MDBA_MDB 1
#define MDBA_MDB_ENTRY 2
#define MDBA_MDB_ENTRY_INFO 3
#define NLM_F_MULTI 0x2
#define EMSGSIZE 90

// Stub function declarations
static struct nlmsghdr* nlmsg_put(struct sk_buff* skb, u32 pid, u32 seq, int type, size_t size, int flags) {
    return NULL;
}
static void* nlmsg_data(struct nlmsghdr* nlh) {
    return NULL;
}
static struct nlattr* nla_nest_start(struct sk_buff* skb, int attrtype) {
    return NULL;
}
static int nla_put(struct sk_buff* skb, int attrtype, size_t size, const void* data) {
    return 0;
}
static void nla_nest_end(struct sk_buff* skb, struct nlattr* attr) {}
static int nlmsg_end(struct sk_buff* skb, struct nlmsghdr* nlh) {
    return 0;
}
static void nlmsg_cancel(struct sk_buff* skb, struct nlmsghdr* nlh) {}