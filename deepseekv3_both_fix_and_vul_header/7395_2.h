#include <stdint.h>

#define HCI_EVENT_PKT 0x04
#define HCI_ACLDATA_PKT 0x02
#define HCI_SCODATA_PKT 0x03
#define HCI_ISODATA_PKT 0x05

typedef uint8_t __u8;

struct sk_buff {
    void *data;
    __u8 pkt_type;
};

struct hci_dev;

struct virtio_bluetooth {
    struct hci_dev *hdev;
};

void skb_pull(struct sk_buff *skb, int len);
void hci_recv_frame(struct hci_dev *hdev, struct sk_buff *skb);

#define hci_skb_pkt_type(skb) ((skb)->pkt_type)