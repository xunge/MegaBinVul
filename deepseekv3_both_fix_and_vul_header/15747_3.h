#include <stdatomic.h>
#include <stdint.h>

struct smc_wr_buf;
struct smc_cdc_tx_pend;
struct smc_link;
struct smc_wr_tx_pend_priv;

typedef union smc_host_cursor {
    uint64_t reserved;
    struct {
        uint32_t wrap;
        uint32_t count;
    };
} smc_host_cursor;

struct smc_cdc_producer_flags {
    uint8_t cons_curs_upd_req;
    uint8_t peer_conn_abort;
    uint8_t peer_conn_closed;
    uint8_t reserved;
};

struct smc_cdc_conn_state_flags {
    uint8_t peer_conn_abort;
    uint8_t peer_conn_closed;
    uint8_t reserved[2];
};

struct smc_cdc_msg {
    smc_host_cursor prod;
    smc_host_cursor cons;
    uint32_t len;
    uint32_t reserved;
    struct smc_cdc_producer_flags prod_flags;
    struct smc_cdc_conn_state_flags conn_state_flags;
    uint32_t seqno;
};

struct smc_connection {
    struct smc_link *lnk;
    uint32_t tx_cdc_seq;
    struct smc_cdc_msg local_tx_ctrl;
    smc_host_cursor rx_curs_confirmed;
    struct smc_cdc_msg local_rx_ctrl;
    atomic_int cdc_pend_tx_wr;
};

void smc_cdc_add_pending_send(struct smc_connection *conn, struct smc_cdc_tx_pend *pend);
void smc_host_msg_to_cdc(struct smc_cdc_msg *msg, struct smc_connection *conn, smc_host_cursor *cfed);
int smc_wr_tx_send(struct smc_link *link, struct smc_wr_tx_pend_priv *pend);
void smc_curs_copy(smc_host_cursor *dst, smc_host_cursor *src, struct smc_connection *conn);