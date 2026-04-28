#include <stdint.h>
#include <stdbool.h>

struct sk_buff {
    void *data;
};

struct hci_dev {
    char *name;
    uint16_t block_mtu;
};

struct hci_conn {
    struct amp_mgr *amp_mgr;
};

struct hci_chan {
    uint16_t handle;
    bool amp;
};

struct amp_mgr {
    struct l2cap_chan *bredr_chan;
};

struct l2cap_chan {
    struct {
        uint16_t mtu;
    } *conn;
};

struct hci_ev_logical_link_complete {
    uint16_t handle;
    uint8_t phy_handle;
    uint8_t status;
};

#define BT_DBG(fmt, ...)
#define le16_to_cpu(x) (x)

void l2cap_chan_lock(struct l2cap_chan *chan);
void l2cap_chan_unlock(struct l2cap_chan *chan);
void l2cap_logical_cfm(struct l2cap_chan *bredr_chan, struct hci_chan *hchan, int status);
void hci_conn_hold(struct hci_conn *hcon);
struct hci_conn *hci_conn_hash_lookup_handle(struct hci_dev *hdev, uint8_t phy_handle);
struct hci_chan *hci_chan_create(struct hci_conn *hcon);