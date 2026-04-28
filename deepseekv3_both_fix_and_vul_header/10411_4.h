#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint64_t sci_t;
typedef uint16_t u16;

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    void *dev;
    char cb[32];
    struct aead_request *req;
};

struct net_device {
    // minimal definition
};

struct scatterlist {
    // minimal definition
};

struct aead_request {
    // minimal definition
};

struct macsec_skb_cb {
    bool valid;
    bool has_sci;
    struct aead_request *req;
};

struct macsec_rx_sa {
    struct {
        void *tfm;
    } key;
};

struct macsec_secy {
    u16 icv_len;
};

struct macsec_eth_header {
    uint8_t tci_an;
    uint32_t packet_number;
};

#define MAX_SKB_FRAGS 16
#define MACSEC_TCI_E 0x08
#define GFP_ATOMIC 0
#define ENOMEM 12
#define EINPROGRESS 115
#define EBADMSG 74

static inline struct macsec_skb_cb *macsec_skb_cb(struct sk_buff *skb)
{
    return (struct macsec_skb_cb *)skb->cb;
}

static inline int macsec_hdr_len(bool has_sci)
{
    return has_sci ? 16 : 8;
}

static inline uint32_t ntohl(uint32_t netlong)
{
    return ((netlong & 0xFF) << 24) | 
           ((netlong & 0xFF00) << 8) |
           ((netlong & 0xFF0000) >> 8) |
           ((netlong & 0xFF000000) >> 24);
}

static struct aead_request *macsec_alloc_req(void *tfm, unsigned char **iv, struct scatterlist **sg, ...)
{
    return NULL;
}

static void macsec_fill_iv(unsigned char *iv, sci_t sci, uint32_t pn)
{
}

static void macsec_decrypt_done(void *req, int err)
{
}

static void *ERR_PTR(long error)
{
    return (void *)error;
}

static void kfree_skb(struct sk_buff *skb)
{
}

static void dev_hold(struct net_device *dev)
{
}

static void dev_put(struct net_device *dev)
{
}

static void aead_request_free(struct aead_request *req)
{
}

static int crypto_aead_decrypt(struct aead_request *req)
{
    return 0;
}

static void aead_request_set_crypt(struct aead_request *req, struct scatterlist *src, struct scatterlist *dst, unsigned int cryptlen, unsigned char *iv)
{
}

static void aead_request_set_ad(struct aead_request *req, unsigned int assoclen)
{
}

static void aead_request_set_callback(struct aead_request *req, unsigned int flags, void (*complete)(void *req, int err), void *data)
{
}

static void sg_init_table(struct scatterlist *sg, unsigned int nents)
{
}

static int skb_to_sgvec(struct sk_buff *skb, struct scatterlist *sg, int offset, int len)
{
    return 0;
}

static struct sk_buff *skb_share_check(struct sk_buff *skb, int pri)
{
    return skb;
}

static struct sk_buff *skb_unshare(struct sk_buff *skb, int pri)
{
    return skb;
}

static int skb_cow_data(struct sk_buff *skb, int tailbits, struct sk_buff **trailer)
{
    return 0;
}