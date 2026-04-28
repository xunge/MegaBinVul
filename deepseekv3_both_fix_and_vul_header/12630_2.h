#include <stdint.h>

struct hci_dev {
    const char *name;
};

struct hci_chan {
    uint8_t amp;
};

struct hci_ev_disconn_logical_link_complete {
    uint16_t handle;
    uint8_t status;
    uint8_t reason;
};

struct sk_buff {
    void *data;
};

#define BT_DBG(fmt, ...)
#define le16_to_cpu(x) (x)

void hci_dev_lock(struct hci_dev *hdev);
void hci_dev_unlock(struct hci_dev *hdev);
struct hci_chan *hci_chan_lookup_handle(struct hci_dev *hdev, uint16_t handle);
void amp_destroy_logical_link(struct hci_chan *hchan, uint8_t reason);