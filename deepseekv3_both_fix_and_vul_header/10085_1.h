#include <stddef.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <errno.h>

struct xfrm_replay_state_esn {
    __u32 replay_window;
    __u32 bmp_len;
};

static inline void *nla_data(const struct nlattr *nla) {
    return (void *)((char *)nla + NLA_HDRLEN);
}

static inline int nla_len(const struct nlattr *nla) {
    return nla->nla_len - NLA_HDRLEN;
}

int xfrm_replay_state_esn_len(struct xfrm_replay_state_esn *up);