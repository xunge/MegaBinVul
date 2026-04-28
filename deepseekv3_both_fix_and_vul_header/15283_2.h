#include <stdint.h>

typedef uint16_t u16;
typedef uint8_t u8;

enum ieee80211_back_parties {
    IEEE80211_BACK_INITIATOR,
    IEEE80211_BACK_RECIPIENT
};

struct ampdu_mlme {
    u8 tid_state_tx[16];
};

struct sta_info {
    struct {
        u8 addr[6];
    } sta;
    struct ampdu_mlme ampdu_mlme;
    int lock;
};

#define HT_AGG_STATE_OPERATIONAL 3
#define ENOENT 2
#define KERN_DEBUG ""

static inline void spin_lock_bh(int *lock) { (void)lock; }
static inline void spin_unlock_bh(int *lock) { (void)lock; }
static inline void printk(const char *fmt, ...) { (void)fmt; }

int ___ieee80211_stop_tx_ba_session(struct sta_info *sta, u16 tid,
                                   enum ieee80211_back_parties initiator);