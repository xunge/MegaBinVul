#include <stdint.h>
#include <errno.h>

#define NUM_NL80211_REKEY_DATA 3
#define MAX_NL80211_REKEY_DATA 3
#define NL80211_REPLAY_CTR_LEN 8
#define NL80211_KEK_LEN 16
#define NL80211_KCK_LEN 16
#define NL80211_ATTR_REKEY_DATA 1
#define NL80211_REKEY_DATA_REPLAY_CTR 0
#define NL80211_REKEY_DATA_KEK 1
#define NL80211_REKEY_DATA_KCK 2

typedef uint8_t u8;

struct nlattr {
    unsigned short nla_len;
    unsigned short nla_type;
};

struct sk_buff;
struct net_device {
    struct wireless_dev *ieee80211_ptr;
};

struct wireless_dev {
    void *current_bss;
};

struct cfg80211_registered_device {
    struct {
        int (*set_rekey_data)(struct cfg80211_registered_device *,
                             struct net_device *,
                             struct cfg80211_gtk_rekey_data *);
    } *ops;
};

struct genl_info {
    void *user_ptr[2];
    struct nlattr **attrs;
    void *extack;
};

struct cfg80211_gtk_rekey_data {
    const u8 *kek;
    const u8 *kck;
    const u8 *replay_ctr;
};

struct nla_policy {
    unsigned int type;
    unsigned int len;
};

extern const struct nla_policy nl80211_rekey_policy[];
extern int nla_parse_nested(struct nlattr *tb[], int maxtype, struct nlattr *nla,
                          const struct nla_policy *policy, void *extack);
extern u8 *nla_data(const struct nlattr *nla);
extern int nla_len(const struct nlattr *nla);
extern void wdev_lock(struct wireless_dev *wdev);
extern void wdev_unlock(struct wireless_dev *wdev);
extern int rdev_set_rekey_data(struct cfg80211_registered_device *rdev,
                             struct net_device *dev,
                             struct cfg80211_gtk_rekey_data *data);