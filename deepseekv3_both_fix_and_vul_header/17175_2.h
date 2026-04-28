#include <stdbool.h>
#include <stddef.h>

#define HI3660_STUB_CLOCK_DATA 0
#define HI3660_CLK_STUB_NUM 32
#define IORESOURCE_MEM 1
#define EINVAL 1
#define ENOMEM 2
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)

struct device {
    int dummy;
};

struct platform_device {
    struct device dev;
};

struct resource {
    unsigned long start;
};

struct clk_hw {
    int dummy;
};

struct mbox_client {
    struct device *dev;
    void (*tx_done)(void);
    bool tx_block;
    bool knows_txdone;
};

struct mbox_chan {
    int dummy;
};

struct hi3660_stub_clk_chan {
    struct mbox_client cl;
    struct mbox_chan *mbox;
};

struct hi3660_stub_clk {
    struct clk_hw hw;
};

static struct hi3660_stub_clk_chan stub_clk_chan;
static void *freq_reg;
static struct hi3660_stub_clk hi3660_stub_clks[HI3660_CLK_STUB_NUM];

static struct clk_hw *hi3660_stub_clk_hw_get(struct of_phandle_args *clkspec, void *data) {
    return NULL;
}

static void *devm_ioremap(struct device *dev, unsigned long start, size_t size) { return NULL; }
static size_t resource_size(struct resource *res) { return 0; }
static struct resource *platform_get_resource(struct platform_device *pdev, int type, int num) { return NULL; }
static int devm_clk_hw_register(struct device *dev, struct clk_hw *hw) { return 0; }
static int devm_of_clk_add_hw_provider(struct device *dev, void *get, void *data) { return 0; }
static struct mbox_chan *mbox_request_channel(struct mbox_client *cl, int index) { return NULL; }