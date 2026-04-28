#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct device {
    void *platform_data;
    void *of_node;
};

struct platform_device {
    const char *name;
    int id;
    struct device dev;
};

struct device_node;

struct resource {
    unsigned long start;
    unsigned long end;
};

struct mii_bus {
    const char *name;
    void *priv;
    uint32_t phy_mask;
    struct device *parent;
    char id[20];
    int (*read)(struct mii_bus *bus, int phy_id, int reg);
    int (*write)(struct mii_bus *bus, int phy_id, int reg, uint16_t val);
    int (*reset)(struct mii_bus *bus);
};

struct unimac_mdio_pdata {
    const char *bus_name;
    uint32_t phy_mask;
    int (*wait_func)(void *wait_func_data);
    void *wait_func_data;
};

struct unimac_mdio_priv {
    void *base;
    struct mii_bus *mii_bus;
    int (*wait_func)(void *wait_func_data);
    void *wait_func_data;
};

#define GFP_KERNEL 0
#define ENOMEM 1
#define EINVAL 2
#define IORESOURCE_MEM 0
#define MII_BUS_ID_SIZE 20

static void *devm_kzalloc(struct device *dev, size_t size, int flags) { return malloc(size); }
static struct resource *platform_get_resource(struct platform_device *pdev, int type, int num) { return NULL; }
static void *devm_ioremap(struct device *dev, unsigned long offset, size_t size) { return NULL; }
static size_t resource_size(const struct resource *res) { return 0; }
static void dev_err(struct device *dev, const char *fmt, ...) {}
static struct mii_bus *mdiobus_alloc(void) { return malloc(sizeof(struct mii_bus)); }
static int of_mdiobus_register(struct mii_bus *bus, struct device_node *np) { return 0; }
static void platform_set_drvdata(struct platform_device *pdev, void *data) {}
static void dev_info(struct device *dev, const char *fmt, ...) {}
static void mdiobus_free(struct mii_bus *bus) { free(bus); }

static int unimac_mdio_poll(void *wait_func_data) { return 0; }
static int unimac_mdio_read(struct mii_bus *bus, int phy_id, int reg) { return 0; }
static int unimac_mdio_write(struct mii_bus *bus, int phy_id, int reg, uint16_t val) { return 0; }
static int unimac_mdio_reset(struct mii_bus *bus) { return 0; }