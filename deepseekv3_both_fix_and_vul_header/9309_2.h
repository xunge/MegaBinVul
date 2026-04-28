#include <stdint.h>
#include <string.h>
#include <pthread.h>

typedef uint32_t u32;

struct kvm_pit_channel {
    int count;
};

struct kvm_pit_state2 {
    u32 flags;
    struct kvm_pit_channel channels[3];
};

struct kvm_pit_state {
    pthread_mutex_t lock;
    u32 flags;
    struct kvm_pit_channel channels[3];
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

#define KVM_PIT_FLAGS_HPET_LEGACY 0x00000001

void kvm_pit_load_count(struct kvm *kvm, int channel, int count, int start);

static inline void mutex_lock(pthread_mutex_t *lock) {
    pthread_mutex_lock(lock);
}

static inline void mutex_unlock(pthread_mutex_t *lock) {
    pthread_mutex_unlock(lock);
}