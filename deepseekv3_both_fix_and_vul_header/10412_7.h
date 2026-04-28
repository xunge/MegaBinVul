#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define ETH_ALEN 6
#define ETH_HLEN 14
#define MAX_SKB_FRAGS 18
#define MACSEC_NEEDED_HEADROOM 32
#define MACSEC_NEEDED_TAILROOM 32
#define GFP_ATOMIC 0
#define EINVAL 22
#define ENOMEM 12
#define ENOLINK 67
#define EINPROGRESS 115

typedef uint32_t u32;

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned int headroom;
    unsigned int tailroom;
    void *dev;
    char cb[48];
};

struct net_device {
    unsigned int mtu;
};

struct scatterlist {
    unsigned long page_link;
    unsigned int offset;
    unsigned int length;
};

struct aead_request {
    void *tfm;
};

struct ethhdr {
    unsigned char h_dest[ETH_ALEN];
    unsigned char h_source[ETH_ALEN];
};

struct macsec_eth_header {
    unsigned char h_dest[ETH_ALEN];
    unsigned char h_source[ETH_ALEN];
};

struct macsec_tx_sa {
    struct {
        void *tfm;
    } key;
};

struct macsec_tx_sc {
    struct macsec_tx_sa *sa[4];
    unsigned int encoding_sa;
    bool encrypt;
};

struct macsec_secy {
    struct macsec_tx_sc tx_sc;
    unsigned int icv_len;
    bool operational;
    void *sci;
};

struct pcpu_secy_stats {
    struct {
        unsigned long OutPktsTooLong;
    } stats;
    unsigned long syncp;
};

struct macsec_dev {
    struct macsec_secy secy;
    struct net_device *real_dev;
    void *stats;
};

struct macsec_skb_cb {
    struct aead_request *req;
    struct macsec_tx_sa *tx_sa;
};

static inline struct macsec_skb_cb *macsec_skb_cb(struct sk_buff *skb)
{
    return (struct macsec_skb_cb *)skb->cb;
}

static inline void *this_cpu_ptr(void *ptr)
{
    return ptr;
}

static inline void u64_stats_update_begin(unsigned long *syncp) {}
static inline void u64_stats_update_end(unsigned long *syncp) {}

static inline void dev_hold(struct net_device *dev) {}
static inline void dev_put(struct net_device *dev) {}

static inline struct macsec_dev *macsec_priv(struct net_device *dev)
{
    return (struct macsec_dev *)dev;
}

static inline struct macsec_tx_sa *macsec_txsa_get(struct macsec_tx_sa *sa)
{
    return sa;
}

static inline void macsec_txsa_put(struct macsec_tx_sa *sa) {}

static inline void consume_skb(struct sk_buff *skb) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline struct sk_buff *skb_copy_expand(struct sk_buff *skb, int headroom, int tailroom, int gfp)
{
    return NULL;
}
static inline struct sk_buff *skb_unshare(struct sk_buff *skb, int gfp)
{
    return NULL;
}

static inline struct ethhdr *eth_hdr(struct sk_buff *skb)
{
    return (struct ethhdr *)skb->data;
}

static inline void *skb_push(struct sk_buff *skb, unsigned int len)
{
    return NULL;
}

static inline void skb_put(struct sk_buff *skb, unsigned int len) {}

static inline int skb_cow_data(struct sk_buff *skb, int tailbits, struct sk_buff **trailer)
{
    return 0;
}

static inline void sg_init_table(struct scatterlist *sg, unsigned int nents) {}
static inline int skb_to_sgvec(struct sk_buff *skb, struct scatterlist *sg, int offset, int len)
{
    return 0;
}

static inline struct aead_request *macsec_alloc_req(void *tfm, unsigned char **iv, struct scatterlist **sg, ...)
{
    return NULL;
}

static inline void macsec_fill_iv(unsigned char *iv, void *sci, u32 pn) {}

static inline void aead_request_set_crypt(struct aead_request *req, struct scatterlist *src, struct scatterlist *dst, unsigned int cryptlen, void *iv) {}
static inline void aead_request_set_ad(struct aead_request *req, unsigned int assoclen) {}
static inline void aead_request_set_callback(struct aead_request *req, unsigned int flags, void (*callback)(void *), void *data) {}
static inline void aead_request_free(struct aead_request *req) {}
static inline int crypto_aead_encrypt(struct aead_request *req)
{
    return 0;
}

static inline bool send_sci(struct macsec_secy *secy)
{
    return false;
}

static inline size_t macsec_extra_len(bool sci_present)
{
    return 0;
}

static inline u32 tx_sa_update_pn(struct macsec_tx_sa *tx_sa, struct macsec_secy *secy)
{
    return 0;
}

static inline void macsec_fill_sectag(struct macsec_eth_header *hh, struct macsec_secy *secy, u32 pn, bool sci_present) {}
static inline void macsec_set_shortlen(struct macsec_eth_header *hh, size_t len) {}
static inline size_t macsec_hdr_len(bool sci_present)
{
    return 0;
}

static inline void macsec_encrypt_done(void *data) {}

static inline unsigned int skb_headroom(const struct sk_buff *skb)
{
    return skb->headroom;
}

static inline unsigned int skb_tailroom(const struct sk_buff *skb)
{
    return skb->tailroom;
}

#define ERR_PTR(err) ((void *)(long)(err))
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)