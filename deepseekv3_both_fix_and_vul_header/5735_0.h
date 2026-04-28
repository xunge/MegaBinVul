#include <stdint.h>
#include <stddef.h>

typedef int16_t s16;
typedef uint32_t grant_ref_t;
typedef uint16_t grant_status_t;

#define GNTST_okay 0
#define GNTST_bad_gntref 1
#define GNTST_eagain 2
#define GNTST_general_error 3

#define unlikely(x) (x)
#define PIN_FAIL(label, err, fmt, ...) do { rc = err; goto label; } while (0)

struct spinlock {
    int lock;
};

struct active_grant_entry {
    int pin;
};

typedef struct {
    int dummy;
} grant_entry_v1_t;

typedef struct {
    int dummy;
} grant_entry_v2_t;

struct grant_table {
    int gt_version;
    struct spinlock lock;
    grant_entry_v1_t *shared_v1;
    grant_entry_v2_t *shared_v2;
    grant_status_t *status;
    struct active_grant_entry *active;
    unsigned int nr_grant_entries;
};

struct domain {
    struct grant_table *grant_table;
};

static inline struct domain *rcu_lock_current_domain(void) { return NULL; }
static inline void rcu_unlock_domain(struct domain *d) {}
static inline unsigned int nr_grant_entries(struct grant_table *gt) { return gt->nr_grant_entries; }
static inline struct active_grant_entry *active_entry_ptr(struct grant_table *gt, grant_ref_t ref) { return gt->active + ref; }
static inline grant_entry_v1_t *shared_entry_v1_ptr(struct grant_table *gt, grant_ref_t ref) { return gt->shared_v1 + ref; }
static inline grant_entry_v2_t *shared_entry_v2_ptr(struct grant_table *gt, grant_ref_t ref) { return gt->shared_v2 + ref; }
static inline grant_status_t *status_entry_ptr(struct grant_table *gt, grant_ref_t ref) { return gt->status + ref; }
static inline void spin_lock(struct spinlock *lock) { lock->lock = 1; }
static inline void spin_unlock(struct spinlock *lock) { lock->lock = 0; }

#define active_entry(gt, ref) (*active_entry_ptr(gt, ref))
#define shared_entry_v1(gt, ref) (*shared_entry_v1_ptr(gt, ref))
#define shared_entry_v2(gt, ref) (*shared_entry_v2_ptr(gt, ref))
#define status_entry(gt, ref) (*status_entry_ptr(gt, ref))