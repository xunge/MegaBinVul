#include <stdlib.h>

#define NUM_NL80211_BANDS 4
#define CONFIG_RSI_DEBUGFS 1

enum nl80211_band {
    NL80211_BAND_2GHZ,
    NL80211_BAND_5GHZ,
    NL80211_BAND_60GHZ,
    NL80211_BAND_6GHZ
};

struct ieee80211_hw;
struct ieee80211_supported_band {
    void *channels;
};

struct rsi_hw {
    struct ieee80211_hw *hw;
    struct ieee80211_supported_band sbands[NUM_NL80211_BANDS];
#ifdef CONFIG_RSI_DEBUGFS
    void *dfsentry;
#endif
};

void ieee80211_stop_queues(struct ieee80211_hw *hw);
void ieee80211_unregister_hw(struct ieee80211_hw *hw);
void ieee80211_free_hw(struct ieee80211_hw *hw);
void rsi_remove_dbgfs(struct rsi_hw *adapter);
void kfree(void *ptr);