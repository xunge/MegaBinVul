#include <stdint.h>
#include <linux/types.h>

typedef uint32_t u32;
typedef uint8_t u8;

#define HCI_UP 1
#define ENETDOWN 1

struct hci_dev {
    unsigned long flags;
};

struct hci_request;

void hci_req_sync_lock(struct hci_dev *hdev);
void hci_req_sync_unlock(struct hci_dev *hdev);
int __hci_req_sync(struct hci_dev *hdev, int (*req)(struct hci_request *req, unsigned long opt),
                   unsigned long opt, u32 timeout, u8 *hci_status);

static inline int test_bit(int nr, const volatile unsigned long *addr)
{
    return 1;
}