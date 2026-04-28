#include <stdint.h>
#include <stddef.h>

#define MAX_TID_COUNT 8
#define IWL_INVALID_STATION -1
#define EINVAL 22
#define ENXIO 6
#define IEEE80211_SCTL_SEQ 0xFFF0
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef uint8_t u8;
typedef uint16_t u16;

enum iwl_agg_state {
    IWL_AGG_OFF,
    IWL_AGG_ON,
    IWL_EMPTYING_HW_QUEUE_ADDBA,
    IWL_EMPTYING_HW_QUEUE_DELBA
};

struct iwl_tid_data {
    u16 seq_number;
    struct {
        u16 txq_id;
        enum iwl_agg_state state;
    } agg;
};

struct iwl_queue {
    int write_ptr;
    int read_ptr;
};

struct iwl_txq {
    struct iwl_queue q;
};

struct iwl_station_entry {
    struct iwl_tid_data tid[MAX_TID_COUNT];
};

struct iwl_lib_ops {
    int (*txq_agg_disable)(struct iwl_priv *priv, int txq_id, int ssn, int tx_fifo_id);
};

struct iwl_ops {
    struct iwl_lib_ops *lib;
};

struct iwl_cfg {
    struct iwl_ops *ops;
};

struct iwl_priv {
    struct iwl_station_entry *stations;
    struct iwl_txq *txq;
    struct iwl_cfg *cfg;
    int lock;
    void *hw;
};

extern int iwl_find_station(struct iwl_priv *priv, const u8 *ra);
extern void IWL_ERR(struct iwl_priv *priv, const char *fmt, ...);
extern void IWL_WARN(struct iwl_priv *priv, const char *fmt, ...);
extern void IWL_DEBUG_HT(struct iwl_priv *priv, const char *fmt, ...);
extern void ieee80211_stop_tx_ba_cb_irqsafe(void *hw, const u8 *ra, u16 tid);

static const int default_tid_to_tx_fifo[MAX_TID_COUNT];

#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define unlikely(x) (x)
#define likely(x) (x)