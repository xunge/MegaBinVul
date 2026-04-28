#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint16_t __be16;

struct nfc_llcp_sock {
    struct nfc_llcp_local *local;
    __be16 miux;
    u8 rw;
};

struct nfc_llcp_local {
    __be16 miux;
    u8 rw;
    struct {
        void *next;
    } tx_queue;
};

struct sk_buff {
    void *data;
};

#define LLCP_MAX_MIUX 0x7ff
#define LLCP_MAX_RW 0xf
#define LLCP_TLV_MIUX 0x01
#define LLCP_TLV_RW 0x02
#define LLCP_PDU_CC 0x01
#define ENODEV 19
#define ENOMEM 12

extern struct sk_buff *llcp_allocate_pdu(struct nfc_llcp_sock *sock, u8 type, u16 size);
extern void llcp_add_tlv(struct sk_buff *skb, u8 *tlv, u8 tlv_length);
extern u8 *nfc_llcp_build_tlv(u8 type, u8 *value, u8 value_length, u8 *tlv_length);
extern void pr_debug(const char *fmt, ...);
extern void pr_err(const char *fmt, ...);

static inline u16 be16_to_cpu(__be16 x) {
    return ((x & 0xff) << 8) | ((x >> 8) & 0xff);
}

#define kfree free
#define skb_queue_tail(queue, skb) /* stub implementation */