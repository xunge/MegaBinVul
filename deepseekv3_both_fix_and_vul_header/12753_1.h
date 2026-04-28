#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t __u8;
typedef uint8_t u8;
typedef uint32_t u32;

struct hci_dev {
    const char *name;
};

struct sk_buff {
    __u8 *data;
    unsigned int len;
};

struct inquiry_data {
    uint8_t bdaddr[6];
    uint8_t pscan_rep_mode;
    uint8_t pscan_period_mode;
    uint8_t pscan_mode;
    uint8_t dev_class[3];
    uint16_t clock_offset;
    int8_t rssi;
    uint8_t ssp_mode;
};

struct extended_inquiry_info {
    uint8_t bdaddr[6];
    uint8_t pscan_rep_mode;
    uint8_t pscan_period_mode;
    uint8_t dev_class[3];
    uint16_t clock_offset;
    int8_t rssi;
    uint8_t data[240];
};

#define BT_DBG(fmt, ...)
#define HCI_PERIODIC_INQ 0
#define HCI_MGMT 0
#define EIR_NAME_COMPLETE 0
#define ACL_LINK 0

static inline void bacpy(void *dest, const void *src) {
    memcpy(dest, src, 6);
}

static inline bool hci_dev_test_flag(struct hci_dev *hdev, int flag) {
    return false;
}

static inline void hci_dev_lock(struct hci_dev *hdev) {}
static inline void hci_dev_unlock(struct hci_dev *hdev) {}

static inline u32 hci_inquiry_cache_update(struct hci_dev *hdev, struct inquiry_data *data, bool name_known) {
    return 0;
}

static inline bool eir_get_data(const void *data, size_t len, int type, void *buf) {
    return false;
}

static inline size_t eir_get_length(const void *data, size_t len) {
    return 0;
}

static inline void mgmt_device_found(struct hci_dev *hdev, void *bdaddr, int link_type, u8 addr_type, 
                                   void *dev_class, int rssi, u32 flags, void *eir, size_t eir_len, 
                                   void *dev_name, u8 name_len) {}