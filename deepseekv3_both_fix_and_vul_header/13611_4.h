#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define SJA1105_NUM_PORTS 5
#define RETRIES 10
#define ENOMEM 12
#define EINVAL 22
#define ENXIO 6
#define EIO 5
#define GFP_KERNEL 0
#define SPI_WRITE 0

typedef uint8_t u8;

struct device {
    // Dummy device structure
};

struct spi_device {
    struct device dev;
};

struct sja1105_static_config {
    uint64_t device_id;
};

struct sja1105_regs {
    int config;
};

struct sja1105_info {
    const struct sja1105_regs *regs;
    uint64_t device_id;
};

struct sja1105_private {
    struct sja1105_static_config static_config;
    struct sja1105_info *info;
    struct spi_device *spidev;
};

struct sja1105_status {
    uint64_t ids;
    uint64_t crcchkl;
    uint64_t crcchkg;
    uint64_t configs;
};

#define GENMASK_ULL(h, l) (((~0ULL) << (l)) & (~0ULL >> (64 - 1 - (h))))

static inline void *kcalloc(size_t n, size_t size, int flags) {
    return calloc(n, size);
}

static inline void kfree(void *p) {
    free(p);
}

static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline void dev_info(struct device *dev, const char *fmt, ...) {}
static inline void usleep_range(unsigned long min, unsigned long max) {
    usleep(min);
}

static inline int sja1105_static_config_get_length(struct sja1105_static_config *config) { return 0; }
static inline int static_config_buf_prepare_for_upload(struct sja1105_private *priv, u8 *buf, int len) { return 0; }
static inline int sja1105_inhibit_tx(struct sja1105_private *priv, unsigned long bitmap, bool inhibit) { return 0; }
static inline int sja1105_cold_reset(struct sja1105_private *priv) { return 0; }
static inline int sja1105_spi_send_long_packed_buf(struct sja1105_private *priv, int write, int reg, u8 *buf, int len) { return 0; }
static inline int sja1105_status_get(struct sja1105_private *priv, struct sja1105_status *status) { return 0; }
static inline int sja1105_ptp_reset(struct sja1105_private *priv) { return 0; }