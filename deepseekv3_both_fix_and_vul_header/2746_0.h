#include <stdint.h>

typedef uint64_t pmd_t;
#define _PAGE_PSE (1ULL << 7)
#define _PAGE_PRESENT (1ULL << 0)

static inline unsigned long pmd_flags(pmd_t pmd) {
    return pmd & ((1ULL << 64) - 1);
}