#include <stdint.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

typedef atomic_int atomic_t;
typedef uint32_t u32;

struct nfp_app {
    struct {
        struct {
            struct nfp_eth_table *eth_tbl;
        } *pf;
        struct nfp_cpp *cpp;
        void *ctrl;
    };
};

struct nfp_flower_priv {
    atomic_t reify_replies;
    struct {
        struct {
            struct {
                struct {
                    struct net_device *netdev;
                } dp;
                struct {
                    struct device *dev;
                } *pdev;
            } *nn;
        };
    };
};

struct nfp_eth_table {
    unsigned int count;
    unsigned int max_index;
    struct {
        unsigned int index;
        unsigned int nbi;
        unsigned int base;
    } *ports;
};

struct nfp_flower_repr_priv {
    struct nfp_repr *nfp_repr;
};

struct nfp_repr {
    void *app_priv;
};

struct nfp_reprs {
    struct net_device **reprs;
};

struct nfp_port;
struct net_device {
    char name[16];
};
struct sk_buff;
struct device;
struct nfp_cpp;

#define NFP_PORT_PHYS_PORT 0
#define NFP_REPR_TYPE_PHYS_PORT 0
#define ENOMEM (-12)
#define GFP_KERNEL 0
#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((intptr_t)(x))
#define RCU_INIT_POINTER(p, v) do { (p) = (v); } while (0)
#define SET_NETDEV_DEV(dev, parentdev) do { } while (0)

static inline void atomic_set(atomic_t *v, int i) { *v = i; }

static inline struct sk_buff *nfp_flower_cmsg_mac_repr_start(struct nfp_app *app, unsigned int count) { return NULL; }
static inline struct nfp_reprs *nfp_reprs_alloc(unsigned int max_index) { return NULL; }
static inline struct net_device *nfp_repr_alloc(struct nfp_app *app) { return NULL; }
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline struct nfp_repr *netdev_priv(struct net_device *dev) { return NULL; }
static inline struct nfp_port *nfp_port_alloc(struct nfp_app *app, int type, struct net_device *dev) { return NULL; }
static inline void nfp_repr_free(struct net_device *dev) {}
static inline int nfp_port_init_phy_port(void *pf, struct nfp_app *app, struct nfp_port *port, int i) { return 0; }
static inline void nfp_port_free(struct nfp_port *port) {}
static inline void nfp_net_get_mac_addr(void *pf, struct net_device *dev, struct nfp_port *port) {}
static inline u32 nfp_flower_cmsg_phys_port(unsigned int phys_port) { return 0; }
static inline int nfp_repr_init(struct nfp_app *app, struct net_device *dev, u32 port_id, struct nfp_port *port, struct net_device *netdev) { return 0; }
static inline void nfp_flower_cmsg_mac_repr_add(struct sk_buff *skb, int i, unsigned int nbi, unsigned int base, unsigned int phys_port) {}
static inline void nfp_info(struct nfp_cpp *cpp, const char *fmt, ...) {}
static inline void *nfp_app_reprs_set(struct nfp_app *app, int type, struct nfp_reprs *reprs) { return NULL; }
static inline int nfp_flower_reprs_reify(struct nfp_app *app, int type, bool exists) { return 0; }
static inline void nfp_warn(struct nfp_cpp *cpp, const char *fmt, ...) {}
static inline int nfp_flower_wait_repr_reify(struct nfp_app *app, atomic_t *replies, int cnt) { return 0; }
static inline void nfp_ctrl_tx(void *ctrl, struct sk_buff *skb) {}
static inline void nfp_reprs_clean_and_free(struct nfp_app *app, struct nfp_reprs *reprs) {}
static inline void kfree_skb(struct sk_buff *skb) {}