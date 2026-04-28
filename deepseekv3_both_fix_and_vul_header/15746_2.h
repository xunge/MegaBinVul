#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef uint32_t u32;

struct ib_wc {
    uint64_t wr_id;
    int status;
    int opcode;
    struct {
        void *qp_context;
    } *qp;
};

enum wr_reg_state {
    FAILED,
    CONFIRMED
};

struct smc_link;

struct smc_wr_tx_pend {
    void *priv;
    bool compl_requested;
    u32 wc_status;
    void (*handler)(void *, struct smc_link *, u32);
};

struct smc_link {
    void *qp_context;
    enum wr_reg_state wr_reg_state;
    u32 wr_tx_cnt;
    struct smc_wr_tx_pend *wr_tx_pends;
    void *wr_tx_bufs;
    unsigned long *wr_tx_mask;
    void *wr_tx_wait;
    void *wr_tx_compl;
};

#define IB_WC_REG_MR 0

static inline u32 smc_wr_tx_find_pending_index(struct smc_link *link, uint64_t wr_id) { return 0; }
static inline void smc_wr_wakeup_reg_wait(struct smc_link *link) {}
static inline void smcr_link_down_cond_sched(struct smc_link *link) {}
static inline void complete(void *c) {}
static inline void wake_up(void *w) {}

static inline bool test_and_clear_bit(int nr, volatile unsigned long *addr) {
    bool ret = (*addr & (1UL << nr)) != 0;
    *addr &= ~(1UL << nr);
    return ret;
}

static inline void clear_bit(int nr, volatile unsigned long *addr) {
    *addr &= ~(1UL << nr);
}

#define for_each_set_bit(bit, addr, size) \
    for ((bit) = 0; (bit) < (size); (bit)++) \
        if ((addr)[(bit) / (8 * sizeof(long))] & (1UL << ((bit) % (8 * sizeof(long)))))