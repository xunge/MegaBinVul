#include <stdint.h>
#include <stddef.h>

typedef uint64_t gfn_t;
typedef uint64_t pfn_t;

struct kvm_memory_slot;

pfn_t gfn_to_pfn_memslot(struct kvm_memory_slot *slot, gfn_t gfn);
int is_error_noslot_pfn(pfn_t pfn);

#define PAGE_SHIFT 12