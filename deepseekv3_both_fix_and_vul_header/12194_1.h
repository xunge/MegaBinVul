#include <stdint.h>
#include <stddef.h>

#define CHECK_FLAG(flag, bit) ((flag) & (bit))
#define ATTR_FLAG_BIT(attr) (1 << (attr))

enum {
    BGP_ATTR_PARSE_PROCEED,
    BGP_ATTR_PARSE_WITHDRAW
};

enum {
    PEER_CAP_RESTART_RCV,
};

enum {
    BGP_ATTR_ORIGIN,
    BGP_ATTR_AS_PATH,
    BGP_ATTR_NEXT_HOP,
    BGP_ATTR_LOCAL_PREF,
    BGP_ATTR_MP_REACH_NLRI,
    BGP_ATTR_MP_UNREACH_NLRI
};

enum {
    BGP_PEER_IBGP
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
extern void flog_warn(int code, const char *format, ...);
extern const char *lookup_msg(const char *table[], int key, const char *default_msg);