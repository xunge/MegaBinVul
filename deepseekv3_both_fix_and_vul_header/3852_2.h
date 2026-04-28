#include <stdint.h>
#include <string.h>

#define NFPROTO_IPV4 2
#define NFPROTO_IPV6 10
#define CTA_TUPLE_MAX 10
#define CTA_TUPLE_IP 1
#define CTA_TUPLE_PROTO 2
#define CTA_TUPLE_ZONE 3
#define CTA_TUPLE_REPLY 4
#define CTA_IP_SRC 1
#define CTA_IP_DST 2
#define CTA_PROTO_NUM 3
#define IP_CT_DIR_ORIGINAL 0
#define IP_CT_DIR_REPLY 1
#define EOPNOTSUPP 95
#define EINVAL 22

#define CTA_FILTER_FLAG(flag) (1 << (flag - 1))
#define ALL_CTA_PROTO 0xFFFF

typedef uint32_t u32;
typedef uint8_t u_int8_t;
typedef uint32_t u_int32_t;

struct nlattr;
struct nf_conntrack_zone;
struct nf_conntrack_tuple {
    struct {
        u_int8_t l3num;
    } src;
    struct {
        u_int8_t dir;
    } dst;
};

extern int nla_parse_nested_deprecated(struct nlattr *tb[], int maxtype, const struct nlattr *nla, const void *policy, void *extack);
extern int ctnetlink_parse_tuple_ip(const struct nlattr *attr, struct nf_conntrack_tuple *tuple, u_int32_t flags);
extern int ctnetlink_parse_tuple_proto(const struct nlattr *attr, struct nf_conntrack_tuple *tuple, u_int32_t flags);
extern int ctnetlink_parse_tuple_zone(const struct nlattr *attr, u32 type, struct nf_conntrack_zone *zone);

static const void *tuple_nla_policy[CTA_TUPLE_MAX+1];