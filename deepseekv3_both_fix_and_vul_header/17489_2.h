#include <stdint.h>

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

typedef uint16_t u16;

struct flowi;
struct xfrm_policy {
    int xfrm_nr;
    int action;
    int type;
    int if_id;
};

#define XFRM_POLICY_ALLOW 0
#define XFRM_POLICY_TYPE_MAIN 0
#define XFRM_POLICY_OUT 0
#define CONFIG_XFRM_SUB_POLICY 1

static inline void xfrm_pols_put(struct xfrm_policy **pols, int num_pols) {}
static inline void *xp_net(struct xfrm_policy *p) { return 0; }
static inline struct xfrm_policy *xfrm_policy_lookup_bytype(void *net, int type, const struct flowi *fl, u16 family, int dir, int if_id) { return 0; }