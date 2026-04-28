#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdatomic.h>

#define INTF_HEADER_LEN 4
#define MWIFIEX_USB_EP_CMD_EVENT 1
#define MWIFIEX_USB_EP_DATA 2
#define MWIFIEX_USB_TYPE_CMD 1
#define MWIFIEX_USB_TYPE_EVENT 2
#define MWIFIEX_SIZE_OF_CMD_BUFFER 2048
#define MWIFIEX_RX_DATA_BUF_SIZE 8192
#define MAX_EVENT_SIZE 256
#define MWIFIEX_EVENT_HEADER_LEN 4
#define PS_STATE_SLEEP_CFM 1
#define ERROR 1
#define EVENT 2
#define WARN 3
#define DATA 4
#define EINPROGRESS 115

typedef uint32_t __le32;
typedef uint8_t u8;
typedef uint32_t u32;

struct sk_buff {
    unsigned int len;
    void *data;
    struct sk_buff *resp_skb;
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct mwifiex_adapter {
    bool hs_activated;
    bool cmd_resp_received;
    bool event_received;
    bool data_received;
    struct sk_buff *curr_cmd;
    struct sk_buff *event_skb;
    struct sk_buff_head rx_data_q;
    atomic_int rx_pending;
    int ps_state;
    uint32_t event_cause;
    uint8_t event_body[MAX_EVENT_SIZE];
};

static inline uint32_t le32_to_cpu(__le32 val) {
    return val;
}

static inline void skb_copy_from_linear_data(const struct sk_buff *skb, void *to, unsigned int len) {
    memcpy(to, skb->data, len);
}

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data = (char *)skb->data + len;
    skb->len -= len;
}

static inline void skb_push(struct sk_buff *skb, unsigned int len) {
    skb->data = (char *)skb->data - len;
    skb->len += len;
}

static inline void skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newsk) {
    newsk->next = (struct sk_buff *)list;
    newsk->prev = list->prev;
    list->prev->next = newsk;
    list->prev = newsk;
}

void mwifiex_dbg(struct mwifiex_adapter *adapter, int level, const char *fmt, ...);
void mwifiex_process_hs_config(struct mwifiex_adapter *adapter);
void mwifiex_process_sleep_confirm_resp(struct mwifiex_adapter *adapter, void *data, int len);