#include <stdatomic.h>
#include <string.h>
#include <stdint.h>

struct neigh_table {
    unsigned int family;
    unsigned long last_flush;
    unsigned long last_rand;
    unsigned short key_len;
    unsigned short entry_size;
    atomic_int entries;
    unsigned int hash_rnd;
    unsigned int hash_mask;
    unsigned int hash_chain_gc;
    struct {
        int qlen;
    } proxy_queue;
    struct neigh_statistics *stats;
    void *lock;
    char *id;
    unsigned int gc_interval;
    unsigned int gc_thresh1;
    unsigned int gc_thresh2;
    unsigned int gc_thresh3;
    struct {
        void *dev;
    } parms;
};

struct neigh_statistics {
    unsigned long long allocs;
    unsigned long long destroys;
    unsigned long long hash_grows;
    unsigned long long res_failed;
    unsigned long long lookups;
    unsigned long long hits;
    unsigned long long rcv_probes_mcast;
    unsigned long long rcv_probes_ucast;
    unsigned long long periodic_gc_runs;
    unsigned long long forced_gc_runs;
};

struct ndtmsg {
    unsigned char ndtm_family;
    unsigned char ndtm_pad1;
    unsigned short ndtm_pad2;
};

struct ndt_config {
    unsigned short ndtc_key_len;
    unsigned short ndtc_entry_size;
    unsigned int ndtc_entries;
    unsigned int ndtc_last_flush;
    unsigned int ndtc_last_rand;
    unsigned int ndtc_hash_rnd;
    unsigned int ndtc_hash_mask;
    unsigned int ndtc_hash_chain_gc;
    unsigned int ndtc_proxy_qlen;
};

struct ndt_stats {
    unsigned long long ndts_allocs;
    unsigned long long ndts_destroys;
    unsigned long long ndts_hash_grows;
    unsigned long long ndts_res_failed;
    unsigned long long ndts_lookups;
    unsigned long long ndts_hits;
    unsigned long long ndts_rcv_probes_mcast;
    unsigned long long ndts_rcv_probes_ucast;
    unsigned long long ndts_periodic_gc_runs;
    unsigned long long ndts_forced_gc_runs;
};

#define RTM_NEWNEIGHTBL 0
#define NLM_F_MULTI 0
#define NDTA_NAME 0
#define NDTA_GC_INTERVAL 0
#define NDTA_THRESH1 0
#define NDTA_THRESH2 0
#define NDTA_THRESH3 0
#define NDTA_CONFIG 0
#define NDTA_STATS 0
#define NR_CPUS 1

#define NLMSG_NEW_ANSWER(skb, cb, type, len, flags) NULL
#define NLMSG_DATA(nlh) NULL
#define RTA_PUT_STRING(skb, attrtype, attrlen) 
#define RTA_PUT_MSECS(skb, attrtype, attrlen) 
#define RTA_PUT_U32(skb, attrtype, attrlen) 
#define RTA_PUT(skb, attrtype, attrlen, attrdata) 
#define NLMSG_END(skb, nlh) 0
#define NLMSG_CANCEL(skb, nlh) 0
#define BUG_ON(cond)
#define jiffies 0
#define jiffies_to_msecs(x) (x)
#define cpu_possible(cpu) 1
#define per_cpu_ptr(ptr, cpu) (ptr)
#define atomic_read(v) 0
#define read_lock_bh(lock)
#define read_unlock_bh(lock)