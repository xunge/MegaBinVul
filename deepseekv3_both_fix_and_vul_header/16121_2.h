#include <stddef.h>

typedef struct spinlock { int lock; } spinlock_t;
typedef struct rwlock { int lock; } rwlock_t;

struct pl_time {
    rwlock_t pt_migrate;
};

struct hvm {
    spinlock_t tm_lock;
    struct pl_time *pl_time;
};

struct arch {
    struct hvm hvm;
};

struct domain {
    struct arch arch;
};

struct vcpu {
    struct domain *domain;
    struct arch arch;
};

struct periodic_time {
    struct vcpu *vcpu;
};

static inline void read_lock(rwlock_t *lock) { (void)lock; }
static inline void spin_lock(spinlock_t *lock) { (void)lock; }