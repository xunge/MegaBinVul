#include <stdint.h>
#include <stddef.h>

struct nfc_dev {
    unsigned int tx_headroom;
    unsigned int tx_tailroom;
};

struct nfc_llcp_local {
    int target_idx;
};

struct sk_buff;

#define ENODEV 19
#define ENOMEM 12 
#define GFP_KERNEL 0
#define LLCP_HEADER_SIZE 2
#define LLCP_PDU_SYMM 0
#define NFC_HEADER_SIZE 1
#define NFC_DIRECTION_TX 0

typedef uint16_t u16;

struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev);
struct sk_buff *alloc_skb(unsigned int size, int priority);
void skb_reserve(struct sk_buff *skb, int len);
struct sk_buff *llcp_add_header(struct sk_buff *skb, int a, int b, int c);
void __net_timestamp(struct sk_buff *skb);
void nfc_llcp_send_to_raw_sock(struct nfc_llcp_local *local, struct sk_buff *skb, int direction);
int nfc_data_exchange(struct nfc_dev *dev, int target_idx, struct sk_buff *skb, void (*recv)(void), struct nfc_llcp_local *local);
void nfc_llcp_recv(void);