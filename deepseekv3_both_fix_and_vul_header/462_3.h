#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define CQSPI_MAX_CHIPSELECT 4
#define GFP_KERNEL 0
#define ENOMEM 12
#define SPI_NOR_QUAD 0

typedef uint8_t u8;
typedef unsigned char u_char;
typedef off_t loff_t;

struct device_node;
struct device {
    struct device_node *of_node;
};
struct platform_device {
    struct device dev;
};
struct mtd_info {
    void *priv;
    const char *name;
};
enum spi_nor_ops {
    SPI_NOR_OPS_READ = 0,
    SPI_NOR_OPS_WRITE,
    SPI_NOR_OPS_ERASE
};
struct spi_nor {
    struct mtd_info mtd;
    struct device *dev;
    void *priv;
    int (*read_reg)(struct spi_nor *, u8, u8 *, size_t);
    int (*write_reg)(struct spi_nor *, u8, const u8 *, size_t);
    ssize_t (*read)(struct spi_nor *, loff_t, size_t, u_char *);
    ssize_t (*write)(struct spi_nor *, loff_t, size_t, const u_char *);
    int (*erase)(struct spi_nor *, loff_t);
    int (*prepare)(struct spi_nor *, enum spi_nor_ops);
    void (*unprepare)(struct spi_nor *, enum spi_nor_ops);
};
struct cqspi_st {
    struct platform_device *pdev;
    struct cqspi_flash_pdata *f_pdata;
};
struct cqspi_flash_pdata {
    struct cqspi_st *cqspi;
    unsigned int cs;
    struct spi_nor nor;
    bool registered;
};

int of_property_read_u32(const struct device_node *, const char *, unsigned int *);
void dev_err(const struct device *, const char *, ...);
char *devm_kasprintf(struct device *, unsigned int, const char *, ...);
const char *dev_name(const struct device *);
int spi_nor_scan(struct spi_nor *, const char *, int);
int mtd_device_register(struct mtd_info *, const char * const *, int);
int mtd_device_unregister(struct mtd_info *);
void spi_nor_set_flash_node(struct spi_nor *, struct device_node *);
#define for_each_available_child_of_node(parent, child) \
    for ((child) = NULL; (child) != NULL; (child) = NULL)

int cqspi_of_get_flash_pdata(struct platform_device *, struct cqspi_flash_pdata *, struct device_node *);
int cqspi_read_reg(struct spi_nor *, u8, u8 *, size_t);
int cqspi_write_reg(struct spi_nor *, u8, const u8 *, size_t);
ssize_t cqspi_read(struct spi_nor *, loff_t, size_t, u_char *);
ssize_t cqspi_write(struct spi_nor *, loff_t, size_t, const u_char *);
int cqspi_erase(struct spi_nor *, loff_t);
int cqspi_prep(struct spi_nor *, enum spi_nor_ops);
void cqspi_unprep(struct spi_nor *, enum spi_nor_ops);