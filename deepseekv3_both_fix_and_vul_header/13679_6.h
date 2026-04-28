#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;

struct device {
    int dummy;
};

struct platform_device {
    struct device dev;
    int id;
};

struct spi_device;
struct spi_transfer;

struct spi_master {
    unsigned int bus_num;
    unsigned int mode_bits;
    unsigned int flags;
    unsigned long bits_per_word_mask;
    int (*setup)(struct spi_device *spi);
    void (*cleanup)(struct spi_device *spi);
};

struct spi_bitbang {
    struct spi_master *master;
    void (*chipselect)(struct spi_device *spi, int is_on);
    void (*set_line_direction)(struct spi_device *spi, bool output);
    u32 (*txrx_word[4])(struct spi_device *spi, unsigned nsecs, u32 word, u8 bits);
    int (*setup_transfer)(struct spi_device *spi, struct spi_transfer *t);
};

struct spi_gpio {
    struct spi_bitbang bitbang;
    void *mosi;
};

struct of_device_id {
    const char *compatible;
    void *data;
};

#define SPI_BPW_RANGE_MASK(min, max) ((~0UL) << (min)) & (~0UL >> (32 - (max)))
#define SPI_MASTER_NO_TX (1 << 0)
#define SPI_MASTER_GPIO_SS (1 << 1)
#define SPI_3WIRE (1 << 2)
#define SPI_3WIRE_HIZ (1 << 3)
#define SPI_CPHA (1 << 4)
#define SPI_CPOL (1 << 5)
#define SPI_CS_HIGH (1 << 6)

enum {
    SPI_MODE_0,
    SPI_MODE_1,
    SPI_MODE_2,
    SPI_MODE_3
};

#define ENOMEM 12

static const struct of_device_id spi_gpio_dt_ids[] = {0};

static inline const struct of_device_id *of_match_device(const struct of_device_id *matches, const struct device *dev) { return NULL; }
static inline struct spi_master *spi_alloc_master(struct device *dev, unsigned size) { return NULL; }
static inline int devm_add_action_or_reset(struct device *dev, void (*action)(void *), void *data) { return 0; }
static inline void *spi_master_get_devdata(struct spi_master *master) { return NULL; }
static inline int spi_bitbang_init(struct spi_bitbang *bb) { return 0; }
static inline int devm_spi_register_master(struct device *dev, struct spi_master *master) { return 0; }
static inline struct spi_master *spi_master_get(struct spi_master *master) { return NULL; }

static inline int spi_gpio_probe_dt(struct platform_device *pdev, struct spi_master *master) { return 0; }
static inline int spi_gpio_probe_pdata(struct platform_device *pdev, struct spi_master *master) { return 0; }
static inline int spi_gpio_request(struct device *dev, struct spi_gpio *spi_gpio) { return 0; }
static inline void spi_gpio_put(void *data) {}
static inline int spi_gpio_setup(struct spi_device *spi) { return 0; }
static inline void spi_gpio_cleanup(struct spi_device *spi) {}
static inline void spi_gpio_chipselect(struct spi_device *spi, int is_on) {}
static inline void spi_gpio_set_direction(struct spi_device *spi, bool output) {}
static inline u32 spi_gpio_spec_txrx_word_mode0(struct spi_device *spi, unsigned nsecs, u32 word, u8 bits) { return 0; }
static inline u32 spi_gpio_spec_txrx_word_mode1(struct spi_device *spi, unsigned nsecs, u32 word, u8 bits) { return 0; }
static inline u32 spi_gpio_spec_txrx_word_mode2(struct spi_device *spi, unsigned nsecs, u32 word, u8 bits) { return 0; }
static inline u32 spi_gpio_spec_txrx_word_mode3(struct spi_device *spi, unsigned nsecs, u32 word, u8 bits) { return 0; }
static inline u32 spi_gpio_txrx_word_mode0(struct spi_device *spi, unsigned nsecs, u32 word, u8 bits) { return 0; }
static inline u32 spi_gpio_txrx_word_mode1(struct spi_device *spi, unsigned nsecs, u32 word, u8 bits) { return 0; }
static inline u32 spi_gpio_txrx_word_mode2(struct spi_device *spi, unsigned nsecs, u32 word, u8 bits) { return 0; }
static inline u32 spi_gpio_txrx_word_mode3(struct spi_device *spi, unsigned nsecs, u32 word, u8 bits) { return 0; }
static inline int spi_bitbang_setup_transfer(struct spi_device *spi, struct spi_transfer *t) { return 0; }