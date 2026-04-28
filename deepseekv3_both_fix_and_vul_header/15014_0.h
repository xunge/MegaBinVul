#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>

#define __user
#define GFP_KERNEL 0
#define EINVAL 22
#define EFAULT 14
#define ENOMEM 12

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct sockaddr_storage {
    unsigned short ss_family;
    char __ss_padding[128 - sizeof(unsigned short)];
};

struct list_head {
    struct list_head *next, *prev;
};

union sctp_addr {
    struct sockaddr sa;
    struct sockaddr_storage ss;
};

struct sctp_bind_addr {
    struct list_head address_list;
    unsigned short port;
};

struct sctp_sockaddr_entry {
    union sctp_addr a;
    struct list_head list;
};

struct sctp_getaddrs_old {
    int addr_num;
    int assoc_id;
    void *addrs;
};

struct sock {
    unsigned short sk_family;
};

struct sctp_sock {
    struct sock sk;
    struct {
        struct {
            struct sctp_bind_addr bind_addr;
        } base;
    } *ep;
};

struct sctp_association {
    struct {
        struct sctp_bind_addr bind_addr;
    } base;
};

struct sctp_pf {
    void (*addr_v4map)(struct sctp_sock *, union sctp_addr *);
};

struct sctp_af {
    int sockaddr_len;
};

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int copy_from_user(void *to, const void *from, unsigned long n) { memcpy(to, from, n); return 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { memcpy(to, from, n); return 0; }
static inline struct sctp_sock *sctp_sk(const struct sock *sk) { return (struct sctp_sock *)sk; }
static inline int sctp_is_any(const union sctp_addr *addr) { return 0; }
static inline int sctp_copy_laddrs_old(struct sock *sk, unsigned short port, int num, void *addrs, int *copied) { return 0; }
static inline struct sctp_association *sctp_id2assoc(struct sock *sk, int id) { return NULL; }
static inline int sctp_list_single_entry(struct list_head *list) { return list->next == list->prev; }
static inline struct sctp_pf *sctp_get_pf_specific(int family) { return NULL; }
static inline struct sctp_af *sctp_get_af_specific(int family) { return NULL; }

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry(pos, head, member) \
    for (pos = list_entry((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = list_entry(pos->member.next, typeof(*pos), member))