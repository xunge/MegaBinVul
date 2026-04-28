#include <linux/netlink.h>
#include <linux/xfrm.h>
#include <linux/errno.h>

struct nlattr;
struct xfrm_replay_state_esn;

static inline int xfrm_replay_state_esn_len(struct xfrm_replay_state_esn *esn);