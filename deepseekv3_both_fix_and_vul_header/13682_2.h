#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

struct htc_frame_hdr {
    uint8_t data[0];
};

struct sk_buff {
    unsigned int len;
    void *data;
};

struct htc_target {
    void *dev;
    uint8_t credits;
    unsigned int htc_flags;
    struct {
        int cmd_wait;
    };
};

struct htc_config_pipe_msg {
    uint16_t message_id;
    uint8_t pipe_id;
    uint8_t credits;
};

#define HTC_MSG_CONFIG_PIPE_ID 0
#define USB_WLAN_TX_PIPE 0
#define HTC_OP_CONFIG_PIPE_CREDITS 0
#define ENDPOINT0 0
#define HZ 1
#define GFP_ATOMIC 0
#define ENOMEM (-1)
#define ETIMEDOUT (-2)
#define EINVAL (-3)

static inline uint16_t cpu_to_be16(uint16_t x) {
    return htons(x);
}

void *alloc_skb(size_t size, int flags);
void skb_reserve(struct sk_buff *skb, size_t len);
void *skb_put(struct sk_buff *skb, size_t len);
void kfree_skb(struct sk_buff *skb);
int htc_issue_send(struct htc_target *target, struct sk_buff *skb, int len, int flags, int endpoint);
unsigned long wait_for_completion_timeout(void *completion, unsigned long timeout);
void dev_err(void *dev, const char *fmt, ...);