#include <stdint.h>
#include <stddef.h>

#define NLBL_CIPSOV4_A_DOI 1
#define NLBL_CIPSOV4_C_LIST 1
#define NLBL_CIPSOV4_A_MTYPE 2
#define NLBL_CIPSOV4_A_TAGLST 3
#define NLBL_CIPSOV4_A_TAG 4
#define NLBL_CIPSOV4_A_MLSLVLLST 5
#define NLBL_CIPSOV4_A_MLSLVL 6
#define NLBL_CIPSOV4_A_MLSLVLLOC 7
#define NLBL_CIPSOV4_A_MLSLVLREM 8
#define NLBL_CIPSOV4_A_MLSCATLST 9
#define NLBL_CIPSOV4_A_MLSCAT 10
#define NLBL_CIPSOV4_A_MLSCATLOC 11
#define NLBL_CIPSOV4_A_MLSCATREM 12

#define CIPSO_V4_TAG_MAXCNT 5
#define CIPSO_V4_TAG_INVALID 0
#define CIPSO_V4_INV_LVL 0xFFFFFFFF
#define CIPSO_V4_INV_CAT 0xFFFFFFFF

#define CIPSO_V4_MAP_TRANS 1
#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12
#define NLMSG_DEFAULT_SIZE 1024

typedef uint32_t u32;

struct sk_buff {
    void *data;
};

struct genl_info {
    struct nlattr **attrs;
};

struct nlattr {
    uint32_t dummy;
};

struct cipso_v4_doi {
    uint32_t type;
    uint8_t tags[CIPSO_V4_TAG_MAXCNT];
    struct {
        struct {
            struct {
                uint32_t *local;
                uint32_t local_size;
            } lvl;
            struct {
                uint32_t *local;
                uint32_t local_size;
            } cat;
        } *std;
    } map;
};

struct netlbl_cipsov4_gnl_family {
    int dummy;
};

static struct netlbl_cipsov4_gnl_family netlbl_cipsov4_gnl_family;

static inline struct sk_buff *nlmsg_new(size_t size, int flags) { return NULL; }
static inline void *genlmsg_put_reply(struct sk_buff *skb, struct genl_info *info, 
                                     struct netlbl_cipsov4_gnl_family *family,
                                     int flags, int cmd) { return NULL; }
static inline uint32_t nla_get_u32(struct nlattr *attr) { return 0; }
static inline int nla_put_u32(struct sk_buff *skb, int attrtype, uint32_t value) { return 0; }
static inline int nla_put_u8(struct sk_buff *skb, int attrtype, uint8_t value) { return 0; }
static inline struct nlattr *nla_nest_start_noflag(struct sk_buff *skb, int attrtype) { return NULL; }
static inline void nla_nest_end(struct sk_buff *skb, struct nlattr *attr) {}
static inline void genlmsg_end(struct sk_buff *skb, void *hdr) {}
static inline int genlmsg_reply(struct sk_buff *skb, struct genl_info *info) { return 0; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline struct cipso_v4_doi *cipso_v4_doi_getdef(uint32_t doi) { return NULL; }