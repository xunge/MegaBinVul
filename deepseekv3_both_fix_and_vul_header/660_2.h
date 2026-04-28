#include <stdint.h>
#include <stdbool.h>

#define WMM_NUM_AC 4
#define EINVAL 22

typedef uint8_t u8;

struct wmi {
    uint32_t lock;
    u8 stream_exist_for_ac[WMM_NUM_AC];
    uint32_t fat_pipe_exist;
    void *parent_dev;
};

struct wmi_pstream_timeout_event {
    u8 traffic_class;
};

void ath6kl_err(const char *fmt, ...);
void ath6kl_indicate_tx_activity(void *dev, u8 ac, bool active);
void spin_lock_bh(uint32_t *lock);
void spin_unlock_bh(uint32_t *lock);