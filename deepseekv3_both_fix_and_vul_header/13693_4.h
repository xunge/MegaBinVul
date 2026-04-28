#include <stdint.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef _Atomic int atomic_t;

enum nfp_flower_cmsg_port_vnic_type {
    NFP_FLOWER_CMSG_PORT_VNIC_TYPE_UNSPEC,
    NFP_FLOWER_CMSG_PORT_VNIC_TYPE_PF,
    NFP_FLOWER_CMSG_PORT_VNIC_TYPE_VF
};

enum nfp_repr_type {
    NFP_REPR_TYPE_PF,
    NFP_REPR_TYPE_VF
};

enum nfp_port_type {
    NFP_PORT_PF_PORT,
    NFP_PORT_VF_PORT
};

struct nfp_cpp;
struct net_device {
    char name[16];
};

struct nfp_app {
    struct {
        struct nfp_cpp *cpp;
        void *vf_cfg_mem;
    } *pf;
    void *priv;
    struct nfp_cpp *cpp;
};

struct nfp_flower_priv {
    atomic_t reify_replies;
    struct {
        struct {
            void *ctrl_bar;
            struct net_device *netdev;
        } dp;
    } *nn;
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

struct nfp_port {
    int pf_id;
    int vf_id;
    void *vnic;
};

#define NFP_NET_CFG_BAR_SZ 0
#define ENOMEM (-12)
#define GFP_KERNEL 0

#define WARN_ON(cond) ((void)0)
#define IS_ERR(ptr) (0)
#define PTR_ERR(ptr) (0)
#define RCU_INIT_POINTER(p, v) ((p) = (v))

static inline int nfp_cppcore_pcie_unit(struct nfp_cpp *cpp) { return 0; }
static inline struct nfp_reprs *nfp_reprs_alloc(unsigned int cnt) { return NULL; }
static inline struct net_device *nfp_repr_alloc(struct nfp_app *app) { return NULL; }
static inline void nfp_repr_free(struct net_device *repr) {}
static inline struct nfp_port *nfp_port_alloc(struct nfp_app *app, enum nfp_port_type port_type, struct net_device *repr) { return NULL; }
static inline void nfp_port_free(struct nfp_port *port) {}
static inline u32 nfp_flower_cmsg_pcie_port(u8 nfp_pcie, enum nfp_flower_cmsg_port_vnic_type vnic_type, int i, u8 queue) { return 0; }
static inline int nfp_repr_init(struct nfp_app *app, struct net_device *repr, u32 port_id, struct nfp_port *port, struct net_device *netdev) { return 0; }
static inline struct nfp_reprs *nfp_app_reprs_set(struct nfp_app *app, enum nfp_repr_type repr_type, struct nfp_reprs *reprs) { return NULL; }
static inline int nfp_flower_reprs_reify(struct nfp_app *app, enum nfp_repr_type repr_type, bool bool_val) { return 0; }
static inline int nfp_flower_wait_repr_reify(struct nfp_app *app, atomic_t *replies, int reify_cnt) { return 0; }
static inline void nfp_reprs_clean_and_free(struct nfp_app *app, struct nfp_reprs *reprs) {}
static inline void nfp_info(struct nfp_cpp *cpp, const char *fmt, ...) {}
static inline void nfp_warn(struct nfp_cpp *cpp, const char *fmt, ...) {}
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void eth_hw_addr_random(struct net_device *dev) {}
static inline void *netdev_priv(struct net_device *dev) { return NULL; }
static inline void atomic_set(atomic_t *v, int i) { atomic_store(v, i); }