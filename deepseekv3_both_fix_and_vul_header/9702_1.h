#define NL80211_IFTYPE_ADHOC 1
#define NL80211_IFTYPE_STATION 2
#define EOPNOTSUPP 95

struct net_device {
    struct wireless_dev *ieee80211_ptr;
};

struct wireless_dev {
    int iftype;
};

struct iw_request_info {};
struct iw_point {
    int flags;
    int length;
};

extern int cfg80211_ibss_wext_giwessid(struct net_device *dev,
                   struct iw_request_info *info,
                   struct iw_point *data, char *ssid);
extern int cfg80211_mgd_wext_giwessid(struct net_device *dev,
                   struct iw_request_info *info,
                   struct iw_point *data, char *ssid);