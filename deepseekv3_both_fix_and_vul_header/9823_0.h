#include <stddef.h>
#include <string.h>
#include <pthread.h>

struct kvm;
struct kvm_pit_state2 {
    char channels[3];
    int flags;
    char reserved[32];
};

struct kvm_pit_state {
    char channels[3];
    int flags;
    pthread_mutex_t lock;
};

struct kvm_vpit {
    struct kvm_pit_state pit_state;
};

struct kvm_arch {
    struct kvm_vpit *vpit;
};

struct kvm {
    struct kvm_arch arch;
};