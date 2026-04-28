#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

struct device {
    struct device_node *of_node;
};

struct device_node;

struct platform_device {
    struct device dev;
};

struct resource {
    unsigned long start;
    unsigned long end;
};

struct reset_control;
struct clk;

struct dwc3 {
    struct device dev;
};

struct acpi_pdata {
    unsigned long qscratch_base_offset;
    unsigned long qscratch_base_size;
    bool is_urs;
};

struct dwc3_qcom {
    struct device *dev;
    struct acpi_pdata *acpi_pdata;
    struct reset_control *resets;
    struct clk **clks;
    int num_clocks;
    void *qscratch_base;
    struct platform_device *urs_usb;
    struct dwc3 *dwc3;
    int mode;
    bool is_suspended;
};

#define GFP_KERNEL 0
#define ENOMEM 1
#define EINVAL 2
#define ENODEV 3
#define IORESOURCE_MEM 0
#define USB_DR_MODE_PERIPHERAL 0

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((int)(intptr_t)(x))

static inline void *devm_kzalloc(struct device *dev, size_t size, int flags) {
    return calloc(1, size);
}

static inline void platform_set_drvdata(struct platform_device *pdev, void *data) {}
static inline bool has_acpi_companion(struct device *dev) { return false; }
static inline void *acpi_device_get_match_data(struct device *dev) { return NULL; }
static inline struct reset_control *devm_reset_control_array_get_optional_exclusive(struct device *dev) { return NULL; }
static inline int reset_control_assert(struct reset_control *resets) { return 0; }
static inline int reset_control_deassert(struct reset_control *resets) { return 0; }
static inline void usleep_range(unsigned min, unsigned max) {}
static inline int of_clk_get_parent_count(struct device_node *np) { return 0; }
static inline struct resource *platform_get_resource(struct platform_device *pdev, int type, int num) { return NULL; }
static inline void *kmemdup(const void *src, size_t size, int flags) { void *p = malloc(size); if (p) memcpy(p, src, size); return p; }
static inline void *devm_ioremap_resource(struct device *dev, struct resource *res) { return NULL; }
static inline bool device_property_read_bool(struct device *dev, const char *prop) { return false; }
static inline int usb_get_dr_mode(struct device *dev) { return 0; }
static inline void device_init_wakeup(struct device *dev, bool val) {}
static inline void pm_runtime_set_active(struct device *dev) {}
static inline void pm_runtime_enable(struct device *dev) {}
static inline void pm_runtime_forbid(struct device *dev) {}
static inline void clk_disable_unprepare(struct clk *clk) {}
static inline void clk_put(struct clk *clk) {}
static inline void dev_err(struct device *dev, const char *fmt, ...) {}

static int dwc3_qcom_clk_init(struct dwc3_qcom *qcom, int count) { return 0; }
static int dwc3_qcom_setup_irq(struct platform_device *pdev) { return 0; }
static void dwc3_qcom_select_utmi_clk(struct dwc3_qcom *qcom) {}
static int dwc3_qcom_of_register_core(struct platform_device *pdev) { return 0; }
static int dwc3_qcom_acpi_register_core(struct platform_device *pdev) { return 0; }
static int dwc3_qcom_interconnect_init(struct dwc3_qcom *qcom) { return 0; }
static void dwc3_qcom_vbus_override_enable(struct dwc3_qcom *qcom, bool enable) {}
static int dwc3_qcom_register_extcon(struct dwc3_qcom *qcom) { return 0; }
static void dwc3_qcom_interconnect_exit(struct dwc3_qcom *qcom) {}
static void of_platform_depopulate(struct device *dev) {}
static struct platform_device *dwc3_qcom_create_urs_usb_platdev(struct device *dev) { return NULL; }
static void platform_device_put(struct platform_device *pdev) {}