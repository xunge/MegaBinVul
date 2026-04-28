#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define BITS_PER_BYTE 8
#define SPI_FRF_OFFSET 8
#define SPI_SCOL_OFFSET 6
#define SPI_SCPH_OFFSET 7
#define SPI_TMOD_OFFSET 8
#define SPI_TMOD_MASK (0x3 << SPI_TMOD_OFFSET)
#define SPI_CPOL 0x02
#define SPI_CPHA 0x01
#define SPI_TMOD_TR 0
#define SPI_TMOD_TO 1
#define SPI_TMOD_RO 2
#define DW_SPI_CTRL0 0
#define DW_SPI_TXFLTR 0
#define SPI_INT_TXEI (1 << 0)
#define SPI_INT_TXOI (1 << 1)
#define SPI_INT_RXUI (1 << 2)
#define SPI_INT_RXOI (1 << 3)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct spi_controller {
    bool (*can_dma)(struct spi_controller *, struct spi_device *, struct spi_transfer *);
    bool cur_msg_mapped;
    void *devdata;
};

struct spi_device {
    void *controller_data;
    u32 mode;
};

struct spi_transfer {
    const void *tx_buf;
    void *rx_buf;
    u32 len;
    u32 speed_hz;
    u8 bits_per_word;
};

struct dw_spi {
    void *devdata;
    int dma_mapped;
    void *tx;
    void *tx_end;
    void *rx;
    void *rx_end;
    int len;
    unsigned long buf_lock;
    unsigned int current_freq;
    unsigned int max_freq;
    unsigned int fifo_len;
    unsigned int n_bytes;
    unsigned int dma_width;
    void (*transfer_handler)(struct dw_spi *dws);
    struct dw_spi_dma_ops *dma_ops;
};

struct chip_data {
    unsigned int speed_hz;
    unsigned int clk_div;
    unsigned int type;
    unsigned int tmode;
    bool cs_control;
    bool poll_mode;
};

struct dw_spi_dma_ops {
    int (*dma_setup)(struct dw_spi *dws, struct spi_transfer *transfer);
    int (*dma_transfer)(struct dw_spi *dws, struct spi_transfer *transfer);
};

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void spi_enable_chip(struct dw_spi *dws, int enable) {}
static inline void spi_mask_intr(struct dw_spi *dws, u32 mask) {}
static inline void spi_umask_intr(struct dw_spi *dws, u32 mask) {}
static inline void spi_set_clk(struct dw_spi *dws, u16 div) {}
static inline void dw_writel(struct dw_spi *dws, u32 offset, u32 val) {}
static inline int poll_transfer(struct dw_spi *dws) { return 0; }
static inline void interrupt_transfer(struct dw_spi *dws) {}
static inline struct dw_spi *spi_controller_get_devdata(struct spi_controller *master) { return master->devdata; }
static inline struct chip_data *spi_get_ctldata(struct spi_device *spi) { return spi->controller_data; }

#define min_t(type, x, y) ({ \
    type __min1 = (x); \
    type __min2 = (y); \
    __min1 < __min2 ? __min1 : __min2; \
})