#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint64_t atomic64_t;

#define KVM_S390_MAX_BIT_DISTANCE 64
#define unlikely(x) (x)

struct kvm_memory_slot {
    unsigned long base_gfn;
    unsigned long npages;
    unsigned long *dirty_bitmap;
};

struct kvm_memslots {
    int used_slots;
    struct kvm_memory_slot memslots[];
};

struct kvm_s390_cmma_log {
    unsigned long start_gfn;
    unsigned long count;
};

struct kvm {
    struct mm_struct *mm;
    struct {
        atomic64_t cmma_dirty_pages;
    } arch;
};

struct mm_struct;

static inline void atomic64_dec(atomic64_t *v) { (*v)--; }
static inline bool test_and_clear_bit(long nr, volatile unsigned long *addr) { return false; }

static unsigned long kvm_s390_next_dirty_cmma(struct kvm_memslots *slots, unsigned long gfn);
static struct kvm_memory_slot *gfn_to_memslot(struct kvm *kvm, unsigned long gfn);
static unsigned long gfn_to_hva(struct kvm *kvm, unsigned long gfn);
static bool kvm_is_error_hva(unsigned long hva);
static unsigned long *kvm_second_dirty_bitmap(struct kvm_memory_slot *ms);
static int get_pgste(struct mm_struct *mm, unsigned long hva, unsigned long *pgstev);
static struct kvm_memslots *kvm_memslots(struct kvm *kvm);