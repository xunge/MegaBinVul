#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

struct dw_spi {
    u32 buf_lock;
    void *tx;
    void *tx_end;
    int len;
    int n_bytes;
};

#define DW_SPI_DR 0

static inline void spin_lock(u32 *lock) {}
static inline void spin_unlock(u32 *lock) {}
static inline void dw_write_io_reg(struct dw_spi *dws, int reg, u16 val) {}
static inline u32 tx_max(struct dw_spi *dws) { return 0; }