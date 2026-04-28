#include <string.h>

struct xfrm_selector {
    unsigned short family;
};

struct xfrm_lifetime {
};

struct xfrm_policy {
    struct xfrm_selector selector;
    struct xfrm_lifetime lft;
    struct xfrm_lifetime curlft;
    unsigned int priority;
    unsigned int index;
    unsigned short family;
    unsigned char action;
    unsigned char flags;
};

struct xfrm_userpolicy_info {
    struct xfrm_selector sel;
    struct xfrm_lifetime lft;
    struct xfrm_lifetime curlft;
    unsigned int priority;
    unsigned int index;
    unsigned char dir;
    unsigned char action;
    unsigned char flags;
    unsigned char share;
};

#define XFRM_SHARE_ANY 0