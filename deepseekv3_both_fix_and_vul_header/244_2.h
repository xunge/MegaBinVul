#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint16_t __be16;

struct sk_buff {
    // 基本结构定义
};

struct sk_buff_head {
    // 队列结构定义  
};

struct nfc_llcp_local {
    __be16 miux;
    u8 rw;
    struct sk_buff_head tx_queue;
};

struct nfc_llcp_sock {
    struct nfc_llcp_local *local;
    u8 *service_name;
    size_t service_name_len;
    __be16 miux;
    u8 rw;
};

#define LLCP_TLV_SN 1
#define LLCP_TLV_MIUX 2
#define LLCP_TLV_RW 3
#define LLCP_PDU_CONNECT 4
#define LLCP_MAX_MIUX 0x7ff
#define LLCP_MAX_RW 15
#define ENODEV 19
#define ENOMEM 12

#define pr_debug(fmt, ...) 
#define pr_err(fmt, ...) 

static inline u16 be16_to_cpu(__be16 val) { return val; }

u8 *nfc_llcp_build_tlv(u8 type, u8 *value, u8 length, u8 *tlv_length);
struct sk_buff *llcp_allocate_pdu(struct nfc_llcp_sock *sock, u8 type, u16 length);
void llcp_add_tlv(struct sk_buff *skb, u8 *tlv, u8 tlv_length);
void skb_queue_tail(struct sk_buff_head *queue, struct sk_buff *skb);
void kfree(void *ptr);