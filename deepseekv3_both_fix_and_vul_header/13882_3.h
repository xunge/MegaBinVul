#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;
typedef int32_t s32;

struct wiphy;
struct wireless_dev {
    int dummy;
};

struct cfg80211_mgmt_tx_params {
    struct ieee80211_channel *chan;
    const u8 *buf;
    size_t len;
};

struct ieee80211_channel {
    u32 center_freq;
};

struct ieee80211_mgmt {
    uint16_t frame_control;
    uint8_t da[6];
    uint8_t bssid[6];
};

struct brcmf_cfg80211_info {
    struct {
        struct {
            struct brcmf_cfg80211_vif *vif;
        } bss_idx[2];
    } p2p;
};

struct brcmf_cfg80211_vif {
    struct wireless_dev wdev;
    struct brcmf_if *ifp;
};

struct brcmf_if;
struct net_device;

struct brcmf_fil_action_frame_le {
    uint32_t packet_id;
    uint8_t da[6];
    uint16_t len;
    uint8_t data[];
};

struct brcmf_fil_af_params_le {
    uint8_t bssid[6];
    uint32_t channel;
    struct brcmf_fil_action_frame_le action_frame;
};

#define BRCMF_FIL_ACTION_FRAME_SIZE 2500
#define DOT11_MGMT_HDR_LEN 24
#define DOT11_BCN_PRB_FIXED_LEN 12
#define ETH_ALEN 6
#define GFP_KERNEL 0
#define EPERM 1
#define EINVAL 22
#define ENOMEM 12
#define TRACE 0
#define BRCMF_VNDR_IE_PRBRSP_FLAG 0
#define P2PAPI_BSSCFG_PRIMARY 0
#define P2PAPI_BSSCFG_DEVICE 1
#define BRCMF_C_GET_CHANNEL 0

static inline int ieee80211_is_mgmt(uint16_t fc) { return (fc & 0x000C) == 0x0000; }
static inline int ieee80211_is_probe_resp(uint16_t fc) { return (fc & 0x00FF) == 0x0050; }
static inline int ieee80211_is_action(uint16_t fc) { return (fc & 0x00FF) == 0x00D0; }
static inline int ieee80211_frequency_to_channel(uint32_t freq) { return (freq - 2407) / 5; }

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define cpu_to_le16(x) (x)
#define cpu_to_le32(x) (x)
#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }

static inline struct brcmf_cfg80211_info *wiphy_to_cfg(struct wiphy *wiphy) { return NULL; }
static inline struct net_device *cfg_to_ndev(struct brcmf_cfg80211_info *cfg) { return NULL; }
static inline bool brcmf_p2p_send_action_frame(struct brcmf_cfg80211_info *cfg, struct net_device *ndev, struct brcmf_fil_af_params_le *af_params) { return false; }
static inline int brcmf_vif_set_mgmt_ie(struct brcmf_cfg80211_vif *vif, int flag, const uint8_t *buf, size_t len) { return 0; }
static inline int brcmf_fil_cmd_int_get(struct brcmf_if *ifp, int cmd, uint32_t *data) { return 0; }
static inline void brcmf_dbg(int level, const char *fmt, ...) {}
static inline void brcmf_err(const char *fmt, ...) {}
static inline void brcmf_dbg_hex_dump(bool trace, const void *buf, size_t len, const char *fmt, ...) {}
static inline void cfg80211_mgmt_tx_status(struct wireless_dev *wdev, uint64_t cookie, const uint8_t *buf, size_t len, bool ack, int gfp) {}