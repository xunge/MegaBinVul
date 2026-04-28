#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef int32_t s32;

struct brcmf_if {
    struct {
        struct brcmf_cfg80211_info *config;
    } *drvr;
};

struct brcmf_event_msg {
    uint32_t datalen;
    uint32_t event_code;
};

struct brcmf_cfg80211_info {
    struct {
        struct {
            struct {
                uint8_t ssid[32];
                uint32_t ssid_len;
            } ssid;
            uint32_t n_channels;
            uint32_t channels[1];
        } *nd;
        struct {
            uint32_t n_matches;
            void *matches[1];
        } *nd_info;
        bool nd_data_completed;
        int nd_data_wait;
    } wowl;
};

struct wiphy;

struct brcmf_pno_scanresults_le {
    uint32_t count;
};

struct brcmf_pno_net_info_le {
    uint8_t SSID[32];
    uint32_t SSID_len;
    uint32_t channel;
};

#define SCAN 1
#define BRCMF_E_PFN_NET_LOST 0
#define CH_MAX_2G_CHANNEL 14
#define EINVAL 22
#define IEEE80211_MAX_SSID_LEN 32
#define NL80211_BAND_2GHZ 0
#define NL80211_BAND_5GHZ 1

static inline uint32_t le32_to_cpu(uint32_t val) { return val; }
static inline void wake_up(int *wq) {}

struct wiphy *cfg_to_wiphy(struct brcmf_cfg80211_info *cfg) { return (struct wiphy *)0; }
void brcmf_dbg(int level, const char *fmt, ...) {}
void bphy_err(struct wiphy *wiphy, const char *fmt, ...) {}
struct brcmf_pno_net_info_le *brcmf_get_netinfo_array(struct brcmf_pno_scanresults_le *result) { return (struct brcmf_pno_net_info_le *)0; }
int ieee80211_channel_to_frequency(int chan, int band) { return 0; }