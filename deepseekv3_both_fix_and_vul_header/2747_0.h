#include <stdint.h>

typedef uint64_t pmd_t;
#define _PAGE_PRESENT  (1ULL << 0)
#define _PAGE_PROTNONE (1ULL << 1)
#define _PAGE_PSE      (1ULL << 2)

static inline uint64_t pmd_flags(pmd_t pmd) {
    return pmd;
}