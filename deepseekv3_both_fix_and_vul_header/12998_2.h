#include <stdbool.h>
#include <stddef.h>

struct device {
    // Minimal device structure
};

struct serdev_device {
    struct device dev;
};

struct hci_uart {
    struct serdev_device *serdev;
    struct hci_dev *hdev;
};

struct hci_dev {
    unsigned long quirks;
    int (*shutdown)(struct hci_dev *hdev);
};

struct gpio_desc {
    // Minimal GPIO descriptor
};

struct clk {
    // Minimal clock structure
};

enum qca_soc_type {
    QCA_ROME,
    QCA_WCN3990,
    QCA_WCN3991,
    QCA_WCN3998,
    QCA_WCN6750
};

#define QCA_CAP_WIDEBAND_SPEECH (1 << 0)
#define QCA_CAP_VALID_LE_STATES (1 << 1)

#define SUSCLK_RATE_32KHZ 32768

#define GFP_KERNEL 0
#define ENOMEM 12
#define GPIOD_OUT_LOW 0
#define GPIOD_IN 0
#define HCI_QUIRK_NON_PERSISTENT_SETUP 0
#define HCI_QUIRK_WIDEBAND_SPEECH_SUPPORTED 1
#define HCI_QUIRK_VALID_LE_STATES 2

#define BT_DBG(fmt, ...)
#define BT_ERR(fmt, ...)
#define dev_err(dev, fmt, ...)
#define dev_warn(dev, fmt, ...)

struct qca_serdev {
    struct hci_uart serdev_hu;
    enum qca_soc_type btsoc_type;
    struct qca_power *bt_power;
    struct gpio_desc *bt_en;
    struct gpio_desc *sw_ctrl;
    struct clk *susclk;
    const char *firmware_name;
    unsigned int oper_speed;
};

struct qca_power {
    struct device *dev;
    bool vregs_on;
};

struct qca_device_data {
    enum qca_soc_type soc_type;
    const char * const *vregs;
    size_t num_vregs;
    unsigned int capabilities;
};

struct hci_uart_proto;

static inline bool qca_is_wcn399x(enum qca_soc_type soc_type)
{
    return soc_type == QCA_WCN3990 || soc_type == QCA_WCN3991 || soc_type == QCA_WCN3998;
}

static inline bool qca_is_wcn6750(enum qca_soc_type soc_type)
{
    return soc_type == QCA_WCN6750;
}

static inline void *devm_kzalloc(struct device *dev, size_t size, int gfp)
{
    return NULL;
}

static inline void *device_get_match_data(struct device *dev)
{
    return NULL;
}

static inline void serdev_device_set_drvdata(struct serdev_device *serdev, void *data)
{
}

static inline int device_property_read_string(struct device *dev, const char *propname, const char **ret)
{
    return 0;
}

static inline int device_property_read_u32(struct device *dev, const char *propname, unsigned int *ret)
{
    return 0;
}

static inline struct gpio_desc *devm_gpiod_get_optional(struct device *dev, const char *con_id, int flags)
{
    return NULL;
}

static inline struct clk *devm_clk_get_optional(struct device *dev, const char *id)
{
    return NULL;
}

static inline int clk_set_rate(struct clk *clk, unsigned long rate)
{
    return 0;
}

static inline int clk_prepare_enable(struct clk *clk)
{
    return 0;
}

static inline void clk_disable_unprepare(struct clk *clk)
{
}

static inline void set_bit(unsigned int nr, volatile unsigned long *addr)
{
}

static inline int PTR_ERR(const void *ptr)
{
    return 0;
}

static inline bool IS_ERR(const void *ptr)
{
    return false;
}

extern int qca_init_regulators(struct qca_power *power, const char * const *vregs, size_t num_vregs);
extern int qca_power_off(struct hci_dev *hdev);
extern int hci_uart_register_device(struct hci_uart *hu, struct hci_uart_proto *p);
extern struct hci_uart_proto qca_proto;