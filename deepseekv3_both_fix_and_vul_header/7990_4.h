#include <stdint.h>

struct mm_struct;
typedef uint64_t pte_t;

#define pte_valid_ng(pte) ((pte) & 0x1)
#define pte_special(pte) ((pte) & 0x2)
#define pte_exec(pte) ((pte) & 0x4)
#define pte_dirty(pte) ((pte) & 0x8)
#define pte_write(pte) ((pte) & 0x10)
#define PTE_RDONLY 0x20

static inline void __sync_icache_dcache(pte_t pte, unsigned long addr) {}
static inline void set_pte(pte_t *ptep, pte_t pte) { *ptep = pte; }
#define pte_val(pte) (pte)