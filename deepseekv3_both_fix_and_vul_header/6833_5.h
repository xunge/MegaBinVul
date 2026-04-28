#include <stddef.h>
#include <stdint.h>

typedef int irqreturn_t;
#define IRQ_NONE 0
#define IRQ_HANDLED 1

struct device {
    const char *name;
    void *of_node;
};

struct platform_device {
    struct device dev;
    const char *name;
};

struct device_node;

struct resource {
    unsigned long start;
    unsigned long end;
};

struct gpio_chip {
    int (*direction_input)(struct gpio_chip *, unsigned);
    int (*direction_output)(struct gpio_chip *, unsigned, int);
    int (*get)(struct gpio_chip *, unsigned);
    void (*set)(struct gpio_chip *, unsigned, int);
    int (*set_debounce)(struct gpio_chip *, unsigned, unsigned);
    void (*dbg_show)(void *, void *);
    int base;
    const char *label;
    void *owner;
    struct device *parent;
    unsigned ngpio;
    void *of_node;
};

struct pinctrl_dev;
struct attribute_group;
struct irq_chip {
    const char *name;
};
struct seq_file;

struct amd_gpio {
    void *lock;
    void *base;
    struct platform_device *pdev;
    struct gpio_chip gc;
    struct pinctrl_dev *pctrl;
    const struct attribute_group **groups;
    unsigned int ngroups;
};

struct pinctrl_desc {
    const char *name;
};

#define GFP_KERNEL 0
#define ENOMEM 1
#define EINVAL 2
#define ENODEV 3
#define THIS_MODULE NULL
#define TOTAL_NUMBER_OF_PINS 0
#define CONFIG_OF_GPIO 0
#define IORESOURCE_MEM 0
#define IRQ_TYPE_NONE 0

static const struct attribute_group *kerncz_groups[] = {NULL};
static struct pinctrl_desc amd_pinctrl_desc;
static struct irq_chip amd_gpio_irqchip;

static int amd_gpio_direction_input(struct gpio_chip *gc, unsigned offset) { return 0; }
static int amd_gpio_direction_output(struct gpio_chip *gc, unsigned offset, int value) { return 0; }
static int amd_gpio_get_value(struct gpio_chip *gc, unsigned offset) { return 0; }
static void amd_gpio_set_value(struct gpio_chip *gc, unsigned offset, int value) {}
static int amd_gpio_set_debounce(struct gpio_chip *gc, unsigned offset, unsigned debounce) { return 0; }
static void amd_gpio_dbg_show(void *s, void *gc) {}
static irqreturn_t amd_gpio_irq_handler(int irq, void *dev_id) { return IRQ_NONE; }
static irqreturn_t handle_simple_irq(int irq, void *dev_id) { return IRQ_NONE; }

static void *devm_kzalloc(struct device *dev, size_t size, int flags) { return NULL; }
static void spin_lock_init(void *lock) {}
static struct resource *platform_get_resource(struct platform_device *pdev, int type, int num) { return NULL; }
static void *devm_ioremap_nocache(struct device *dev, unsigned long offset, size_t size) { return NULL; }
static int platform_get_irq(struct platform_device *pdev, int num) { return 0; }
static void dev_err(struct device *dev, const char *fmt, ...) {}
static size_t resource_size(const struct resource *res) { return 0; }
static const char *dev_name(const struct device *dev) { return NULL; }
static void *pinctrl_register(const struct pinctrl_desc *desc, struct device *dev, void *driver_data) { return NULL; }
static int IS_ERR(const void *ptr) { return 0; }
static long PTR_ERR(const void *ptr) { return 0; }
static int gpiochip_add_data(struct gpio_chip *gc, void *data) { return 0; }
static int gpiochip_add_pin_range(struct gpio_chip *gc, const char *name, unsigned offset, unsigned pin_base, unsigned npins) { return 0; }
static int gpiochip_irqchip_add(struct gpio_chip *gc, struct irq_chip *irqchip, unsigned int first_irq, void *handler, unsigned int type) { return 0; }
static void gpiochip_set_chained_irqchip(struct gpio_chip *gc, struct irq_chip *irqchip, int irq, void *handler) {}
static void platform_set_drvdata(struct platform_device *pdev, void *data) {}
static void dev_dbg(struct device *dev, const char *fmt, ...) {}
static void gpiochip_remove(struct gpio_chip *gc) {}
static void pinctrl_unregister(void *pctrl) {}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))