#include <stdint.h>
#include <stddef.h>

#define CHECK_FLAG(flags, flag) ((flags) & (flag))
#define ATTR_FLAG_BIT(bit) (1 << (bit))

enum bgp_attr_parse_ret {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_WITHDRAW,
    BGP_ATTR_PARSE_MISSING_MANDATORY
};

enum bgp_attr_type {
    BGP_ATTR_ORIGIN,
    BGP_ATTR_AS_PATH,
    BGP_ATTR_NEXT_HOP,
    BGP_ATTR_LOCAL_PREF,
    BGP_ATTR_MP_REACH_NLRI,
    BGP_ATTR_MP_UNREACH_NLRI
};

enum bgp_peer_sort {
    BGP_PEER_IBGP
};

enum peer_cap {
    PEER_CAP_RESTART_RCV
};

enum ec_bgp_errors {
    EC_BGP_MISSING_ATTRIBUTE
};

struct peer {
    uint32_t cap;
    enum bgp_peer_sort sort;
    char *host;
};

struct attr {
    uint8_t flag;
};

typedef uint16_t bgp_size_t;

extern const char *attr_str[];

void flog_warn(int error_code, const char *format, ...);
const char *lookup_msg(const char *msg_table[], int key, const char *default_msg);