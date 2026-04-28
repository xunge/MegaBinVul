#include <stddef.h>
#include <errno.h>
#include <stdbool.h>

struct smc_connection;
struct smc_sock;
struct smc_lgr;

struct smc_connection {
    struct smc_lgr *lgr;
    struct {
        struct {
            int peer_conn_abort;
        } conn_state_flags;
    } local_tx_ctrl;
    int killed;
    void *rx_tsklet;
};

struct smc_sock {
    struct smc_connection conn;
    struct {
        int sk_err;
    } sk;
};

struct smc_lgr {
    bool is_smcd;
    bool peer_shutdown;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))