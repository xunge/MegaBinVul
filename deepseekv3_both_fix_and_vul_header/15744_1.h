#include <stdbool.h>
#include <linux/errno.h>

struct smc_link {
    int wr_tx_wait;
};

#define SMC_WR_TX_WAIT_PENDING_TIME 0

static inline bool smc_wr_is_tx_pend(struct smc_link *link)
{
    return false;
}