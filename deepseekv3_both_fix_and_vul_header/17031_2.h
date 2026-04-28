#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

struct sk_buff;
struct nlattr;

struct genl_info {
    struct nlattr **attrs;
};

struct ieee80211_regdomain;

struct hwsim_new_radio_params {
    bool reg_strict;
    bool p2p_device;
    u32 channels;
    bool destroy_on_close;
    bool no_vif;
    char *hwname;
    bool use_chanctx;
    const char *reg_alpha2;
    const struct ieee80211_regdomain *regd;
};

extern u32 channels;
extern struct ieee80211_regdomain *hwsim_world_regdom_custom[1];
extern int mac80211_hwsim_new_radio(struct genl_info *info, struct hwsim_new_radio_params *param);

enum {
    HWSIM_ATTR_UNSPEC,
    HWSIM_ATTR_REG_STRICT_REG,
    HWSIM_ATTR_SUPPORT_P2P_DEVICE,
    HWSIM_ATTR_CHANNELS,
    HWSIM_ATTR_DESTROY_RADIO_ON_CLOSE,
    HWSIM_ATTR_NO_VIF,
    HWSIM_ATTR_RADIO_NAME,
    HWSIM_ATTR_USE_CHANCTX,
    HWSIM_ATTR_REG_HINT_ALPHA2,
    HWSIM_ATTR_REG_CUSTOM_REG,
    __HWSIM_ATTR_MAX,
};

#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static inline char *kasprintf(int flags, const char *fmt, ...) { return NULL; }
static inline void kfree(const void *objp) {}
static inline u32 nla_get_u32(const struct nlattr *attr) { return 0; }
static inline const void *nla_data(const struct nlattr *attr) { return NULL; }
static inline int nla_len(const struct nlattr *attr) { return 0; }