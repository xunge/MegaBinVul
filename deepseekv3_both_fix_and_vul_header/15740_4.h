#include <stdbool.h>
#include <stddef.h>

typedef int spinlock_t;

enum smc_lgr_role {
    SMC_CLNT,
    SMC_SERV
};

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (void*)((char*)(head)->next - offsetof(typeof(*(pos)), member)); \
         &pos->member != (head); \
         pos = (void*)((char*)pos->member.next - offsetof(typeof(*(pos)), member)))

struct delayed_work {
    int dummy;
};

struct work_struct {
    int dummy;
};

struct ism_dev {
    struct list_head lgr_list;
    spinlock_t lgr_lock;
};

struct smc_link_group {
    struct list_head list;
    spinlock_t conns_lock;
    int conns_num;
    int vlan_id;
    bool sync_err;
    struct delayed_work free_work;
};

struct smc_connection {
    struct smc_link_group *lgr;
    struct {
        struct {
            int type;
        } common;
        int len;
    } local_tx_ctrl;
    int urg_state;
    int cdc_pend_tx_wq;
    int rx_off;
#ifndef KERNEL_HAS_ATOMIC64
    spinlock_t acurs_lock;
#endif
    struct work_struct abort_work;
};

struct smc_sock {
    struct smc_connection conn;
    bool listen_smc;
};

struct smc_init_info {
    bool is_smcd;
    int ism_selected;
    struct ism_dev **ism_dev;
    unsigned int *ism_peer_gid;
    bool first_contact_local;
    bool first_contact_peer;
    int smcd_version;
    int vlan_id;
    void *ib_lcl;
    int ib_clcqpn;
};

struct smcd_cdc_msg {
    int type;
};

#define SMC_V2 2
#define SMC_RMBS_PER_LGR_MAX 255
#define SMC_CDC_MSG_TYPE 1
#define SMC_WR_TX_SIZE 1024
#define SMC_URG_READ 1
#define SMC_CLC_DECL_SYNCERR -1

extern struct {
    struct list_head list;
    spinlock_t lock;
} smc_lgr_list;

extern int smc_lgr_register_conn(struct smc_connection *conn, bool is_new);
extern int smc_lgr_create(struct smc_sock *smc, struct smc_init_info *ini);
extern bool smcd_lgr_match(struct smc_link_group *lgr, struct ism_dev *ism_dev, unsigned int peer_gid);
extern bool smcr_lgr_match(struct smc_link_group *lgr, void *ib_lcl, enum smc_lgr_role role, int qpn);
extern void smcd_cdc_rx_init(struct smc_connection *conn);
extern void smc_conn_abort_work(struct work_struct *work);

static inline void spin_lock_bh(spinlock_t *lock) {}
static inline void spin_unlock_bh(spinlock_t *lock) {}
static inline void write_lock_bh(spinlock_t *lock) {}
static inline void write_unlock_bh(spinlock_t *lock) {}
static inline bool delayed_work_pending(struct delayed_work *work) { return false; }
static inline void cancel_delayed_work(struct delayed_work *work) {}
static inline void init_waitqueue_head(int *wq) {}
static inline void INIT_WORK(struct work_struct *work, void (*func)(struct work_struct *)) {}
static inline void spin_lock_init(spinlock_t *lock) {}