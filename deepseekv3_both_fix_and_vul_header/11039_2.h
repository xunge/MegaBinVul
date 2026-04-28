#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14
#define EMSGSIZE 90
#define EOPNOTSUPP 95
#define GFP_KERNEL 0

struct nla_policy {
    unsigned int type;
    unsigned int len;
};

struct mwifiex_private {
    struct {
        struct {
            void *dev;
        } *adapter;
    };
};

struct mwifiex_ds_misc_cmd {
    unsigned int len;
    unsigned char cmd[0];
};

struct wiphy;
struct wireless_dev {
    struct net_device *netdev;
};
struct sk_buff;
struct nlattr;
struct net_device;

#define MWIFIEX_TM_ATTR_MAX 2
#define MWIFIEX_TM_ATTR_CMD 1
#define MWIFIEX_TM_ATTR_DATA 2
#define MWIFIEX_TM_CMD_HOSTCMD 1

static const struct nla_policy mwifiex_tm_policy[MWIFIEX_TM_ATTR_MAX + 1] = {0};

static inline struct mwifiex_private *mwifiex_netdev_get_priv(struct net_device *dev) { return NULL; }
static int mwifiex_send_cmd(struct mwifiex_private *priv, int cmd_no, int cmd_action, 
                          unsigned int cmd_oid, void *data_buf, bool async) { return 0; }
static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void kfree(void *ptr) { free(ptr); }
static void kfree_skb(struct sk_buff *skb) { free(skb); }
static int nla_parse(struct nlattr *tb[], int maxtype, void *data, int len,
                    const struct nla_policy *policy, void *extack) { return 0; }
static unsigned int nla_len(const struct nlattr *nla) { return 0; }
static void *nla_data(const struct nlattr *nla) { return NULL; }
static unsigned int nla_get_u32(const struct nlattr *nla) { return 0; }
static int nla_put(struct sk_buff *skb, int attrtype, int attrlen, const void *data) { return 0; }
static struct sk_buff *cfg80211_testmode_alloc_reply_skb(struct wiphy *wiphy, int len) { return NULL; }
static int cfg80211_testmode_reply(struct sk_buff *skb) { return 0; }
static void dev_err(void *dev, const char *fmt, ...) {}