#include <stdint.h>
#include <stddef.h>

#define CHECK_FLAG(flags, flag) ((flags) & (flag))
#define ATTR_FLAG_BIT(attr) (1 << (attr))

enum {
    PEER_CAP_RESTART_RCV,
    BGP_ATTR_MP_REACH_NLRI,
    BGP_ATTR_MP_UNREACH_NLRI,
    BGP_ATTR_ORIGIN,
    BGP_ATTR_AS_PATH,
    BGP_ATTR_NEXT_HOP,
    BGP_ATTR_LOCAL_PREF,
    BGP_PEER_IBGP
};

enum bgp_attr_parse_ret {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_WITHDRAW
};

enum {
    EC_BGP_MISSING_ATTRIBUTE
};

struct peer {
    uint32_t cap;
    int sort;
    char *host;
};

struct attr {
    uint8_t flag;
};

typedef uint16_t bgp_size_t;

extern const char *attr_str[];

void flog_warn(int ec, const char *fmt, ...);
const char *lookup_msg(const char *str[], int type, void *null);