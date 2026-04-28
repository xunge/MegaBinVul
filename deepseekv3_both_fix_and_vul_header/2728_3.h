#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define MAX_SKB_FRAGS 18
#define MAX_PENDING_REQS 256
#define PKT_PROT_LEN 128
#define NET_SKB_PAD 32
#define NET_IP_ALIGN 2
#define XEN_NETIF_TX_RING_SIZE 1024
#define XEN_NETIF_EXTRA_TYPE_MAX 4
#define XEN_NETIF_EXTRA_TYPE_GSO 1
#define XEN_NETTXF_extra_info (1 << 0)
#define INVALID_PENDING_IDX 0xFFFF
#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define DOMID_SELF 0
#define ETH_HLEN 14
#define GFP_ATOMIC 0
#define __GFP_NOWARN 0
#define GNTCOPY_source_gref 0

typedef unsigned int RING_IDX;
typedef unsigned int pending_ring_idx_t;
typedef uint16_t u16;
typedef uint8_t u8;

struct sk_buff {
    char data[0];
    struct {
        int nr_frags;
        struct {
            u16 pending_idx;
        } frags[0];
    } *shinfo;
};

struct page {};
struct xenvif {
    struct {
        RING_IDX req_cons;
        struct {
            RING_IDX req_prod;
        } *sring;
    } tx;
    unsigned int remaining_credit;
    void* dev;
    int domid;
};

struct xen_netif_tx_request {
    u16 size;
    u16 flags;
    u16 gref;
    u16 offset;
};

struct xen_netif_extra_info {
    u8 type;
};

struct xen_netbk {
    struct gnttab_copy* tx_copy_ops;
    u16* pending_ring;
    unsigned int pending_cons;
    struct {
        struct xen_netif_tx_request req;
        struct xenvif* vif;
    } *pending_tx_info;
    void* net_schedule_list;
    void* tx_queue;
};

struct gnttab_copy {
    struct {
        union {
            unsigned int ref;
        } u;
        int domid;
        unsigned int offset;
    } source;
    struct {
        union {
            unsigned int gmfn;
        } u;
        int domid;
        unsigned int offset;
    } dest;
    unsigned int len;
    unsigned int flags;
};

static inline void rmb(void) {}
static inline int list_empty(void *list) { return 1; }
static inline int tx_credit_exceeded(struct xenvif *vif, u16 size) { return 0; }
#define RING_FINAL_CHECK_FOR_REQUESTS(x, y) (y = 0)
#define RING_GET_REQUEST(x, y) (NULL)
#define netdev_err(dev, fmt, ...) 
#define netdev_dbg(dev, fmt, ...) 
#define unlikely(x) (x)
#define __skb_put(skb, len) 
#define skb_reserve(skb, len) 
#define skb_shinfo(skb) ((struct {int nr_frags; struct {u16 pending_idx;} frags[0];}*)NULL)
#define __skb_queue_tail(queue, skb) 
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

static inline int nr_pending_reqs(struct xen_netbk *netbk) { return 0; }
static struct xenvif *poll_net_schedule_list(struct xen_netbk *netbk) { return NULL; }
static void netbk_fatal_tx_err(struct xenvif *vif) {}
static void netbk_tx_err(struct xenvif *vif, struct xen_netif_tx_request *txreq, RING_IDX idx) {}
static void xenvif_put(struct xenvif *vif) {}
static int xen_netbk_get_extras(struct xenvif *vif, struct xen_netif_extra_info *extras, int work_to_do) { return 0; }
static int netbk_count_requests(struct xenvif *vif, struct xen_netif_tx_request *txreq, struct xen_netif_tx_request *txfrags, int work_to_do) { return 0; }
static pending_ring_idx_t pending_index(pending_ring_idx_t index) { return 0; }
static struct page *xen_netbk_alloc_page(struct xen_netbk *netbk, struct sk_buff *skb, u16 pending_idx) { return NULL; }
static int netbk_set_skb_gso(struct xenvif *vif, struct sk_buff *skb, struct xen_netif_extra_info *gso) { return 0; }
static void frag_set_pending_idx(void *frag, u16 pending_idx) {}
static struct gnttab_copy *xen_netbk_get_requests(struct xen_netbk *netbk, struct xenvif *vif, struct sk_buff *skb, struct xen_netif_tx_request *txfrags, struct gnttab_copy *gop) { return NULL; }
static void xen_netbk_check_rx_xenvif(struct xenvif *vif) {}
static void* virt_to_mfn(void* addr) { return NULL; }
static void* page_address(struct page* page) { return NULL; }
static struct sk_buff* alloc_skb(int size, int flags) { return NULL; }
static void kfree_skb(struct sk_buff* skb) {}