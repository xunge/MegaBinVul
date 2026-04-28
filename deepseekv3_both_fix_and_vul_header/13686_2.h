#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct device {
    void *platform_data;
};

struct spi_device {
    struct device dev;
};

struct completion {
    unsigned int done;
};

struct ieee802154_hw {
    void *priv;
    struct device *parent;
    struct {
        struct {
            unsigned char perm_extended_addr[8];
        } *phy;
    };
};

struct ca8210_priv {
    struct ieee802154_hw *hw;
    struct spi_device *spi;
    int lock;
    bool async_tx_pending;
    bool hw_registered;
    int sync_up;
    int sync_down;
    bool promiscuous;
    int retries;
    struct completion ca8210_is_awake;
    struct completion spi_transfer_complete;
    struct completion sync_exchange_complete;
};

struct ca8210_platform_data {
    bool extclockenable;
};

#define GFP_KERNEL 0
#define ENOMEM 12
#define IS_ENABLED(x) 0

static inline void spin_lock_init(int *lock) {}
static inline void init_completion(struct completion *x) { x->done = 0; }
static inline void spi_set_drvdata(struct spi_device *spi, void *data) {}
static inline void msleep(unsigned int msecs) {}
static inline void dev_info(struct device *dev, const char *fmt, ...) {}
static inline void dev_crit(struct device *dev, const char *fmt, ...) {}

extern struct ieee802154_hw *ieee802154_alloc_hw(size_t priv_size, const void *ops);
extern void ieee802154_random_extended_addr(unsigned char *addr);
extern int ieee802154_register_hw(struct ieee802154_hw *hw);
extern void *kmalloc(size_t size, int flags);
extern int (*cascoda_api_upstream)(void);
extern int ca8210_test_int_driver_write(void);
extern void ca8210_test_interface_init(struct ca8210_priv *priv);
extern void ca8210_hw_setup(struct ieee802154_hw *hw);
extern int ca8210_get_platform_data(struct spi_device *spi, struct ca8210_platform_data *pdata);
extern int ca8210_dev_com_init(struct ca8210_priv *priv);
extern int ca8210_reset_init(struct spi_device *spi);
extern int ca8210_interrupt_init(struct spi_device *spi);
extern void ca8210_reset_send(struct spi_device *spi, int reset);
extern int tdme_chipinit(struct spi_device *spi);
extern int ca8210_config_extern_clk(struct ca8210_platform_data *pdata, struct spi_device *spi, int enable);
extern int ca8210_register_ext_clock(struct spi_device *spi);
extern void ca8210_remove(struct spi_device *spi);
extern int link_to_linux_err(int err);

static const void *ca8210_phy_ops;