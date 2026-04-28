#include <stdint.h>

#define NFC_ATTR_DEVICE_INDEX 0
#define NFC_ATTR_TARGET_INDEX 0
#define NFC_TARGET_MODE_SLEEP 0
#define EINVAL 22
#define ENODEV 19

typedef uint32_t u32;

struct nfc_dev;
struct sk_buff;
struct genl_info {
    void **attrs;
};

extern struct nfc_dev *nfc_get_device(u32 device_idx);
extern int nfc_deactivate_target(struct nfc_dev *dev, u32 target_idx, int mode);
extern void nfc_put_device(struct nfc_dev *dev);
extern u32 nla_get_u32(void *attr);