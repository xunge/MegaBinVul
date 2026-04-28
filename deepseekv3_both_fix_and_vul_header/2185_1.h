#include <stddef.h>
#include <stdio.h>

#define EFX_DEFAULT_DMAQ_SIZE 0
#define EFX_RXQ_MIN_ENT 0
#define EFX_TXQ_MIN_ENT(x) 0
#define EINVAL 22

struct efx_nic {
    void *net_dev;
    unsigned int rxq_entries;
    unsigned int txq_entries;
};

#define netif_err(efx, type, net_dev, fmt, ...) \
    fprintf(stderr, fmt, ##__VA_ARGS__)

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define WARN_ON(condition) (condition)