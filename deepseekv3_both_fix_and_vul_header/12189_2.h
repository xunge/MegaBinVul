#include <stdlib.h>

struct brcmf_cfg80211_info {
    struct wiphy *wiphy;
    void *escan_timeout_work;
};

struct wiphy;

void brcmf_pno_detach(struct brcmf_cfg80211_info *cfg);
void brcmf_btcoex_detach(struct brcmf_cfg80211_info *cfg);
void wl_deinit_priv(struct brcmf_cfg80211_info *cfg);
void brcmf_free_wiphy(struct wiphy *wiphy);
void cancel_work_sync(void *work);
void wiphy_unregister(struct wiphy *wiphy);