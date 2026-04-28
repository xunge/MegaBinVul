#include <stdint.h>
#include <stdio.h>

#define NLMSG_HDRLEN ((size_t) 16)
#define NLMSG_ALIGN(len) (((len) + 3) & ~3)
#define KERN_WARNING ""
#define CAP_SYS_ADMIN 0
#define NLM_F_ACK 0x04

typedef uint32_t u32;
typedef uint16_t u16;

struct sk_buff {
    unsigned int len;
};

struct nlmsghdr {
    u32 nlmsg_len;
    u16 nlmsg_type;
    u16 nlmsg_flags;
};

struct scsi_nl_hdr {
    u32 version;
    u32 transport;
    u32 magic;
    u32 msgtype;
    u32 msglen;
};

#define SCSI_TRANSPORT_MSG 0
#define SCSI_NL_VERSION 1
#define SCSI_NL_MAGIC 0xA1B2C3D4
#define SCSI_NL_TRANSPORT 0
#define SCSI_NL_SHOST_VENDOR 0

#define EBADMSG 74
#define EPROTOTYPE 91
#define EPERM 1
#define ESRCH 3
#define EBADR 53
#define ENOENT 2

static inline struct nlmsghdr *nlmsg_hdr(struct sk_buff *skb) {
    return (struct nlmsghdr *)skb;
}

static inline struct scsi_nl_hdr *nlmsg_data(struct nlmsghdr *nlh) {
    return (struct scsi_nl_hdr *)(nlh + 1);
}

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->len -= len;
}

static inline void netlink_ack(struct sk_buff *skb, struct nlmsghdr *nlh, int err) {
    // Dummy implementation
}

static inline int capable(int cap) {
    return 0; // Dummy implementation
}

static inline int printk(const char *fmt, ...) {
    return 0; // Dummy implementation
}