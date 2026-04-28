#include <stdint.h>
#include <stdlib.h>

#define GFP_KERNEL 0
#define ENOMEM 12

typedef uint8_t u8;
typedef uint16_t u16;

struct spi_transfer {
    void *tx_buf;
    void *rx_buf;
    unsigned int bits_per_word;
    unsigned int len;
};

struct spi_message {
    // minimal definition needed
};

struct iio_dev {
    unsigned int num_channels;
    void *dev_data;
};

static inline void *iio_device_get_drvdata(struct iio_dev *indio_dev)
{
    return indio_dev->dev_data;
}

struct adis {
    struct spi_message msg;
    struct spi_transfer *xfer;
    u8 *buffer;
    struct {
        unsigned int extra_len;
        u16 reg_cmd;
    } *burst;
};

#define ADIS_READ_REG(reg) (reg)

static inline void spi_message_init(struct spi_message *msg) {}
static inline void spi_message_add_tail(struct spi_transfer *xfer, struct spi_message *msg) {}

void *kcalloc(size_t n, size_t size, int flags);
void *kzalloc(size_t size, int flags);