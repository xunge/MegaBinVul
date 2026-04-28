#include <stdatomic.h>
#include <stdint.h>
#include <stddef.h>

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define unlikely(x) (x)
#define WARN_ON(condition) ((void)(condition))
#define smp_mb__before_atomic() atomic_thread_fence(memory_order_release)
#define smp_mb__after_atomic() atomic_thread_fence(memory_order_acquire)

enum ib_wc_status {
    IB_WC_SUCCESS
};

struct smc_wr_tx_pend_priv;
struct smc_link;
struct sock;

struct smc_cursor {
    uint16_t reserved;
    uint16_t wrap;
    uint32_t count;
};

struct smc_buf_desc {
    uint32_t len;
};

struct smc_connection {
    struct smc_cursor tx_curs_fin;
    struct smc_cursor local_tx_ctrl_fin;
    uint32_t tx_cdc_seq_fin;
    _Atomic int cdc_pend_tx_wr;
    struct {
        int dummy;
    } cdc_pend_tx_wq;
    _Atomic int sndbuf_space;
    struct smc_buf_desc *sndbuf_desc;
};

struct smc_cdc_tx_pend {
    struct smc_connection *conn;
    struct smc_cursor cursor;
    struct smc_cursor p_cursor;
    uint32_t ctrl_seq;
};

struct smc_sock {
    struct sock *sk;
    struct smc_connection conn;
};

static inline int smc_curs_diff(uint32_t len, struct smc_cursor *old, struct smc_cursor *new) { return 0; }
static inline void smc_curs_copy(struct smc_cursor *to, struct smc_cursor *from, struct smc_connection *conn) {}
static inline void bh_lock_sock(struct sock *sk) {}
static inline void bh_unlock_sock(struct sock *sk) {}
static inline void smc_tx_sndbuf_nonfull(struct smc_sock *smc) {}
static inline int wq_has_sleeper(void *wq) { return 0; }
static inline void wake_up(void *wq) {}