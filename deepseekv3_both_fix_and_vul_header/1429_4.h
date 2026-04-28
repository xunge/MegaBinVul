#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;

struct timer_list {
    // 最小化定义
};

struct device {
    // 最小化定义
};

struct sk_buff {
    unsigned int len;
    // 其他必要字段
};

struct nfc_target {
    u32 idx;
    // 其他必要字段
};

struct nfc_ops;

struct nfc_dev {
    struct device dev;
    u32 rf_mode;
    struct nfc_target *active_target;
    struct nfc_ops *ops;
    int shutting_down;
    struct timer_list check_pres_timer;
    // 其他必要字段
};

struct nfc_ops {
    int (*check_presence)(void);
    int (*im_transceive)(struct nfc_dev *dev, struct nfc_target *target,
                        struct sk_buff *skb, void *cb, void *cb_context);
    int (*tm_send)(struct nfc_dev *dev, struct sk_buff *skb);
    // 其他必要操作
};

typedef void (*data_exchange_cb_t)(void *cb_context, struct sk_buff *skb, int err);

#define ENODEV 19
#define EADDRNOTAVAIL 99
#define ENOTCONN 107
#define NFC_RF_INITIATOR 0
#define NFC_RF_TARGET 1
#define NFC_CHECK_PRES_FREQ_MS 1000

// 函数声明
void kfree_skb(struct sk_buff *skb);
void device_lock(struct device *dev);
void device_unlock(struct device *dev);
int device_is_registered(struct device *dev);
void del_timer_sync(struct timer_list *timer);
void mod_timer(struct timer_list *timer, unsigned long expires);
unsigned long jiffies;
unsigned long msecs_to_jiffies(unsigned int msecs);
const char *dev_name(struct device *dev);
int pr_debug(const char *fmt, ...);