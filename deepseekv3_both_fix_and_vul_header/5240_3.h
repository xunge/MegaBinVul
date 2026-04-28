#include <stdbool.h>
#include <stddef.h>

typedef unsigned short __u16;

struct sock;
struct msghdr {
    int msg_flags;
    void *msg_iter;
};

struct sctp_sndrcvinfo {
    __u16 sinfo_flags;
    __u16 sinfo_assoc_id;
};

struct sctp_cmsgs {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct sctp_association {
    struct list_head asocs;
};

struct sctp_endpoint {
    struct list_head asocs;
    struct sctp_endpoint *ep;
};

struct sctp_transport {
    struct sctp_association *asoc;
};

union sctp_addr {
    int dummy;
};

#define IS_ERR(x) ((unsigned long)(void *)(x) >= (unsigned long)-4095)
#define PTR_ERR(x) ((long)(x))
#define EPIPE 32
#define ESRCH 3
#define SCTP_SENDALL 0x01
#define SCTP_ADDR_OVER 0x02
#define UDP 0
#define TCP 1

static inline struct sctp_endpoint *sctp_sk(struct sock *sk) { 
    static struct sctp_endpoint ep;
    return &ep; 
}
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int sctp_style(struct sock *sk, int style) { return 0; }
static inline int sctp_sendmsg_parse(struct sock *sk, struct sctp_cmsgs *cmsgs, 
                                   struct sctp_sndrcvinfo *sinfo, 
                                   struct msghdr *msg, size_t msg_len) { return 0; }
static inline union sctp_addr *sctp_sendmsg_get_daddr(struct sock *sk, 
                                                     struct msghdr *msg, 
                                                     struct sctp_cmsgs *cmsgs) { return NULL; }
static inline int sctp_sendmsg_check_sflags(struct sctp_association *asoc, 
                                          __u16 sflags, 
                                          struct msghdr *msg, 
                                          size_t msg_len) { return 0; }
static inline void sctp_sendmsg_update_sinfo(struct sctp_association *asoc, 
                                           struct sctp_sndrcvinfo *sinfo, 
                                           struct sctp_cmsgs *cmsgs) {}
static inline int sctp_sendmsg_to_asoc(struct sctp_association *asoc, 
                                     struct msghdr *msg, 
                                     size_t msg_len, 
                                     struct sctp_transport *transport, 
                                     struct sctp_sndrcvinfo *sinfo) { return 0; }
static inline struct sctp_association *sctp_endpoint_lookup_assoc(
    struct sctp_endpoint *ep, union sctp_addr *daddr, 
    struct sctp_transport **transport) { return NULL; }
static inline int sctp_sendmsg_new_asoc(struct sock *sk, __u16 sflags, 
                                      struct sctp_cmsgs *cmsgs, 
                                      union sctp_addr *daddr, 
                                      struct sctp_transport **transport) { return 0; }
static inline struct sctp_association *sctp_id2assoc(struct sock *sk, 
                                                   __u16 assoc_id) { return NULL; }
static inline void sctp_association_free(struct sctp_association *asoc) {}
static inline int sctp_error(struct sock *sk, int flags, int err) { return err; }
static inline void iov_iter_revert(void *iter, int err) {}

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)), \
         n = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = n, n = (typeof(*pos)*)((char*)n->member.next - offsetof(typeof(*pos), member)))