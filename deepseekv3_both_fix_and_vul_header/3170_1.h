#include <linux/netdevice.h>
#include <linux/string.h>
#include <linux/wireless.h>
#include <linux/types.h>

struct wl_private {
    char StationName[32];
};

struct iw_request_info;
union iwreq_data;

#define DBG_FUNC(x)
#define DBG_ENTER(x)
#define DBG_LEAVE(x)
#define DbgInfo

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

static inline void wl_lock(struct wl_private *lp, unsigned long *flags) {}
static inline void wl_unlock(struct wl_private *lp, unsigned long *flags) {}
static inline void wl_apply(struct wl_private *lp) {}
static inline struct wl_private *wl_priv(struct net_device *dev) { return NULL; }