#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef uint8_t u8;

#define NFC_SDP_ATTR_MAX 1
#define NFC_ATTR_DEVICE_INDEX 0
#define NFC_ATTR_LLC_SDP 1
#define NFC_SDP_ATTR_URI 0

struct sk_buff;
struct genl_info {
    struct nlattr **attrs;
    void *extack;
};

struct nfc_dev {
    struct {
        int dev;
    } dev;
    bool dep_link_up;
};

struct nfc_llcp_local {
    u8 sdreq_next_tid;
};

struct nlattr {
    int nla_len;
    char data[];
};

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct nfc_llcp_sdp_tlv {
    size_t tlv_len;
    struct hlist_node node;
};

static const void *nfc_sdp_genl_policy;

#define INIT_HLIST_HEAD(ptr) ((ptr)->first = NULL)
#define hlist_empty(ptr) ((ptr)->first == NULL)

static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h)
{
    n->next = h->first;
    if (h->first)
        h->first->pprev = &n->next;
    h->first = n;
    n->pprev = &h->first;
}

#define ENOLINK 1
#define ENODEV 2
#define EINVAL 3
#define ENOMEM 4

static inline u32 nla_get_u32(const struct nlattr *nla) { return *(u32*)nla->data; }
static inline size_t nla_len(const struct nlattr *nla) { return nla->nla_len; }
static inline void *nla_data(const struct nlattr *nla) { return (void*)nla->data; }
static inline void device_lock(void *dev) {}
static inline void device_unlock(void *dev) {}
static inline struct nfc_dev *nfc_get_device(u32 idx) { return NULL; }
static inline void nfc_put_device(struct nfc_dev *dev) {}
static inline struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev) { return NULL; }
static inline struct nfc_llcp_sdp_tlv *nfc_llcp_build_sdreq_tlv(u8 tid, char *uri, size_t uri_len) { return NULL; }
static inline int nfc_llcp_send_snl_sdreq(struct nfc_llcp_local *local, struct hlist_head *sdreq_list, size_t tlvs_len) { return 0; }
static inline int nla_parse_nested_deprecated(struct nlattr **attrs, int max, struct nlattr *nla, const void *policy, void *extack) { return 0; }

#define nla_for_each_nested(attr, nla, rem) \
    for (attr = (struct nlattr *)nla_data(nla), rem = nla_len(nla); \
         rem >= (int)sizeof(*attr) && nla_len(attr) >= sizeof(*attr) && nla_len(attr) <= rem; \
         attr = (struct nlattr *)((char *)attr + NLA_ALIGN(nla_len(attr))), rem -= NLA_ALIGN(nla_len(attr)))

#define NLA_ALIGN(len) (((len) + 3) & ~3)