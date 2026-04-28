#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>

#define KVM_PIT_CHANNEL_MASK 0x3
#define RW_STATE_LSB 0
#define RW_STATE_MSB 1
#define RW_STATE_WORD0 2
#define RW_STATE_WORD1 3
#define EOPNOTSUPP 95

typedef uint64_t gpa_t;

struct kvm_kpit_channel_state {
    int status_latched;
    int status;
    int count_latched;
    int latched_count;
    int read_state;
};

struct kvm_kpit_state {
    struct kvm_kpit_channel_state channels[4];
    pthread_mutex_t lock;
};

struct kvm {
    // dummy definition
};

struct kvm_io_device {
    // dummy definition
};

struct kvm_pit {
    struct kvm_kpit_state pit_state;
    struct kvm *kvm;
};

static inline struct kvm_pit *dev_to_pit(struct kvm_io_device *dev) { return (struct kvm_pit *)dev; }
static int pit_in_range(gpa_t addr) { return addr < 4; }
static int pit_get_count(struct kvm *kvm, gpa_t addr) { return 0; }

#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)