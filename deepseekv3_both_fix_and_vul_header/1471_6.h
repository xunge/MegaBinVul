#include <stdbool.h>
#include <stddef.h>

#define KVM_VCPU_PREEMPTED 1
#define KVM_MSR_ENABLED 1
#define unlikely(x) (x)
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define __user

typedef unsigned long gpa_t;
typedef unsigned long gfn_t;
typedef unsigned char u8;
typedef unsigned long long u64;

struct mm_struct;
struct kvm_memory_slot;

struct kvm_steal_time {
    u8 preempted;
};

struct gfn_to_hva_cache {
    u64 generation;
    unsigned long hva;
    struct kvm_memory_slot *memslot;
    gpa_t gpa;
};

struct kvm_memslots {
    u64 generation;
};

struct kvm {
    struct mm_struct *mm;
};

struct kvm_vcpu {
    struct {
        struct {
            struct gfn_to_hva_cache cache;
            u64 msr_val;
            bool preempted;
        } st;
        bool at_instruction_boundary;
    } arch;
    struct kvm *kvm;
    struct {
        int preemption_other;
        int preemption_reported;
    } stat;
};

struct task_struct {
    struct mm_struct *mm;
};
extern struct task_struct *current;

struct kvm_memslots *kvm_memslots(struct kvm *kvm);
bool kvm_is_error_hva(unsigned long hva);
void mark_page_dirty_in_slot(struct kvm *kvm, struct kvm_memory_slot *memslot, gfn_t gfn);
int copy_to_user_nofault(void *to, const void *from, unsigned long n);
gfn_t gpa_to_gfn(gpa_t gpa);