#include <stdint.h>
#include <stddef.h>

typedef uint16_t u16;
typedef uint8_t u8;

enum ieee80211_back_parties {
    IEEE80211_BACK_INITIATOR,
    IEEE80211_BACK_RECIPIENT
};

struct sta_info {
    struct ieee80211_local *local;
    struct {
        u8 tid_state_tx[16];
        u8 addba_req_num[16];
    } ampdu_mlme;
    struct {
    } sta;
};

struct ieee80211_local;

#define HT_AGG_STATE_OPERATIONAL 0
#define HT_AGG_STATE_REQ_STOP_BA_MSK 1
#define HT_AGG_STATE_INITIATOR_SHIFT 1

#define IEEE80211_AMPDU_TX_STOP 0

#define WARN_ON(condition) (condition)

int drv_ampdu_action(struct ieee80211_local *local, int action, void *sta, u16 tid, void *args);