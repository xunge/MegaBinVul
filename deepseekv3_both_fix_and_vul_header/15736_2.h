#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef uint64_t u64;

#define IDXD_INTC_ERR 0
#define IDXD_INTC_CMD 0
#define IDXD_INTC_OCCUPY 0
#define IDXD_INTC_PERFMON_OVFL 0
#define IDXD_SWERR_OFFSET 0
#define IDXD_SWERR_ACK 0
#define IDXD_GENSTATS_OFFSET 0
#define IDXD_DEVICE_STATE_HALT 0
#define IDXD_DEVICE_RESET_SOFTWARE 0
#define IDXD_DEVICE_RESET_FLR 0
#define IDXD_WQT_USER 0
#define ENXIO 0

struct wait_queue_head {
    int dummy;
};

struct work_struct {
    int dummy;
};

struct completion {
    int dummy;
};

struct device {
    int dummy;
};

struct pci_dev {
    struct device dev;
};

union gensts_reg {
    u32 bits;
    struct {
        u32 state:3;
        u32 reset_type:2;
    };
};

struct idxd_sw_err {
    u64 bits[4];
    bool valid;
    bool wq_idx_valid;
    bool desc_valid;
    int wq_idx;
    u64 fault_addr;
};

struct idxd_cdev {
    struct wait_queue_head err_queue;
};

struct idxd_wq {
    int type;
    struct idxd_cdev idxd_cdev;
};

enum idxd_dev_state {
    IDXD_DEV_HALTED
};

struct idxd_device {
    struct device *dev;
    struct pci_dev *pdev;
    void *dev_lock;
    void *reg_base;
    struct idxd_sw_err sw_err;
    struct idxd_wq *wqs;
    int max_wqs;
    enum idxd_dev_state state;
    struct completion *cmd_done;
    struct work_struct work;
    struct workqueue_struct *wq;
};

static inline void spin_lock_bh(void *lock) {}
static inline void spin_unlock_bh(void *lock) {}
static inline u64 ioread64(void *addr) { return 0; }
static inline void iowrite64(u64 val, void *addr) {}
static inline u32 ioread32(void *addr) { return 0; }
static inline void wake_up_interruptible(struct wait_queue_head *q) {}
static inline void complete(struct completion *c) {}
static inline void INIT_WORK(struct work_struct *work, void *func) {}
static inline void queue_work(struct workqueue_struct *wq, struct work_struct *work) {}
static inline void dev_warn(struct device *dev, const char *fmt, ...) {}
static inline void dev_warn_once(struct device *dev, const char *fmt, ...) {}
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline void idxd_device_schedule_fault_process(struct idxd_device *idxd, u64 addr) {}
static inline void idxd_device_reinit(struct work_struct *work) {}
static inline void idxd_device_wqs_clear_state(struct idxd_device *idxd) {}