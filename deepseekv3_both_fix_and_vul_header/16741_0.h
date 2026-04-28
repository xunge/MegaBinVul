#include <stdatomic.h>
#include <stddef.h>

typedef unsigned long gfn_t;

struct kvm_memory_slot {
    gfn_t base_gfn;
    unsigned long npages;
};

struct kvm_memslots {
    struct kvm_memory_slot *memslots;
    int used_slots;
    atomic_int lru_slot;
};