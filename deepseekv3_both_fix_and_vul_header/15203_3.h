#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>
#include <time.h>

typedef uint32_t u32;
typedef unsigned long jiffies_t;

struct sk_buff {
    unsigned char *tail;
    unsigned char *data;
    int len;
};

struct neighbour {
    struct {
        int family;
    } *ops;
    unsigned int flags;
    int type;
    struct {
        int ifindex;
        int addr_len;
        unsigned char *ha;
    } *dev;
    void *primary_key;
    struct {
        int key_len;
    } *tbl;
    int nud_state;
    jiffies_t used;
    jiffies_t confirmed;
    jiffies_t updated;
    struct {
        int counter;
    } refcnt;
    struct {
        int counter;
    } probes;
    void *lock;
};

struct nlmsghdr {
    u32 nlmsg_len;
};

struct ndmsg {
    int ndm_family;
    int ndm_pad1;
    int ndm_pad2;
    unsigned int ndm_flags;
    int ndm_type;
    int ndm_ifindex;
    int ndm_state;
};

struct nda_cacheinfo {
    uint32_t ndm_used;
    uint32_t ndm_confirmed;
    uint32_t ndm_updated;
    uint32_t ndm_refcnt;
};

#define NLMSG_NEW(skb, pid, seq, type, len, flags) ((struct nlmsghdr *)NULL)
#define NLMSG_DATA(nlh) ((struct ndmsg *)((char *)(nlh) + sizeof(struct nlmsghdr)))
#define RTA_PUT(skb, attrtype, attrlen, data) (0)

static inline jiffies_t jiffies = 0;

static inline int atomic_read(const volatile int *v) {
    return *v;
}

static inline void read_lock_bh(void *lock) {}
static inline void read_unlock_bh(void *lock) {}
static inline void skb_trim(struct sk_buff *skb, int len) {}

#define NUD_VALID 0x01
#define NDA_DST 0
#define NDA_LLADDR 1
#define NDA_CACHEINFO 2
#define NDA_PROBES 3