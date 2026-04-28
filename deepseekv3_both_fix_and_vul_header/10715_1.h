#include <stdint.h>

typedef struct tor_addr_t tor_addr_t;
typedef uint8_t maskbits_t;

#define CMP_SEMANTIC 0

static inline int tor_addr_compare_masked(const tor_addr_t *a1, const tor_addr_t *a2,
                                        maskbits_t m, int how)
{
    return 0;
}