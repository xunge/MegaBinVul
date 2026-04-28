#include <stdbool.h>

#define SMC_LNK_UNUSED 0
#define SMC_LGR_SINGLE 0
#define SMC_SERV 0
#define SMC_LLC_FLOW_NONE 0
#define SMC_LLC_REQ 0
#define SMC_LLC_DEL_LOST_PATH 0
#define SMC_LLC_WAIT_TIME 0

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

typedef struct {
    int dummy;
} wait_queue_head_t;

struct smc_link {
    int state;
    int link_id;
    struct smc_link_group *lgr;
};

struct smc_link_group {
    struct list_head list;
    int role;
    int type;
    struct mutex llc_conf_mutex;
    wait_queue_head_t llc_flow_waiter;
    struct {
        int type;
    } llc_flow_lcl;
};

void smc_ib_modify_qp_reset(struct smc_link *lnk);
struct smc_link *smc_switch_conns(struct smc_link_group *lgr, struct smc_link *lnk, bool flag);
void smcr_link_clear(struct smc_link *lnk, bool flag);
void smcr_lgr_set_type(struct smc_link_group *lgr, int type);
void smc_llc_srv_delete_link_local(struct smc_link *lnk, int id);
void smc_llc_send_delete_link(struct smc_link *lnk, int id, int req, bool flag, int path);

static inline bool list_empty(const struct list_head *head) {
    return head->next == head;
}

static inline void mutex_lock(struct mutex *lock) {
    (void)lock;
}

static inline void mutex_unlock(struct mutex *lock) {
    (void)lock;
}

static inline void wake_up(wait_queue_head_t *wq_head) {
    (void)wq_head;
}

static inline void wait_event_timeout(wait_queue_head_t wq_head,
                                    bool condition,
                                    unsigned long timeout) {
    (void)wq_head;
    (void)condition;
    (void)timeout;
}