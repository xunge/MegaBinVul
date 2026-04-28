#include <stdint.h>

typedef struct {
    uint64_t pmd;
} pmd_t;

#define pmd_read_atomic(pmd) (*pmd)
#define pmd_none(pmdval) ((pmdval).pmd == 0)
#define pmd_bad(pmdval) (0)
#define pmd_trans_huge(pmdval) (0)
#define pmd_clear_bad(pmd) do { } while (0)
#define barrier() __asm__ __volatile__("": : :"memory")
#define unlikely(x) (x)