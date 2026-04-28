#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define EINVAL 22
#define EOPNOTSUPP 95
#define EBUSY 16
#define E2BIG 7

#define NFT_DYNSET_F_INV 0x1
#define NFT_DYNSET_F_EXPR 0x2
#define NFT_SET_OBJECT 0x1
#define NFT_SET_CONSTANT 0x2
#define NFT_SET_TIMEOUT 0x4
#define NFT_SET_MAP 0x8
#define NFT_SET_EVAL 0x10
#define NFT_SET_EXPR_MAX 10
#define NFT_SET_EXT_KEY 0
#define NFT_SET_EXT_DATA 1
#define NFT_SET_EXT_TIMEOUT 2
#define NFT_SET_EXT_EXPIRATION 3
#define NFTA_DYNSET_SET_NAME 0
#define NFTA_DYNSET_OP 1
#define NFTA_DYNSET_SREG_KEY 2
#define NFTA_DYNSET_FLAGS 3
#define NFTA_DYNSET_SET_ID 4
#define NFTA_DYNSET_TIMEOUT 5
#define NFTA_DYNSET_SREG_DATA 6
#define NFTA_DYNSET_EXPR 7
#define NFTA_DYNSET_EXPRESSIONS 8
#define NFTA_LIST_ELEM 0
#define NFT_DYNSET_OP_DELETE 1
#define NFT_DATA_VERDICT 0

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint32_t nft_genmask_t;

struct nft_ctx {
    void *net;
    void *table;
};

struct nft_expr {
    struct nft_expr_ops *ops;
};

struct nft_expr_ops {
    void *update;
};

struct nlattr {
    int type;
};

struct nftables_pernet {
    int commit_mutex;
};

struct nft_dynset {
    bool invert;
    bool expr;
    u32 op;
    u32 sreg_key;
    u32 sreg_data;
    unsigned int num_exprs;
    struct nft_expr *expr_array[NFT_SET_EXPR_MAX];
    void *tmpl;
    u64 timeout;
    void *binding;
    void *set;
};

struct nft_set {
    unsigned int flags;
    struct nft_set_ops *ops;
    unsigned int klen;
    unsigned int dlen;
    unsigned int dtype;
    unsigned int num_exprs;
    struct nft_expr *exprs[NFT_SET_EXPR_MAX];
    u64 timeout;
    unsigned int size;
};

struct nft_set_ops {
    void *update;
};

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-4096)
#define PTR_ERR(x) ((int)(intptr_t)(x))
#define lockdep_assert_held(x) (void)(x)

static inline struct nftables_pernet *nft_pernet(void *net) { return NULL; }
static inline struct nft_dynset *nft_expr_priv(const struct nft_expr *expr) { return NULL; }
static inline u8 nft_genmask_next(void *net) { return 0; }
static inline u32 ntohl(u32 x) { return x; }
static inline u32 nla_get_be32(const struct nlattr *attr) { return 0; }
static inline struct nft_set *nft_set_lookup_global(void *net, void *table, const struct nlattr *name, const struct nlattr *id, u8 genmask) { return NULL; }
static inline int nf_msecs_to_jiffies64(const struct nlattr *attr, u64 *timeout) { return 0; }
static inline int nft_parse_register_load(const struct nlattr *attr, u32 *sreg, unsigned int len) { return 0; }
static inline struct nft_expr *nft_dynset_expr_alloc(const struct nft_ctx *ctx, struct nft_set *set, const struct nlattr *attr, int i) { return NULL; }
static inline int nft_set_elem_expr_clone(const struct nft_ctx *ctx, struct nft_set *set, struct nft_expr *expr_array[]) { return 0; }
static inline void nft_set_ext_prepare(void *tmpl) {}
static inline void nft_set_ext_add_length(void *tmpl, int type, unsigned int len) {}
static inline void nft_dynset_ext_add_expr(struct nft_dynset *priv) {}
static inline void nft_set_ext_add(void *tmpl, int type) {}
static inline int nf_tables_bind_set(const struct nft_ctx *ctx, struct nft_set *set, void *binding) { return 0; }
static inline void nft_expr_destroy(const struct nft_ctx *ctx, struct nft_expr *expr) {}
static inline int nla_type(const struct nlattr *attr) { return attr->type; }

#define nla_for_each_nested(pos, attr, rem) \
    for (pos = (struct nlattr *)(attr), rem = 0; rem == 0; rem = 1)