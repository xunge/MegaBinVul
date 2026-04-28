#include <stddef.h>

struct vcpu_hvm {
    int tm_lock;
};

struct vcpu_arch {
    struct vcpu_hvm hvm;
};

struct vcpu {
    struct vcpu_arch arch;
};

struct periodic_time {
    struct vcpu *vcpu;
};

static inline void spin_unlock(int *lock) {}