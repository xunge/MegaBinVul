#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define GFP_KERNEL 0
#define ENOMEM 12

typedef uint16_t __be16;

struct spi_transfer {
    int bits_per_word;
    int cs_change;
    int len;
    unsigned int delay_usecs;
    void *tx_buf;
    void *rx_buf;
};

struct spi_message {
    // dummy structure
};

struct adis {
    struct spi_transfer *xfer;
    void *buffer;
    struct spi_message msg;
    struct {
        unsigned int read_delay;
    } *data;
    struct {
        int en;
    } *burst;
};

struct iio_chan_spec {
    unsigned int scan_index;
    struct {
        unsigned int storagebits;
    } scan_type;
    unsigned int address;
};

struct iio_dev {
    const struct iio_chan_spec *channels;
    unsigned int num_channels;
    unsigned int scan_bytes;
    void *driver_data;
};

static inline void *kcalloc(size_t n, size_t size, int flags) {
    return calloc(n, size);
}

static inline void kfree(void *p) {
    free(p);
}

static inline void spi_message_init(struct spi_message *m) {
    memset(m, 0, sizeof(*m));
}

static inline void spi_message_add_tail(struct spi_transfer *t, struct spi_message *m) {
    // dummy implementation
}

static inline int test_bit(unsigned int nr, const unsigned long *addr) {
    return (addr[nr / (sizeof(*addr) * 8)] >> (nr % (sizeof(*addr) * 8))) & 1;
}

static inline __be16 cpu_to_be16(uint16_t x) {
    return ((x & 0xFF) << 8) | ((x >> 8) & 0xFF);
}

static inline void *iio_device_get_drvdata(struct iio_dev *indio_dev) {
    return indio_dev->driver_data;
}

static inline int adis_update_scan_mode_burst(struct iio_dev *indio_dev, const unsigned long *scan_mask) {
    return 0;
}