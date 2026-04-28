#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define WMM_NUM_AC 4
#define ATH6KL_DBG_WMI 0
#define WMI_DELETE_PSTREAM_CMDID 0
#define SYNC_BEFORE_WMIFLAG 0
#define EINVAL 22
#define ENOMEM 12
#define ENODATA 61

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct sk_buff {
    void *data;
};

struct wmi {
    int lock;
    u16 stream_exist_for_ac[WMM_NUM_AC];
    u8 fat_pipe_exist;
    void *parent_dev;
};

struct wmi_delete_pstream_cmd {
    u8 traffic_class;
    u8 tsid;
};

int ath6kl_err(const char *fmt, ...);
int ath6kl_dbg(int level, const char *fmt, ...);
int ath6kl_wmi_cmd_send(struct wmi *wmi, u8 if_idx, struct sk_buff *skb, u32 cmd_id, u32 flags);
void ath6kl_indicate_tx_activity(void *dev, u8 traffic_class, bool active);
struct sk_buff *ath6kl_wmi_get_new_buf(size_t size);
void dev_kfree_skb(struct sk_buff *skb);

static inline void spin_lock_bh(int *lock) { (void)lock; }
static inline void spin_unlock_bh(int *lock) { (void)lock; }