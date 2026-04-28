#include <stdint.h>
#include <errno.h>

typedef uint64_t vaddr_t;
typedef uint64_t paddr_t;

#define PAR_F       (1ULL << 0)
#define PADDR_MASK  0x0000fffffffff000ULL
#define PAGE_MASK   0x0000fffffffff000ULL

uint64_t gva_to_ma_par(vaddr_t va, unsigned int flags);
uint64_t gva_to_ma_par(vaddr_t va);