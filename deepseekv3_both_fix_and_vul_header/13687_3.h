#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define ETH_P_IP 0x0800
#define GFP_KERNEL 0
#define ENOMEM 12
#define EOPNOTSUPP 95

typedef uint16_t __be16;
typedef uint32_t u32;
typedef uint8_t u8;

struct list_head {
    struct list_head *next, *prev;
};

struct netlink_ext_ack;

struct tc_u32_key {
    u32 val;
    u32 mask;
};

struct tc_u32_sel {
    struct tc_u32_key keys[1];
    u32 classid;
};

struct tc_cls_u32_knode {
    struct tc_u32_sel *sel;
    struct tc_u32_sel *res;
    u32 handle;
};

struct nfp_abm_link {
    struct nfp_abm *abm;
    struct list_head dscp_map;
};

struct nfp_abm_u32_match {
    struct list_head list;
    u32 handle;
    u32 band;
    u8 mask;
    u8 val;
};

struct nfp_abm {
    // Placeholder for actual fields
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

static inline __be16 htons(uint16_t hostshort) {
    return (hostshort >> 8) | (hostshort << 8);
}

static inline uint32_t be32_to_cpu(uint32_t be) {
    return ((be >> 24) & 0xff) | ((be >> 8) & 0xff00) | ((be << 8) & 0xff0000) | ((be << 24) & 0xff000000);
}

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

#define NL_SET_ERR_MSG_MOD(extack, msg) ((void)0)

static int nfp_abm_u32_check_knode(struct nfp_abm *abm, struct tc_cls_u32_knode *knode, __be16 proto, struct netlink_ext_ack *extack);
static int nfp_abm_update_band_map(struct nfp_abm_link *alink);
static void nfp_abm_u32_knode_delete(struct nfp_abm_link *alink, struct tc_cls_u32_knode *knode);