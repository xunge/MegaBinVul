#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

enum wimax_rf_state {
    WIMAX_RF_OFF,
    WIMAX_RF_ON
};

struct wimax_dev;
struct device;
struct sk_buff;

struct i2400m {
    void *state_wq;
};

struct i2400m_l3l4_hdr {
    uint16_t type;
    uint16_t length;
    uint16_t version;
};

struct i2400m_tlv_hdr {
    uint16_t type;
    uint16_t length;
};

struct i2400m_tlv_rf_operation {
    struct i2400m_tlv_hdr hdr;
    uint32_t status;
};

#define I2400M_MT_CMD_RF_CONTROL 0x0000
#define I2400M_L3L4_VERSION 0x0100
#define I2400M_TLV_RF_OPERATION 0x0000

#define __packed __attribute__((packed))
#define GFP_KERNEL 0
#define HZ 100
#define ENOMEM 12
#define ETIMEDOUT 110

#define cpu_to_le16(x) (x)
#define cpu_to_le32(x) (x)

#define d_fnstart(level, dev, fmt, ...)
#define d_fnend(level, dev, fmt, ...)

#define PTR_ERR(ptr) ((long)(ptr))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)(-1000))

#define BUG() assert(0)

static inline struct i2400m *wimax_dev_to_i2400m(struct wimax_dev *wimax_dev) { return NULL; }
static inline struct device *i2400m_dev(struct i2400m *i2400m) { return NULL; }
static inline struct sk_buff *i2400m_msg_to_dev(struct i2400m *i2400m, void *cmd, size_t size) { return NULL; }
static inline int i2400m_msg_check_status(void *msg, char *strerr, size_t size) { return 0; }
static inline void *wimax_msg_data(struct sk_buff *skb) { return NULL; }
static inline int i2400m_radio_is(struct i2400m *i2400m, enum wimax_rf_state state) { return 0; }
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void kfree_skb(struct sk_buff *skb) { free(skb); }
static inline int wait_event_timeout(void *wq, int condition, int timeout) { return 0; }