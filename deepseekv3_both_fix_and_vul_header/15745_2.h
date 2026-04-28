#include <stdatomic.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>

struct ib_device;
struct smc_ib_device {
    struct ib_device *ibdev;
};

struct smc_link {
    struct smc_ib_device *smcibdev;
    atomic_int wr_reg_refcnt;
    atomic_int wr_tx_refcnt;
    unsigned long *wr_tx_mask;
    uintptr_t wr_rx_dma_addr;
    uintptr_t wr_tx_dma_addr;
    int wr_rx_cnt;
    int wr_tx_cnt;
    int wr_reg_wait;
    int wr_tx_wait;
};

#define SMC_WR_BUF_CNT 16
#define SMC_WR_BUF_SIZE 4096
#define BITS_TO_LONGS(n) (((n) + 8 * sizeof(long) - 1) / (8 * sizeof(long)))
#define DMA_FROM_DEVICE 1
#define DMA_TO_DEVICE 2

static inline int atomic_read(atomic_int *v) {
    return atomic_load(v);
}

void wait_event(int wait, int condition);
void smc_wr_wakeup_reg_wait(struct smc_link *lnk);
void smc_wr_wakeup_tx_wait(struct smc_link *lnk);
int smc_wr_tx_wait_no_pending_sends(struct smc_link *lnk);
void ib_dma_unmap_single(struct ib_device *ibdev, uintptr_t dma_addr, size_t size, int direction);