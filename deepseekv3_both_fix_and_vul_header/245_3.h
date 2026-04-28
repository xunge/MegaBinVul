#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

typedef uint16_t u16;

#define EINVAL 22
#define ENODEV 19
#define PTR_ERR(ptr) ((long)(ptr))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)(-1000L))
#define BUG_ON(condition) do { if (condition) abort(); } while (0)

struct device {
    void *parent;
    void *class;
    void *groups;
};

struct mutex {
    int dummy;
};

struct class {
    int dummy;
};

struct mii_bus {
    const char *name;
    int (*read)(struct mii_bus *, int, int);
    int (*write)(struct mii_bus *, int, int, u16);
    int state;
    struct module *owner;
    void *parent;
    struct device dev;
    const char *id;
    struct mutex mdio_lock;
    struct gpio_desc *reset_gpiod;
    unsigned int reset_delay_us;
    int (*reset)(struct mii_bus *);
    unsigned int phy_mask;
    struct mdio_device *mdio_map[32];
};

struct mdio_device {
    void (*device_remove)(struct mdio_device *);
    void (*device_free)(struct mdio_device *);
};

struct phy_device;
struct gpio_desc;
struct module;
struct class mdio_bus_class = {0};

#define MDIOBUS_ALLOCATED 1
#define MDIOBUS_UNREGISTERED 2
#define MDIOBUS_REGISTERED 3
#define PHY_MAX_ADDR 32
#define GPIOD_OUT_LOW 0

#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define pr_info(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)
#define dev_err(dev, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

static inline void mutex_init(struct mutex *lock) { (void)lock; }
static inline int device_register(struct device *dev) { (void)dev; return 0; }
static inline void put_device(struct device *dev) { (void)dev; }
static inline void dev_set_name(struct device *dev, const char *fmt, ...) { (void)dev; (void)fmt; }
static inline int device_del(struct device *dev) { (void)dev; return 0; }
static inline struct gpio_desc *devm_gpiod_get_optional(struct device *dev, const char *con_id, int flags) { (void)dev; (void)con_id; (void)flags; return NULL; }
static inline void gpiod_set_value_cansleep(struct gpio_desc *desc, int value) { (void)desc; (void)value; }
static inline void udelay(unsigned long usecs) { (void)usecs; }
static inline struct phy_device *mdiobus_scan(struct mii_bus *bus, int addr) { (void)bus; (void)addr; return NULL; }
static inline void mdiobus_setup_mdiodev_from_board_info(struct mii_bus *bus, void *func) { (void)bus; (void)func; }
static void *mdiobus_create_device;