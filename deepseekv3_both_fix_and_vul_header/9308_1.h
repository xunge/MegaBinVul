#include <string.h>
#include <stddef.h>
#include <pthread.h>

struct kvm;
struct kvm_pit_state;

struct kvm_pit_channel {
    int count;
};

struct kvm_pit_state {
    struct kvm_pit_channel channels[3];
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

void kvm_pit_load_count(struct kvm *kvm, int channel, int count, int is_oneshot);