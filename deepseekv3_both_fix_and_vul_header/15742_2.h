#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct tasklet_struct {
    // Minimal definition to make it complete
    void *data;
    void (*func)(unsigned long);
    unsigned long data_field;
};

struct work_struct {
    // Minimal definition to make it complete  
    void *data;
};

struct smc_connection;
struct smc_link_group {
    bool is_smcd;
    struct list_head list;
    unsigned int conns_num;
};
struct smc_connection {
    struct smc_link_group *lgr;
    struct tasklet_struct rx_tsklet;
    struct work_struct abort_work;
};

void smc_ism_unset_conn(struct smc_connection *conn);
void smc_cdc_tx_dismiss_slots(struct smc_connection *conn);
void smc_lgr_unregister_conn(struct smc_connection *conn);
void smc_buf_unuse(struct smc_connection *conn, struct smc_link_group *lgr);
void smc_lgr_schedule_free_work(struct smc_link_group *lgr);
struct work_struct *current_work(void);
void cancel_work_sync(struct work_struct *work);
void tasklet_kill(struct tasklet_struct *t);
bool list_empty(const struct list_head *head);