#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct device {
    struct device *parent;
};

struct pci_dev {
    struct device dev;
    unsigned int irq;
};

struct pci_device_id {
    void *driver_data;
};

struct property_entry {
    void *driver_data;
};

struct resource {
    unsigned long start;
    unsigned long end;
    const char *name;
    unsigned long flags;
};

struct platform_device {
    struct device dev;
};

struct work_struct {
    void *data;
};

struct dwc3_pci {
    struct pci_dev *pci;
    struct platform_device *dwc3;
    struct work_struct wakeup_work;
};

#define PLATFORM_DEVID_AUTO (-2)
#define IORESOURCE_MEM 0x00000200
#define IORESOURCE_IRQ 0x00000400
#define GFP_KERNEL 0
#define ENODEV 19
#define ENOMEM 12
#define CONFIG_PM 1
#define true 1
#define false 0

unsigned long pci_resource_start(struct pci_dev *pdev, int bar);
unsigned long pci_resource_end(struct pci_dev *pdev, int bar);
int pcim_enable_device(struct pci_dev *pdev);
void pci_set_master(struct pci_dev *pdev);
void *devm_kzalloc(struct device *dev, size_t size, int flags);
struct platform_device *platform_device_alloc(const char *name, int id);
int platform_device_add_resources(struct platform_device *pdev, struct resource *res, int num);
int platform_device_add_properties(struct platform_device *pdev, struct property_entry *properties);
int platform_device_add(struct platform_device *pdev);
void platform_device_put(struct platform_device *pdev);
void device_init_wakeup(struct device *dev, bool val);
void pci_set_drvdata(struct pci_dev *pdev, void *data);
void pm_runtime_put(struct device *dev);
void INIT_WORK(struct work_struct *work, void (*func)(struct work_struct *work));
void dwc3_pci_resume_work(struct work_struct *work);
int dwc3_pci_quirks(struct dwc3_pci *dwc);
void dev_err(struct device *dev, const char *fmt, ...);

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define ACPI_COMPANION(dev) NULL
#define ACPI_COMPANION_SET(dev, acpi) do {} while (0)