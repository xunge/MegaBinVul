#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;

#define NSEC_PER_SEC 1000000000L
#define PAGE_SHIFT 12
#define KVM_REQ_CLOCK_UPDATE 8
#define PVCLOCK_GUEST_STOPPED 1
#define PVCLOCK_TSC_STABLE_BIT 2
#define unlikely(x) (x)

struct kvm_vcpu;
struct kvm;
struct kvm_x86_ops {
    u64 (*read_l1_tsc)(struct kvm_vcpu *v, u64 host_tsc);
};

struct pvclock_vcpu_time_info {
    u64 tsc_timestamp;
    u64 system_time;
    u32 tsc_shift;
    u32 tsc_to_system_mul;
    u8 flags;
    u32 version;
};

struct kvm_arch {
    bool use_master_clock;
    u64 master_cycle_now;
    s64 master_kernel_ns;
    s64 kvmclock_offset;
    int pvclock_gtod_sync_lock;
};

struct kvm_vcpu_arch {
    struct pvclock_vcpu_time_info hv_clock;
    bool tsc_catchup;
    bool pv_time_enabled;
    bool pvclock_set_guest_stopped_request;
    u64 last_guest_tsc;
    s64 last_kernel_ns;
    u64 hw_tsc_khz;
    void *time_page;
    u64 time_offset;
    void *pv_time;
    u64 time;
};

struct kvm {
    struct kvm_arch arch;
};

struct kvm_vcpu {
    struct kvm_vcpu_arch arch;
    struct kvm *kvm;
};

extern struct kvm_x86_ops *kvm_x86_ops;
extern unsigned long __get_cpu_var(unsigned long);
extern unsigned long cpu_tsc_khz;

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void local_irq_save(unsigned long flags) {}
static inline void local_irq_restore(unsigned long flags) {}
static inline u64 native_read_tsc(void) { return 0; }
static inline s64 get_kernel_ns(void) { return 0; }
static inline u64 compute_guest_tsc(struct kvm_vcpu *v, s64 kernel_ns) { return 0; }
static inline void adjust_tsc_offset_guest(struct kvm_vcpu *v, u64 offset) {}
static inline void kvm_get_time_scale(u64 scale, u64 tsc_khz, u32 *tsc_shift, u32 *tsc_mul) {}
static inline int kvm_read_guest_cached(struct kvm *kvm, void *data, void *dst, size_t len) { return 0; }
static inline int kvm_write_guest_cached(struct kvm *kvm, void *data, void *src, size_t len) { return 0; }
static inline void kvm_make_request(int req, struct kvm_vcpu *v) {}
static inline void mark_page_dirty(struct kvm *kvm, u64 gfn) {}
static inline void *kmap_atomic(void *page) { return 0; }
static inline void kunmap_atomic(void *addr) {}
static inline u64 pvclock_scale_delta(u64 delta, u32 mul, int32_t shift) { return delta * mul >> shift; }