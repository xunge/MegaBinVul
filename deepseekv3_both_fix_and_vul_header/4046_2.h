#include <stdint.h>
#include <stddef.h>

#define EINVAL 22
#define ENODEV 19
#define EINPROGRESS 115

#define NFC_ATTR_DEVICE_INDEX 0
#define NFC_ATTR_LLC_PARAM_LTO 1
#define NFC_ATTR_LLC_PARAM_RW 2
#define NFC_ATTR_LLC_PARAM_MIUX 3

#define LLCP_MAX_RW 15
#define LLCP_MAX_MIUX 0x7ff

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct sk_buff {
    // dummy definition
};

struct genl_info {
    void *attrs[4]; // NFC_ATTR_* indices
};

struct device {
    // dummy definition
};

struct nfc_dev {
    struct device dev;
    int dep_link_up;
};

struct nfc_llcp_local {
    u8 lto;
    u8 rw;
    u16 miux;
};

static inline u8 nla_get_u8(void *attr) { return 0; }
static inline u16 nla_get_u16(void *attr) { return 0; }
static inline u32 nla_get_u32(void *attr) { return 0; }
static inline u16 cpu_to_be16(u16 val) { return val; }

static inline struct nfc_dev *nfc_get_device(u32 idx) { return NULL; }
static inline void nfc_put_device(struct nfc_dev *dev) {}
static inline struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev) { return NULL; }

static inline void device_lock(struct device *dev) {}
static inline void device_unlock(struct device *dev) {}