#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct completion {
    pthread_mutex_t lock;
    pthread_cond_t cond;
    int done;
};

struct htc_target {
    void *dev;
    unsigned int htc_flags;
    struct completion cmd_wait;
};

struct htc_frame_hdr {
    uint8_t data[0];
};

struct htc_comp_msg {
    uint16_t msg_id;
};

struct sk_buff {
    unsigned int len;
    void *data;
};

#define HTC_MSG_SETUP_COMPLETE_ID 0
#define HTC_OP_START_WAIT 0
#define ENDPOINT0 0
#define GFP_ATOMIC 0
#define HZ 1

enum {
    ENOMEM = -1,
    ETIMEDOUT = -2,
    EINVAL = -3
};

static inline uint16_t cpu_to_be16(uint16_t x) {
    return ((x & 0xFF) << 8) | ((x >> 8) & 0xFF);
}

struct sk_buff *alloc_skb(unsigned int size, int flags);
void skb_reserve(struct sk_buff *skb, unsigned int len);
void *skb_put(struct sk_buff *skb, unsigned int len);
void kfree_skb(struct sk_buff *skb);
int htc_issue_send(struct htc_target *target, struct sk_buff *skb, unsigned int len, int flags, int endpoint);
unsigned long wait_for_completion_timeout(struct completion *comp, unsigned long timeout);
void dev_err(void *dev, const char *fmt, ...);