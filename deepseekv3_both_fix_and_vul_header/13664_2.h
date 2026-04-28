#include <stdint.h>
#include <stddef.h>

#define BIT(nr) (1UL << (nr))
#define GFP_KERNEL 0
#define NLMSG_DEFAULT_SIZE 1024
#define NL80211_IFTYPE_AP 2
#define NL80211_CMD_GET_FTM_RESPONDER_STATS 0
#define NL80211_ATTR_IFINDEX 0
#define NL80211_ATTR_FTM_RESPONDER_STATS 0
#define NL80211_FTM_STATS_PAD 0
#define NL80211_FTM_STATS_SUCCESS_NUM 0
#define NL80211_FTM_STATS_PARTIAL_NUM 1
#define NL80211_FTM_STATS_FAILED_NUM 2
#define NL80211_FTM_STATS_ASAP_NUM 3
#define NL80211_FTM_STATS_NON_ASAP_NUM 4
#define NL80211_FTM_STATS_TOTAL_DURATION_MSEC 5
#define NL80211_FTM_STATS_UNKNOWN_TRIGGERS_NUM 6
#define NL80211_FTM_STATS_RESCHEDULE_REQUESTS_NUM 7
#define NL80211_FTM_STATS_OUT_OF_WINDOW_TRIGGERS_NUM 8

#define EOPNOTSUPP 95
#define ENODATA 61
#define ENOMEM 12
#define ENOBUFS 105

struct sk_buff {
    void *data;
};

struct genl_info {
    void *user_ptr[2];
    uint32_t snd_portid;
    uint32_t snd_seq;
};

struct cfg80211_registered_device {
    // dummy structure
};

struct net_device {
    struct wireless_dev *ieee80211_ptr;
    int ifindex;
};

struct wireless_dev {
    int iftype;
    int beacon_interval;
};

struct nlattr {
    // dummy structure
};

struct cfg80211_ftm_responder_stats {
    uint32_t filled;
    uint32_t success_num;
    uint32_t partial_num;
    uint32_t failed_num;
    uint32_t asap_num;
    uint32_t non_asap_num;
    uint64_t total_duration_ms;
    uint32_t unknown_triggers_num;
    uint32_t reschedule_requests_num;
    uint32_t out_of_window_triggers_num;
};

static inline int rdev_get_ftm_responder_stats(struct cfg80211_registered_device *rdev,
                                             struct net_device *dev,
                                             struct cfg80211_ftm_responder_stats *ftm_stats) {
    return 0;
}

static inline struct sk_buff *nlmsg_new(size_t size, int flags) {
    return NULL;
}

static inline void *nl80211hdr_put(struct sk_buff *skb, uint32_t portid, uint32_t seq,
                                  int flags, int cmd) {
    return NULL;
}

static inline int nla_put_u32(struct sk_buff *skb, int attrtype, uint32_t value) {
    return 0;
}

static inline struct nlattr *nla_nest_start_noflag(struct sk_buff *skb, int attrtype) {
    return NULL;
}

static inline int nla_put_u64_64bit(struct sk_buff *skb, int attrtype, uint64_t value, int padattr) {
    return 0;
}

static inline void nla_nest_end(struct sk_buff *skb, struct nlattr *attr) {}

static inline void genlmsg_end(struct sk_buff *skb, void *hdr) {}

static inline int genlmsg_reply(struct sk_buff *skb, struct genl_info *info) {
    return 0;
}

static inline void nlmsg_free(struct sk_buff *skb) {}