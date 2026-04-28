#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/ethernet.h>

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((head)->next); &pos->member != (head); pos = (typeof(pos))(pos->member.next))

#define GFP_KERNEL 0
#define EOPNOTSUPP 95
#define ENOMEM 12

struct nfp_abm_link {
    struct list_head dscp_map;
    void *abm;
};

struct tc_cls_u32_knode {
    unsigned int handle;
    struct {
        struct {
            uint32_t val;
            uint32_t mask;
        } keys[0];
    } *sel;
    struct {
        uint32_t classid;
    } *res;
};

struct netlink_ext_ack {
    const char *_msg;
};

#define NL_SET_ERR_MSG_MOD(extack, msg) ((extack)->_msg = msg)

typedef uint16_t __be16;
typedef uint8_t u8;
typedef uint32_t u32;

struct nfp_abm_u32_match {
    struct list_head list;
    u32 handle;
    u32 band;
    u8 mask;
    u8 val;
};

extern int nfp_abm_u32_check_knode(struct nfp_abm_link *alink,
                                  struct tc_cls_u32_knode *knode,
                                  __be16 proto, struct netlink_ext_ack *extack);
extern void nfp_abm_u32_knode_delete(struct nfp_abm_link *alink,
                                    struct tc_cls_u32_knode *knode);
extern int nfp_abm_update_band_map(struct nfp_abm_link *alink);