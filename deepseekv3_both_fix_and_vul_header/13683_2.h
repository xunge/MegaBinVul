#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

enum htc_endpoint_id {
    ENDPOINT0
};

struct completion {
    bool done;
};

struct htc_target {
    void *endpoint;
    void *dev;
    enum htc_endpoint_id conn_rsp_epid;
    struct completion cmd_wait;
};

struct htc_service_connreq {
    uint16_t service_id;
    unsigned int max_send_qdepth;
    uint16_t con_flags;
    void *ep_callbacks;
};

struct htc_endpoint {
    uint16_t service_id;
    unsigned int max_txqdepth;
    uint8_t ul_pipeid;
    uint8_t dl_pipeid;
    void *ep_callbacks;
};

struct htc_conn_svc_msg {
    uint16_t service_id;
    uint16_t msg_id;
    uint16_t con_flags;
    uint8_t dl_pipeid;
    uint8_t ul_pipeid;
};

struct htc_frame_hdr {
    uint8_t data[0];
};

struct sk_buff {
    unsigned int len;
    void *data;
};

#define HTC_MSG_CONNECT_SERVICE_ID 0
#define HZ 1
#define GFP_ATOMIC 0
#define cpu_to_be16(x) (x)
#define EINVAL 22
#define ENOMEM 12
#define ETIMEDOUT 110

struct sk_buff *alloc_skb(unsigned int size, int flags);
void kfree_skb(struct sk_buff *skb);
void skb_reserve(struct sk_buff *skb, unsigned int len);
void *skb_put(struct sk_buff *skb, unsigned int len);
int htc_issue_send(struct htc_target *target, struct sk_buff *skb, int len, int flags, enum htc_endpoint_id ep);
unsigned long wait_for_completion_timeout(struct completion *comp, unsigned long timeout);
void dev_err(void *dev, const char *fmt, ...);
struct htc_endpoint *get_next_avail_ep(void *endpoint);
uint8_t service_to_ulpipe(uint16_t service_id);
uint8_t service_to_dlpipe(uint16_t service_id);