#include <stdint.h>
#include <stdatomic.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define DW_SPI_DR 0

struct dw_spi {
    atomic_flag buf_lock;
    void *rx;
    void *rx_end;
    int len;
    int n_bytes;
};

u32 rx_max(struct dw_spi *dws);
u16 dw_read_io_reg(struct dw_spi *dws, int reg);