#include <stddef.h>
#include <string.h>

#define __user
#define EINVAL 22
#define EFAULT 14

typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef __u32 sctp_assoc_t;

struct sockaddr_storage {
    unsigned short ss_family;
    char __ss_padding[128 - sizeof(unsigned short)];
};

struct sctp_stats {
    __u64 rtxchunks;
    __u64 gapcnt;
    __u64 outofseqtsns;
    __u64 osacks;
    __u64 isacks;
    __u64 octrlchunks;
    __u64 ictrlchunks;
    __u64 oodchunks;
    __u64 iodchunks;
    __u64 ouodchunks;
    __u64 iuodchunks;
    __u64 idupchunks;
    __u64 opackets;
    __u64 ipackets;
    __u64 max_obs_rto;
    struct sockaddr_storage obs_rto_ipaddr;
};

struct sctp_association {
    struct sctp_stats stats;
    __u64 rto_min;
};

struct sctp_assoc_stats {
    sctp_assoc_t sas_assoc_id;
    __u64 sas_rtxchunks;
    __u64 sas_gapcnt;
    __u64 sas_outofseqtsns;
    __u64 sas_osacks;
    __u64 sas_isacks;
    __u64 sas_octrlchunks;
    __u64 sas_ictrlchunks;
    __u64 sas_oodchunks;
    __u64 sas_iodchunks;
    __u64 sas_ouodchunks;
    __u64 sas_iuodchunks;
    __u64 sas_idupchunks;
    __u64 sas_opackets;
    __u64 sas_ipackets;
    __u64 sas_maxrto;
    struct sockaddr_storage sas_obs_rto_ipaddr;
};

struct sock;

static inline int copy_from_user(void *to, const void __user *from, unsigned long n) { return 0; }
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }
static inline int put_user(int val, int __user *addr) { return 0; }
static inline struct sctp_association *sctp_id2assoc(struct sock *sk, sctp_assoc_t id) { return NULL; }
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define SCTP_DEBUG_PRINTK(fmt, ...)