#include <stdatomic.h>
#include <stdbool.h>

#define WARN_ON(condition) ((condition) ? true : false)

static inline int atomic_read(atomic_int *obj) {
    return atomic_load(obj);
}

static inline void atomic_set(atomic_int *obj, int desired) {
    atomic_store(obj, desired);
}

struct kvm_memory_slot {
    int id;
};

struct kvm_memslots {
    struct kvm_memory_slot *memslots;
    int *id_to_index;
    int used_slots;
    atomic_int lru_slot;
};