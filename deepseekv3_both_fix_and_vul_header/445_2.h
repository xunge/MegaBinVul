#include <stddef.h>
#include <stdint.h>

#define SERDES_MAX 1
#define GFP_KERNEL 0
#define ENOMEM 12
#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-4095))
#define PTR_ERR(x) ((int)(uintptr_t)(x))
#define PTR_ERR_OR_ZERO(x) (IS_ERR(x) ? PTR_ERR(x) : 0)

struct device {
    struct device *parent;
    void *of_node;
};

struct platform_device {
    struct device dev;
};

struct regmap;
struct phy;
struct phy_provider;

struct serdes_ctrl {
    struct device *dev;
    struct regmap *regs;
    struct phy *phys[SERDES_MAX + 1];
};

void *devm_kzalloc(struct device *dev, size_t size, int flags);
struct regmap *syscon_node_to_regmap(void *node);
int serdes_phy_create(struct serdes_ctrl *ctrl, unsigned int i, struct phy **phy);
void dev_set_drvdata(struct device *dev, void *data);
struct phy_provider *devm_of_phy_provider_register(struct device *dev, void *xlate);
void *serdes_simple_xlate;