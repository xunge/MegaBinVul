#include <stdint.h>

struct sk_buff {
    unsigned char *data;
    unsigned int len;
};

struct x25_address {
    char x25_addr[16];
};

struct x25_facilities {
    uint8_t facilities[128];
};

struct x25_dte_facilities {
    uint8_t dte_facilities[128];
};

struct x25_sock {
    uint8_t condition;
    uint16_t vs;
    uint16_t va;
    uint16_t vr;
    uint16_t vl;
    uint8_t state;
    struct x25_facilities facilities;
    struct x25_dte_facilities dte_facilities;
    uint16_t vc_facil_mask;
    struct {
        uint8_t cuddata[128];
        uint16_t cudlength;
    } calluserdata;
};

struct sock {
    int sk_state;
    unsigned int sk_flags;
    void (*sk_state_change)(struct sock *sk);
};

#define X25_STATE_3 3
#define X25_CALL_ACCEPTED 0x01
#define X25_CLEAR_REQUEST 0x02
#define X25_CLEAR_CONFIRMATION 0x03
#define X25_STD_MIN_LEN 3
#define ECONNREFUSED 111
#define TCP_ESTABLISHED 1
#define SOCK_DEAD (1 << 2)

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
    skb->len -= len;
}

static inline void skb_copy_from_linear_data(const struct sk_buff *skb, void *to, const unsigned int len) {
    memcpy(to, skb->data, len);
}

static inline int sock_flag(const struct sock *sk, unsigned int flag) {
    return sk->sk_flags & flag;
}