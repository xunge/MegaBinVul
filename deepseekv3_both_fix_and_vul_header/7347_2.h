#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct qrtr_endpoint {
    struct qrtr_node *node;
};

struct qrtr_node {
    // node fields would be defined here
};

struct qrtr_hdr_v1 {
    u32 type;
    u32 src_node_id;
    u32 src_port_id;
    u32 confirm_rx;
    u32 dst_node_id;
    u32 dst_port_id;
    u32 size;
};

struct qrtr_hdr_v2 {
    u8 type;
    u8 flags;
    u16 optlen;
    u16 src_node_id;
    u16 src_port_id;
    u16 dst_node_id;
    u16 dst_port_id;
    u32 size;
};

struct qrtr_sock {
    int sk;
};

struct sk_buff {
    char cb[64]; // control buffer
};

struct qrtr_cb {
    u32 type;
    u32 src_node;
    u32 src_port;
    u32 confirm_rx;
    u32 dst_node;
    u32 dst_port;
};

struct qrtr_ctrl_pkt {
    struct {
        u32 node;
    } server;
};

#define QRTR_PROTO_VER_1 1
#define QRTR_PROTO_VER_2 2
#define QRTR_PORT_CTRL 0xffff
#define QRTR_TYPE_DATA 1
#define QRTR_TYPE_RESUME_TX 2
#define QRTR_TYPE_NEW_SERVER 3
#define QRTR_FLAGS_CONFIRM_RX 1

#define GFP_ATOMIC 0
#define __GFP_NOWARN 0

#define EINVAL 22
#define ENOMEM 12

#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)

#define ALIGN(x, a) (((x) + ((a)-1)) & ~((a)-1))

static inline void *__netdev_alloc_skb(void *a, size_t b, int c) { return malloc(b); }
static inline void kfree_skb(void *skb) { free(skb); }
static inline void skb_put_data(void *skb, const void *data, size_t len) { memcpy(skb, data, len); }
static inline void qrtr_node_assign(struct qrtr_node *node, u32 id) {}
static inline void qrtr_tx_resume(struct qrtr_node *node, struct sk_buff *skb) {}
static inline struct qrtr_sock *qrtr_port_lookup(u32 port) { return NULL; }
static inline void qrtr_port_put(struct qrtr_sock *ipc) {}
static inline int sock_queue_rcv_skb(int *sk, struct sk_buff *skb) { return 0; }
static inline void pr_err(const char *fmt, ...) {}