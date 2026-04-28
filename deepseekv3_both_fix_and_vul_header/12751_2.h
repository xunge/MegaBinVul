#include <stdint.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>

#define XFRM_MAX_DEPTH 6
#define EINVAL 22
#define IS_ENABLED(x) 1
#define CONFIG_IPV6 1
#define IPSEC_PROTO_ANY 255

typedef uint16_t u16;

enum {
    XFRM_MODE_TRANSPORT = 0,
    XFRM_MODE_TUNNEL = 1,
    XFRM_MODE_ROUTEOPTIMIZATION = 2,
    XFRM_MODE_IN_TRIGGER = 3,
    XFRM_MODE_BEET = 4,
    XFRM_MODE_MAX = 5
};

struct xfrm_user_tmpl {
    u16 family;
    u16 mode;
    struct {
        uint8_t proto;
    } id;
};