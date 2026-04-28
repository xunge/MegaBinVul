#include <string.h>

struct xfrm_id {
    unsigned char data[16];
};

struct xfrm_selector {
    unsigned char data[64];
};

struct xfrm_lifetime_cfg {
    unsigned char data[32];
};

struct xfrm_lifetime_cur {
    unsigned char data[24];
};

struct xfrm_stats {
    unsigned char data[24];
};

struct xfrm_address {
    unsigned char data[16];
};

struct xfrm_state {
    struct xfrm_id id;
    struct xfrm_selector sel;
    struct xfrm_lifetime_cfg lft;
    struct xfrm_lifetime_cur curlft;
    struct xfrm_stats stats;
    struct {
        struct xfrm_address saddr;
        unsigned int mode;
        unsigned int replay_window;
        unsigned int reqid;
        unsigned short family;
        unsigned int flags;
    } props;
    struct {
        unsigned int seq;
    } km;
};

struct xfrm_usersa_info {
    struct xfrm_id id;
    struct xfrm_selector sel;
    struct xfrm_lifetime_cfg lft;
    struct xfrm_lifetime_cur curlft;
    struct xfrm_stats stats;
    struct xfrm_address saddr;
    unsigned int mode;
    unsigned int replay_window;
    unsigned int reqid;
    unsigned short family;
    unsigned int flags;
    unsigned int seq;
};