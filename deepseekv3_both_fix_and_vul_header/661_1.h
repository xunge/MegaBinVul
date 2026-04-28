#include <stdint.h>
#include <stdbool.h>

#define WMM_NUM_AC 4
#define IEEE80211_TSPEC_STATUS_ADMISS_ACCEPTED 0
#define IEEE80211_WMM_IE_TSPEC_TID_SHIFT 0
#define IEEE80211_WMM_IE_TSPEC_TID_MASK 0x0F
#define CAC_INDICATION_ADMISSION_RESP 0
#define CAC_INDICATION_NO_RESP 1
#define CAC_INDICATION_DELETE 2
#define EINVAL 22

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint16_t __le16;

struct wmi {
    int lock;
    u16 stream_exist_for_ac[WMM_NUM_AC];
    void *parent_dev;
    u8 fat_pipe_exist;
};

struct wmi_cac_event {
    u8 ac;
    u8 cac_indication;
    u8 status_code;
    u8 tspec_suggestion[0];
};

struct ieee80211_tspec_ie {
    __le16 tsinfo;
};

struct ath6kl_vif {
    u8 fw_vif_idx;
};

static inline u16 le16_to_cpu(__le16 val) {
    return val;
}

void ath6kl_err(const char *fmt, ...);
void ath6kl_wmi_delete_pstream_cmd(struct wmi *wmi, u8 vif_idx, u8 ac, u8 tsid);
void ath6kl_indicate_tx_activity(void *dev, u8 ac, bool active);

#define spin_lock_bh(lock) do { } while (0)
#define spin_unlock_bh(lock) do { } while (0)