#include <stddef.h>
#include <time.h>

typedef int ieee80211_tx_result;

struct sk_buff;
struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    unsigned int qlen;
};

struct timer_list {
    unsigned long expires;
    void (*function)(unsigned long);
    unsigned long data;
};

struct ieee80211_tx_data {
    struct sta_info *sta;
    struct sk_buff *skb;
    struct ieee80211_local *local;
    struct ieee80211_sub_if_data *sdata;
};

struct sta_info {
    struct sta_info *ps_lock;
    struct sk_buff_head ps_tx_buf[4];
    struct ieee80211_sub_if_data *sdata;
    struct {
        unsigned char addr[6];
        int aid;
    } sta;
};

struct ieee80211_tx_info {
    unsigned int flags;
    struct {
        unsigned long jiffies;
        void *vif;
    } control;
};

struct ieee80211_local {
    unsigned int total_ps_buffered;
    struct timer_list sta_cleanup;
    struct {
        void *hw;
    } hw;
};

struct ieee80211_sub_if_data {
    void *vif;
};

#define WLAN_STA_PS_STA 0
#define WLAN_STA_PS_DRIVER 0
#define IEEE80211_TX_CTL_NO_PS_BUFFER 0
#define IEEE80211_TX_INTFL_NEED_TXPROCESSING 0
#define IEEE80211_TX_TEMPORARY_FLAGS 0
#define STA_MAX_TX_BUFFER 100
#define TOTAL_MAX_TX_BUFFER 1000
#define STA_INFO_CLEANUP_INTERVAL (10)

#define TX_CONTINUE 0
#define TX_QUEUED 1

#define ps_dbg(...)
#define test_sta_flag(...) 0
#define purge_old_ps_buffers(...)
#define sta_info_recalc_tim(...)
#define IEEE80211_SKB_CB(...) ((struct ieee80211_tx_info *)NULL)
#define skb_get_queue_mapping(...) 0
#define skb_queue_len(...) 0
#define skb_dequeue(...) NULL
#define skb_queue_tail(...)
#define timer_pending(...) 0
#define mod_timer(...)
#define round_jiffies(...) 0
#define ieee80211_free_txskb(...)

#define unlikely(x) (x)
#define spin_lock(x)
#define spin_unlock(x)
static unsigned long jiffies = 0;