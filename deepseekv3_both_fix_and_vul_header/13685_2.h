#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

enum wmi_cmd_id {
    WMI_CMD_1,
    WMI_CMD_2
};

struct ath_hw {
    unsigned int ah_flags;
};

struct ath_common {
    int dummy;
};

struct htc_frame_hdr {
    u16 dummy;
};

struct wmi_cmd_hdr {
    u16 dummy;
};

struct sk_buff {
    void *data;
    unsigned int len;
    unsigned int headroom;
};

struct completion {
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    bool done;
};

struct wmi_drv_priv {
    struct ath_hw *ah;
};

struct wmi {
    struct wmi_drv_priv *drv_priv;
    bool stopped;
    u8 *cmd_rsp_buf;
    u32 cmd_rsp_len;
    pthread_mutex_t op_mutex;
    struct completion cmd_wait;
};

#define GFP_ATOMIC 0
#define ENOMEM (-1)
#define EPROTO (-2)
#define ETIMEDOUT (-3)
#define AH_UNPLUGGED (1 << 0)
#define WMI 0
#define unlikely(x) (x)

struct ath_common *ath9k_hw_common(struct ath_hw *ah);
int ath9k_wmi_cmd_issue(struct wmi *wmi, struct sk_buff *skb, enum wmi_cmd_id cmd_id, u32 cmd_len);
void ath_dbg(struct ath_common *common, int type, const char *fmt, ...);
const char *wmi_cmd_to_name(enum wmi_cmd_id cmd_id);

struct sk_buff *alloc_skb(unsigned int size, int flags);
void skb_reserve(struct sk_buff *skb, unsigned int len);
void skb_put_data(struct sk_buff *skb, const void *data, unsigned int len);
void kfree_skb(struct sk_buff *skb);

unsigned long wait_for_completion_timeout(struct completion *comp, unsigned long timeout);
void mutex_lock(pthread_mutex_t *mutex);
void mutex_unlock(pthread_mutex_t *mutex);