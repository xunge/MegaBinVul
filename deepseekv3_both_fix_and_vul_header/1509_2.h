#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint64_t dma_addr_t;

#define I2C_SMBUS_WRITE 0
#define I2C_SMBUS_READ 1
#define I2C_SMBUS_QUICK 0
#define I2C_SMBUS_BYTE 1
#define I2C_SMBUS_BYTE_DATA 2
#define I2C_SMBUS_WORD_DATA 3
#define I2C_SMBUS_PROC_CALL 4
#define I2C_SMBUS_BLOCK_DATA 5
#define I2C_SMBUS_BLOCK_PROC_CALL 6
#define I2C_SMBUS_I2C_BLOCK_DATA 8
#define I2C_CLIENT_PEC 0x04

struct device {
    // minimal stub
};

struct pci_dev {
    struct device dev;
    // minimal stub
};

struct i2c_adapter {
    // minimal stub
};

struct ismt_desc {
    u32 tgtaddr_rw;
    u32 wr_len_cmd;
    u32 rd_len;
    u32 control;
    u32 dptr_low;
    u32 dptr_high;
};

struct ismt_priv {
    struct pci_dev *pci_dev;
    u8 buffer[256];
    struct ismt_desc *hw;
    u32 *log;
    unsigned int head;
    // completion stub
    int cmp;
};

union i2c_smbus_data {
    u8 byte;
    u16 word;
    u8 block[33];
};

enum dma_data_direction {
    DMA_BIDIRECTIONAL = 0,
    DMA_TO_DEVICE = 1,
    DMA_FROM_DEVICE = 2,
    DMA_NONE = 3,
};

#define ISMT_DESC_ADDR_RW(addr, rw) (((addr) << 1) | (rw))
#define ISMT_DESC_INT    (1 << 2)
#define ISMT_DESC_FAIR   (1 << 3)
#define ISMT_DESC_PEC    (1 << 4)
#define ISMT_DESC_CWRL   (1 << 5)
#define ISMT_DESC_BLK    (1 << 6)
#define ISMT_DESC_I2C    (1 << 7)

#define ISMT_LOG_ENTRIES 32
#define ISMT_DESC_ENTRIES 32
#define I2C_SMBUS_BLOCK_MAX 32

#define EINVAL 22
#define EIO 5
#define ETIMEDOUT 110
#define EOPNOTSUPP 95

static inline uint32_t lower_32_bits(uint64_t val) {
    return (uint32_t)val;
}

static inline uint32_t upper_32_bits(uint64_t val) {
    return (uint32_t)(val >> 32);
}

#define likely(x) (x)
#define unlikely(x) (x)
#define PTR_ALIGN(p, align) ((typeof(p))((unsigned long)(p) & ~(align-1)))

#define HZ 100

static inline struct ismt_priv *i2c_get_adapdata(struct i2c_adapter *adap) {
    return (struct ismt_priv *)adap;
}

static inline int pci_dev_msi_enabled(struct pci_dev *dev) {
    return 0;
}

static inline dma_addr_t dma_map_single(struct device *dev, void *ptr, size_t size, enum dma_data_direction dir) {
    return (dma_addr_t)ptr;
}

static inline int dma_mapping_error(struct device *dev, dma_addr_t addr) {
    return 0;
}

static inline void dma_unmap_single(struct device *dev, dma_addr_t addr, size_t size, enum dma_data_direction dir) {
}

static inline unsigned long wait_for_completion_timeout(int *cmp, unsigned long timeout) {
    return 1;
}

static inline void reinit_completion(int *cmp) {
}

static inline void ismt_submit_desc(struct ismt_priv *priv) {
}

static inline int ismt_process_desc(struct ismt_desc *desc, union i2c_smbus_data *data, struct ismt_priv *priv, int size, char read_write) {
    return 0;
}

#define dev_dbg(dev, fmt, ...) 
#define dev_err(dev, fmt, ...) 