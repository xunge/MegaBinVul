#include <stdint.h>
#include <cstddef>
#include <cstring>

struct tcf_proto;
struct sk_buff {
    unsigned char *tail;
    unsigned char *data;
    int len;
};
struct rtattr {
    unsigned short rta_len;
};
struct tcmsg {
    uint32_t tcm_handle;
};
struct tcf_exts {
    // minimal definition to make it complete
    int dummy;
};
struct tcf_ext_map {
    // minimal definition to make it complete
    int dummy;
};
struct rsvp_filter {
    unsigned long handle;
    struct rsvp_session *sess;
    uint32_t spi;
    uint8_t tunnelhdr;
    uint8_t src[16];
    struct {
        uint32_t classid;
    } res;
    struct tcf_exts exts;
};
struct rsvp_session {
    uint32_t dst;
    uint32_t dpi;
    uint8_t protocol;
    uint32_t tunnelid;
};
struct tc_rsvp_pinfo {
    uint32_t dpi;
    uint32_t spi;
    uint8_t protocol;
    uint8_t tunnelhdr;
    uint32_t tunnelid;
    uint32_t pad;
};

extern const struct tcf_ext_map rsvp_ext_map;
int tcf_exts_dump(struct sk_buff *skb, struct tcf_exts *exts, const struct tcf_ext_map *map);
int tcf_exts_dump_stats(struct sk_buff *skb, struct tcf_exts *exts, const struct tcf_ext_map *map);
void skb_trim(struct sk_buff *skb, int len);

#define TCA_OPTIONS 0
#define TCA_RSVP_DST 1
#define TCA_RSVP_PINFO 2
#define TCA_RSVP_CLASSID 3
#define TCA_RSVP_SRC 4

#define RTA_PUT(skb, attrtype, attrlen, data) \
    do { \
        struct rtattr *rta = (struct rtattr*)skb->tail; \
        rta->rta_len = (attrlen) + sizeof(struct rtattr); \
        skb->tail += sizeof(struct rtattr); \
        if (data) memcpy(skb->tail, (data), (attrlen)); \
        skb->tail += (attrlen); \
    } while(0)