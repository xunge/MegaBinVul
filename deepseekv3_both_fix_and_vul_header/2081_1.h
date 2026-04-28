#include <stddef.h>
#include <stdbool.h>

#define unlikely(x) __builtin_expect(!!(x), 0)

typedef struct { unsigned long pmd; } pmd_t;

static inline pmd_t pmd_read_atomic(pmd_t *pmd) { return *pmd; }
static inline int pmd_none(pmd_t pmd) { return pmd.pmd == 0; }
static inline int pmd_bad(pmd_t pmd) { return (pmd.pmd & 2) != 0; }
static inline int pmd_trans_huge(pmd_t pmd) { return (pmd.pmd & 4) != 0; }
static inline void pmd_clear_bad(pmd_t *pmd) { pmd->pmd &= ~2UL; }
static inline void barrier() { asm volatile("" ::: "memory"); }