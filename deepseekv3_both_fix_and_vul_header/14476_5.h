#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef uint64_t u64;

struct list_head {
    struct list_head *next, *prev;
};

struct nlattr {
    u16 nla_len;
    u16 nla_type;
};

struct nlmsghdr {
    u32 nlmsg_len;
    u16 nlmsg_type;
    u16 nlmsg_flags;
    u32 nlmsg_seq;
    u32 nlmsg_pid;
};

struct sk_buff;
struct net;
struct netlink_ext_ack;

struct nfnl_info {
    struct nlmsghdr *nlh;
    struct netlink_ext_ack *extack;
    struct net *net;
};

struct nfgenmsg {
    int nfgen_family;
};

struct nft_set_desc {
    unsigned int klen;
    unsigned int dlen;
    unsigned int size;
    unsigned int field_count;
    unsigned int field_len[16];
    bool expr;
};

struct nft_expr;

struct nft_set {
    struct nft_table *table;
    const struct nft_set_ops *ops;
    u32 ktype;
    u32 klen;
    u32 dtype;
    u32 objtype;
    u32 dlen;
    u32 flags;
    u32 size;
    u32 policy;
    u16 udlen;
    unsigned char *udata;
    u64 timeout;
    u32 gc_int;
    u64 handle;
    unsigned int field_count;
    unsigned int field_len[16];
    char *name;
    void *data;
    struct nft_expr *exprs[16];
    unsigned int num_exprs;
    struct list_head list;
    struct list_head bindings;
    struct list_head catchall_list;
    void *net;
};

struct nft_set_ops {
    u64 (*privsize)(const struct nlattr * const nla[], const struct nft_set_desc *desc);
    int (*init)(struct nft_set *set, const struct nft_set_desc *desc, const struct nlattr * const nla[]);
    void (*destroy)(struct nft_set *set);
};

struct nft_table {
    struct list_head sets;
    unsigned int use;
};

struct nft_ctx {
    struct net *net;
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    int family;
    struct nft_table *table;
};

struct nft_verdict {
    int code;
};

struct netlink_cb {
    int portid;
};

#define NLA_ALIGN(len) (((len) + 3) & ~3)

#define NFT_DATA_VALUE 0
#define NFT_DATA_RESERVED_MASK 0xffffff00
#define NFT_DATA_VERDICT 1
#define NFT_DATA_VALUE_MAXLEN 64
#define NFT_SET_ANONYMOUS 0x1
#define NFT_SET_CONSTANT 0x2
#define NFT_SET_INTERVAL 0x4
#define NFT_SET_TIMEOUT 0x8
#define NFT_SET_MAP 0x10
#define NFT_SET_EVAL 0x20
#define NFT_SET_OBJECT 0x40
#define NFT_SET_CONCAT 0x80
#define NFT_SET_EXPR 0x100
#define NFT_OBJECT_UNSPEC 0
#define NFT_OBJECT_MAX 255
#define NFT_SET_POL_PERFORMANCE 0
#define NFT_SET_EXPR_MAX 16
#define NLM_F_EXCL 0x200
#define NLM_F_REPLACE 0x100
#define NLM_F_CREATE 0x400
#define EINVAL 22
#define EOPNOTSUPP 95
#define ENOENT 2
#define EEXIST 17
#define ENOMEM 12
#define E2BIG 7
#define NFT_MSG_NEWSET 0

#define NFTA_SET_TABLE 0
#define NFTA_SET_NAME 1
#define NFTA_SET_KEY_LEN 2
#define NFTA_SET_ID 3
#define NFTA_SET_KEY_TYPE 4
#define NFTA_SET_FLAGS 5
#define NFTA_SET_DATA_TYPE 6
#define NFTA_SET_DATA_LEN 7
#define NFTA_SET_OBJ_TYPE 8
#define NFTA_SET_TIMEOUT 9
#define NFTA_SET_GC_INTERVAL 10
#define NFTA_SET_POLICY 11
#define NFTA_SET_DESC 12
#define NFTA_SET_EXPR 13
#define NFTA_SET_EXPRESSIONS 14
#define NFTA_SET_USERDATA 15
#define NFTA_LIST_ELEM 16

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-1000L)
#define PTR_ERR(x) ((long)(x))
#define NL_SET_BAD_ATTR(extack, attr)
#define GFP_KERNEL 0

static inline const void *nlmsg_data(const void *nlh) { return nlh; }
static inline u8 nft_genmask_next(struct net *net) { return 0; }
static inline int nf_msecs_to_jiffies64(const struct nlattr *nla, u64 *timeout) { return 0; }
static inline int nf_tables_set_desc_parse(struct nft_set_desc *desc, const struct nlattr *nla) { return 0; }
static inline struct nft_table *nft_table_lookup(struct net *net, const struct nlattr *nla, int family, u8 genmask, int portid) { return NULL; }
static inline void nft_ctx_init(struct nft_ctx *ctx, struct net *net, struct sk_buff *skb, struct nlmsghdr *nlh, int family, struct nft_table *table, void *null, const struct nlattr * const nla[]) {}
static inline struct nft_set *nft_set_lookup(struct nft_table *table, const struct nlattr *nla, u8 genmask) { return NULL; }
static inline const struct nft_set_ops *nft_select_set_ops(const struct nft_ctx *ctx, const struct nlattr * const nla[], const struct nft_set_desc *desc, u32 policy) { return NULL; }
static inline int nf_tables_set_alloc_name(struct nft_ctx *ctx, struct nft_set *set, const char *name) { return 0; }
static inline struct nft_expr *nft_set_elem_expr_alloc(struct nft_ctx *ctx, struct nft_set *set, const struct nlattr *attr) { return NULL; }
static inline u64 nf_tables_alloc_handle(struct nft_table *table) { return 0; }
static inline int nft_trans_set_add(struct nft_ctx *ctx, int msg_type, struct nft_set *set) { return 0; }
static inline void nft_expr_destroy(struct nft_ctx *ctx, struct nft_expr *expr) {}
static inline void *kvzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kvfree(void *ptr) { free(ptr); }
static inline u32 ntohl(u32 x) { return x; }
static inline u32 nla_get_be32(const struct nlattr *attr) { return *(u32*)(attr + 1); }
static inline size_t nla_len(const struct nlattr *attr) { return attr ? attr->nla_len : 0; }
static inline char *nla_strdup(const struct nlattr *attr, int flags) { return strdup((const char*)(attr + 1)); }
static inline void nla_memcpy(void *dest, const struct nlattr *src, size_t len) { memcpy(dest, src + 1, len); }
static inline int nla_type(const struct nlattr *attr) { return attr ? attr->nla_type : 0; }
#define nla_for_each_nested(pos, attr, rem) for (pos = (struct nlattr*)(attr + 1), rem = nla_len(attr) - sizeof(*attr); rem > 0; pos = (struct nlattr*)((char*)pos + NLA_ALIGN(pos->nla_len)), rem -= NLA_ALIGN(pos->nla_len))
static inline void INIT_LIST_HEAD(struct list_head *list) { list->next = list->prev = list; }
static inline void write_pnet(void **net, void *val) { *net = val; }
static inline void list_add_tail_rcu(struct list_head *new, struct list_head *head) { new->next = head; new->prev = head->prev; head->prev->next = new; head->prev = new; }
static inline struct netlink_cb NETLINK_CB(const struct sk_buff *skb) { struct netlink_cb cb = {0}; return cb; }
static inline void kfree(void *p) { free(p); }