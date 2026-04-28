#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint64_t u64;

#define BRCMF_C_SCAN 123  // Dummy value for compilation

struct brcmf_pub {
    // dummy definition
};

struct brcmf_cfg80211_info {
    struct brcmf_pub *pub;
    struct cfg80211_scan_request *scan_request;
    unsigned long escan_timeout;
    unsigned int int_escan_map;
    void *pno;
    unsigned long scan_status;
};

struct brcmf_if {
    // dummy definition
};

struct brcmf_scan_params_v2_le {
    // dummy definition
    char dummy[128];
};

struct brcmf_scan_params_le {
    // dummy definition
    char dummy[64];
};

struct cfg80211_scan_request {
    // dummy definition
};

struct cfg80211_scan_info {
    bool aborted;
};

#define BRCMF_FEAT_SCAN_V2 1
#define BRCMF_SCAN_STATUS_BUSY 0
#define BIT(n) (1UL << (n))
#define __ffs(word) (__builtin_ffs(word) - 1)

#define SCAN 0

static inline int timer_pending(void *timer) { return 0; }
static inline void del_timer_sync(void *timer) {}
static inline bool brcmf_feat_is_enabled(struct brcmf_if *ifp, int feat) { return false; }
static inline void brcmf_escan_prep(void *cfg, void *params, void *ssid) {}
static inline s32 brcmf_fil_cmd_data_set(struct brcmf_if *ifp, int cmd, void *buf, int len) { return 0; }
static inline void brcmf_scan_params_v2_to_v1(void *v2, void *v1) {}
static inline void brcmf_scan_config_mpc(struct brcmf_if *ifp, int enable) {}
static inline u64 brcmf_pno_find_reqid_by_bucket(void *pno, u32 bucket) { return 0; }
static inline void *cfg_to_wiphy(void *cfg) { return NULL; }
static inline int test_and_clear_bit(int nr, unsigned long *addr) { return 0; }
static inline void cfg80211_sched_scan_results(void *wiphy, u64 reqid) {}
static inline void cfg80211_scan_done(struct cfg80211_scan_request *request, struct cfg80211_scan_info *info) {}

#define brcmf_dbg(level, fmt, ...) 
#define bphy_err(drvr, fmt, ...) 