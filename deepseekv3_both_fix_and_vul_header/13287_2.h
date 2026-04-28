#include <stdint.h>
#include <string.h>

typedef uint32_t u32;
typedef uint64_t dma_addr_t;

#define I2C_SMBUS_BLOCK_MAX 32
#define SLIMPRO_IIC_BUS 0
#define SLIMPRO_IIC_WRITE 0
#define SLIMPRO_IIC_ENCODE_MSG(bus, chip, op, protocol, addrlen, datalen) 0
#define SLIMPRO_IIC_ENCODE_FLAG_BUFADDR 0
#define SLIMPRO_IIC_ENCODE_UPPER_BUFADDR(addr) 0
#define SLIMPRO_IIC_ENCODE_ADDR(addr) 0
#define DMA_TO_DEVICE 0
#define EINVAL 22
#define ENOMEM 12

struct device {
    int dummy;
};

struct i2c_adapter {
    struct device dev;
};

struct mbox_client {
    int tx_block;
};

struct completion {
    int dummy;
};

struct slimpro_i2c_dev {
    struct device *dev;
    struct i2c_adapter adapter;
    struct mbox_client mbox_client;
    struct completion rd_complete;
    void *dma_buffer;
};

static inline dma_addr_t dma_map_single(struct device *dev, void *ptr, size_t size, int dir) { return 0; }
static inline int dma_mapping_error(struct device *dev, dma_addr_t addr) { return 0; }
static inline void dma_unmap_single(struct device *dev, dma_addr_t addr, size_t size, int dir) {}
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline void reinit_completion(struct completion *x) {}