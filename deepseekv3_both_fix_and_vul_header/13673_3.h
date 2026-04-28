#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define DRIVER_NAME "fsl_lpspi"
#define IMX7ULP_PARAM 0
#define ENOMEM 1
#define EPROBE_DEFER 2
#define IORESOURCE_MEM 0

#define SPI_BPW_RANGE_MASK(min, max) ((1U << ((max) + 1)) - (1U << (min)))
#define SPI_CPOL 0x01
#define SPI_CPHA 0x02
#define SPI_CS_HIGH 0x04
#define SPI_MASTER_MUST_RX 0x01
#define SPI_MASTER_MUST_TX 0x02

typedef uint32_t u32;

struct device_node;
struct device {
    struct device_node *of_node;
};
struct spi_controller {
    unsigned int num_chipselect;
    int *cs_gpios;
    int (*prepare_message)(struct spi_controller *, void *);
    unsigned int bits_per_word_mask;
    int (*transfer_one)(struct spi_controller *, void *, void *);
    int (*prepare_transfer_hardware)(struct spi_controller *);
    int (*unprepare_transfer_hardware)(struct spi_controller *);
    unsigned int mode_bits;
    unsigned int flags;
    struct device dev;
    int bus_num;
    int (*slave_abort)(struct spi_controller *);
};
struct resource {
    uintptr_t start;
};
struct clk;
struct completion {
    unsigned int done;
};

struct platform_device {
    struct device dev;
    int id;
};

struct fsl_lpspi_data {
    struct device *dev;
    bool is_slave;
    int *chipselect;
    void *base;
    uintptr_t base_phys;
    struct clk *clk_per;
    struct clk *clk_ipg;
    struct completion xfer_done;
    unsigned int txfifosize;
    unsigned int rxfifosize;
};

struct spi_imx_master {
    int *chipselect;
};

static inline bool of_property_read_bool(struct device_node *np, const char *prop) { return false; }
static inline int of_get_named_gpio(struct device_node *np, const char *prop, int index) { return -1; }
static inline bool gpio_is_valid(int gpio) { return false; }
static inline int devm_gpio_request(struct device *dev, int gpio, const char *label) { return 0; }
static inline void *devm_ioremap_resource(struct device *dev, struct resource *res) { return NULL; }
static inline int platform_get_irq(struct platform_device *pdev, int num) { return -1; }
static inline int devm_request_irq(struct device *dev, int irq, void (*handler)(int, void*), unsigned long flags, const char *name, void *dev_id) { return 0; }
static inline struct clk *devm_clk_get(struct device *dev, const char *id) { return NULL; }
static inline int pm_runtime_get_sync(struct device *dev) { return 0; }
static inline unsigned int readl(void *addr) { return 0; }
static inline int devm_spi_register_controller(struct device *dev, struct spi_controller *ctrl) { return 0; }
static inline void spi_controller_put(struct spi_controller *ctrl) {}
static inline struct spi_controller *spi_alloc_slave(struct device *dev, unsigned int size) { return NULL; }
static inline struct spi_controller *spi_alloc_master(struct device *dev, unsigned int size) { return NULL; }
static inline void platform_set_drvdata(struct platform_device *pdev, void *data) {}
static inline struct fsl_lpspi_data *spi_controller_get_devdata(struct spi_controller *ctrl) { return NULL; }
static inline void init_completion(struct completion *c) {}
static inline void *dev_get_platdata(struct device *dev) { return NULL; }
static inline struct resource *platform_get_resource(struct platform_device *pdev, unsigned int type, unsigned int num) { return NULL; }
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline const char *dev_name(struct device *dev) { return NULL; }

static int fsl_lpspi_prepare_message(struct spi_controller *ctrl, void *msg) { return 0; }
static int fsl_lpspi_transfer_one(struct spi_controller *ctrl, void *spi, void *tfr) { return 0; }
static int lpspi_prepare_xfer_hardware(struct spi_controller *ctrl) { return 0; }
static int lpspi_unprepare_xfer_hardware(struct spi_controller *ctrl) { return 0; }
static int fsl_lpspi_slave_abort(struct spi_controller *ctrl) { return 0; }
static void fsl_lpspi_isr(int irq, void *dev_id) {}
static int fsl_lpspi_init_rpm(struct fsl_lpspi_data *fsl_lpspi) { return 0; }
static int fsl_lpspi_dma_init(struct device *dev, struct fsl_lpspi_data *fsl_lpspi, struct spi_controller *controller) { return 0; }

#define PTR_ERR(x) ((int)(intptr_t)(x))
#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))