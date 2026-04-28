#include <linux/netlink.h>
#include <linux/xfrm.h>
#include <errno.h>

struct nlattr;
struct xfrm_replay_state_esn;

extern int xfrm_replay_state_esn_len(struct xfrm_replay_state_esn *replay_esn);
extern void *nla_data(const struct nlattr *nla);
extern int nla_len(const struct nlattr *nla);