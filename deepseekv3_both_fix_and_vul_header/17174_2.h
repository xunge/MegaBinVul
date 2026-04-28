#include <stddef.h>
#include <errno.h>

enum task_disposition {
    TASK_IS_DONE,
    TASK_IS_ABORTED,
    TASK_IS_AT_LU,
    TASK_IS_NOT_AT_LU,
    TASK_ABORT_FAILED
};

#define TMF_RESP_FUNC_COMPLETE 0
#define SAS_HA_FROZEN 0
#define SAS_TASK_NEED_DEV_RESET (1 << 0)

struct list_head {
    struct list_head *next, *prev;
};

typedef int spinlock_t;

struct Scsi_Host {
    void *transportt;
    void *hostdata;
};

struct scsi_cmnd {
    struct list_head eh_entry;
    struct {
        void *ptr;
    } SCp;
    struct {
        unsigned long lun;
        struct {
            void *hostdata;
        } *host;
    } *device;
};

struct sas_internal {
    struct {
        int (*lldd_clear_nexus_port)(void *);
        int (*lldd_clear_nexus_ha)(void *);
    } *dft;
};

struct sas_ha_struct {
    struct list_head eh_ata_q;
};

struct domain_device {
    spinlock_t done_lock;
    struct asd_sas_port *port;
    unsigned long sas_addr;
};

struct sas_task {
    spinlock_t task_state_lock;
    unsigned int task_state_flags;
    struct domain_device *dev;
};

struct asd_sas_port {
    int id;
};

#define SHOST_TO_SAS_HA(shost) ((struct sas_ha_struct *)(shost)->hostdata)
#define SAS_ADDR(dev) ((dev)->sas_addr)
#define TO_SAS_TASK(cmd) ((struct sas_task *)(cmd)->SCp.ptr)
#define cmd_to_domain_dev(cmd) ((struct domain_device *)(cmd)->device->host->hostdata)
#define LIST_HEAD(name) struct list_head name = { &(name), &(name) }

static inline void spin_lock_irqsave(spinlock_t *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags) {}

static inline void list_move_tail(struct list_head *entry, struct list_head *head) {}
static inline void list_del_init(struct list_head *entry) {}
static inline void list_splice_tail(struct list_head *list, struct list_head *head) {}
static inline void list_splice_tail_init(struct list_head *list, struct list_head *head) {}

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (void *)(head); pos = n)

static struct sas_internal *to_sas_internal(void *transportt) { return NULL; }
static int sas_scsi_find_task(struct sas_task *task) { return 0; }
static int sas_recover_lu(struct domain_device *dev, struct scsi_cmnd *cmd) { return 0; }
static int sas_recover_I_T(struct domain_device *dev) { return 0; }
static void sas_eh_defer_cmd(struct scsi_cmnd *cmd) {}
static void sas_scsi_clear_queue_lu(struct list_head *work_q, struct scsi_cmnd *cmd) {}
static void sas_eh_finish_cmd(struct scsi_cmnd *cmd) {}
static void sas_scsi_clear_queue_I_T(struct list_head *work_q, struct domain_device *dev) {}
static void try_to_reset_cmd_device(struct scsi_cmnd *cmd) {}
static void sas_scsi_clear_queue_port(struct list_head *work_q, struct asd_sas_port *port) {}

#define SAS_DPRINTK(fmt, ...)