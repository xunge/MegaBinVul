#include <stdatomic.h>
#include <arpa/inet.h>

struct smc_host_cdc_msg {
    struct {
        int type;
    } common;
    int len;
    unsigned int token;
};

struct smc_cdc_msg {
    struct {
        int type;
    } common;
    int len;
    unsigned short seqno;
    unsigned int token;
    struct {
        int failover_validation;
    } prod_flags;
};

struct smc_connection {
    struct smc_host_cdc_msg local_tx_ctrl;
    struct smc_link *lnk;
    unsigned int tx_cdc_seq_fin;
    atomic_int cdc_pend_tx_wr;
};

struct smc_link;
struct smc_cdc_tx_pend;
struct smc_wr_buf;
struct smc_wr_tx_pend_priv;

#define unlikely(x) __builtin_expect(!!(x), 0)
#define smp_mb__after_atomic() atomic_thread_fence(memory_order_seq_cst)

void smc_cdc_add_pending_send(struct smc_connection *conn, struct smc_cdc_tx_pend *pend);
int smc_wr_tx_send(struct smc_link *link, struct smc_wr_tx_pend_priv *pend);