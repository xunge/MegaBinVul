#include <stdlib.h>
#include <string.h>

struct device {
    const char *type;
    void *dma_mask;
    void *dma_parms;
    unsigned long coherent_dma_mask;
    struct device *parent;
};

struct resource {
    unsigned long flags;
    unsigned long start;
    unsigned long end;
};

struct platform_device {
    struct device dev;
    const char *name;
};

struct dwc3_qcom {
    struct platform_device *dwc3;
    struct platform_device *urs_usb;
    struct acpi_pdata *acpi_pdata;
};

struct acpi_pdata {
    size_t dwc3_core_base_size;
};

struct software_node;
extern const struct software_node dwc3_qcom_swnode;

#define PLATFORM_DEVID_AUTO (-2)
#define IORESOURCE_MEM 0x00000200
#define IORESOURCE_IRQ 0x00000400
#define GFP_KERNEL 0
#define ENOMEM 12
#define ENODEV 19

static inline void *platform_get_drvdata(const struct platform_device *pdev) { return NULL; }
static inline struct platform_device *platform_device_alloc(const char *name, int id) { return NULL; }
static inline struct resource *platform_get_resource(struct platform_device *pdev, unsigned int type, unsigned int num) { return NULL; }
static inline int platform_get_irq(struct platform_device *pdev, unsigned int num) { return 0; }
static inline int platform_device_add_resources(struct platform_device *pdev, const struct resource *res, unsigned int num) { return 0; }
static inline int platform_device_add(struct platform_device *pdev) { return 0; }
static inline int device_add_software_node(struct device *dev, const struct software_node *node) { return 0; }
static inline void device_remove_software_node(struct device *dev) {}
static inline void *kcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }
static inline void kfree(void *p) { free(p); }
static inline void dev_err(const struct device *dev, const char *fmt, ...) {}