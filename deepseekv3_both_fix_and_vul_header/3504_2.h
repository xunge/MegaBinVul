#include <stdbool.h>
#include <stddef.h>

struct ieee80211_sta;
struct ath_softc;
struct ath_txq;

struct list_head {
    struct list_head *next, *prev;
};

#define IEEE80211_NUM_TIDS 8

struct ath_atx_tid {
    bool sched;
    struct ath_atx_ac *ac;
    struct list_head list;
};

struct ath_atx_ac {
    bool sched;
    struct ath_txq *txq;
    struct list_head list;
};

struct ath_node {
    struct ath_atx_tid tid[IEEE80211_NUM_TIDS];
};

void ath_txq_lock(struct ath_softc *sc, struct ath_txq *txq);
void ath_txq_unlock(struct ath_softc *sc, struct ath_txq *txq);
bool ath_tid_has_buffered(struct ath_atx_tid *tid);
void ieee80211_sta_set_buffered(struct ieee80211_sta *sta, int tidno, bool buffered);
void list_del(struct list_head *entry);