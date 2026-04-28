#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uintptr_t dma_addr_t;
typedef uint16_t u16;

struct device {
    void *of_node;
    void *fwnode;
};

struct spi_device;
struct spi_transfer;

struct spi_controller {
    bool use_gpio_descriptors;
    unsigned int mode_bits;
    unsigned int bits_per_word_mask;
    int bus_num;
    u16 num_chipselect;
    int (*setup)(struct spi_device *spi);
    void (*cleanup)(struct spi_device *spi);
    void (*set_cs)(struct spi_device *spi, bool enable);
    int (*transfer_one)(struct spi_controller *ctlr, struct spi_device *spi, struct spi_transfer *transfer);
    void (*handle_err)(struct spi_controller *ctlr, struct spi_device *spi, struct spi_transfer *transfer);
    unsigned int max_speed_hz;
    struct device dev;
    unsigned int flags;
    bool auto_runtime_pm;
    bool (*can_dma)(struct spi_controller *master, struct spi_device *spi, struct spi_transfer *xfer);
};

struct dw_spi {
    struct spi_controller *master;
    unsigned int type;
    int dma_inited;
    dma_addr_t dma_addr;
    uintptr_t paddr;
    unsigned int irq;
    int bus_num;
    u16 num_cs;
    unsigned int max_freq;
    struct device *dev;
    const struct dw_spi_dma_ops *dma_ops;
    void (*set_cs)(struct spi_device *spi, bool enable);
    unsigned long buf_lock;
};

struct dw_spi_dma_ops {
    int (*dma_init)(struct dw_spi *dws);
    void (*dma_exit)(struct dw_spi *dws);
    bool (*can_dma)(struct spi_controller *master, struct spi_device *spi, struct spi_transfer *xfer);
};

#define DW_SPI_DR 0x60
#define SSI_MOTO_SPI 0
#define SPI_BPW_RANGE_MASK(min, max) (((1U << ((max) - (min) + 1)) - 1) << (min))
#define BUG_ON(cond) ((void)0)
#define ENOMEM 12
#define IRQF_SHARED 0x00000080
#define SPI_CPOL 0x01
#define SPI_CPHA 0x02
#define SPI_LOOP 0x04
#define SPI_MASTER_GPIO_SS 0x08

static inline struct spi_controller *spi_alloc_master(struct device *dev, unsigned size) { return NULL; }
static inline void spi_controller_set_devdata(struct spi_controller *ctlr, void *data) {}
static inline int request_irq(unsigned int irq, void (*handler)(int, void *), unsigned long flags, const char *name, void *dev) { return 0; }
static inline const char *dev_name(const struct device *dev) { return NULL; }
static inline void dev_err(const struct device *dev, const char *fmt, ...) {}
static inline void dev_warn(const struct device *dev, const char *fmt, ...) {}
static inline int devm_spi_register_controller(struct device *dev, struct spi_controller *ctlr) { return 0; }
static inline void free_irq(unsigned int irq, void *dev_id) {}
static inline void spi_controller_put(struct spi_controller *ctlr) {}
static inline void dw_spi_irq(int irq, void *dev_id) {}
static inline int dw_spi_setup(struct spi_device *spi) { return 0; }
static inline void dw_spi_cleanup(struct spi_device *spi) {}
static inline void dw_spi_set_cs(struct spi_device *spi, bool enable) {}
static inline int dw_spi_transfer_one(struct spi_controller *ctlr, struct spi_device *spi, struct spi_transfer *transfer) { return 0; }
static inline void dw_spi_handle_err(struct spi_controller *ctlr, struct spi_device *spi, struct spi_transfer *transfer) {}
static inline void spi_hw_init(struct device *dev, struct dw_spi *dws) {}
static inline void dw_spi_debugfs_init(struct dw_spi *dws) {}
static inline void spi_enable_chip(struct dw_spi *dws, int enable) {}