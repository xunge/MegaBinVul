#include <stdint.h>
#include <errno.h>

#define XFRM_SHARE_ANY 0
#define XFRM_SHARE_SESSION 1
#define XFRM_SHARE_USER 2
#define XFRM_SHARE_UNIQUE 3

#define XFRM_POLICY_ALLOW 0
#define XFRM_POLICY_BLOCK 1

#define AF_INET 2
#define AF_INET6 10

#define XFRM_POLICY_MAX 0x7
#define EINVAL 22
#define EAFNOSUPPORT 97

#define IS_ENABLED(x) 0
#define CONFIG_IPV6 0

struct xfrm_userpolicy_info {
    uint8_t share;
    uint8_t action;
    uint8_t dir;
    uint32_t index;
    struct {
        uint8_t family;
        uint8_t prefixlen_d;
        uint8_t prefixlen_s;
    } sel;
};

extern int verify_policy_dir(uint8_t dir);