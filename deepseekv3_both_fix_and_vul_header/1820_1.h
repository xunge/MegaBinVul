#include <stdint.h>
#include <string.h>

#define HCI_PRIMARY 0
#define ACL_START 0
#define ACL_START_NO_FLUSH 1
#define ACL_COMPLETE 2
#define ACL_CONT 3
#define L2CAP_LEN_SIZE 2
#define L2CAP_HDR_SIZE 4
#define ECOMM 70

typedef uint16_t u16;

struct sk_buff {
    unsigned int len;
    void *data;
};

struct hci_conn {
    struct hci_dev *hdev;
    struct l2cap_conn *l2cap_data;
};

struct hci_dev {
    int dev_type;
};

struct l2cap_conn {
    struct sk_buff *rx_skb;
    unsigned int rx_len;
    unsigned int mtu;
};

#define BT_DBG(fmt, ...)
#define BT_ERR(fmt, ...)

static inline uint16_t get_unaligned_le16(const void *p)
{
    const uint8_t *ptr = p;
    return ptr[0] | (ptr[1] << 8);
}

void l2cap_recv_reset(struct l2cap_conn *conn);
void l2cap_conn_unreliable(struct l2cap_conn *conn, int err);
int l2cap_recv_frag(struct l2cap_conn *conn, struct sk_buff *skb, int len);
void l2cap_recv_frame(struct l2cap_conn *conn, struct sk_buff *skb);
int l2cap_recv_len(struct l2cap_conn *conn, struct sk_buff *skb);
struct l2cap_conn *l2cap_conn_add(struct hci_conn *hcon);
void kfree_skb(struct sk_buff *skb);