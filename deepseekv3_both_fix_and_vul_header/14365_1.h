#include <stdatomic.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef _Atomic u32 atomic_t;

#define READ_ONCE(x) (*(volatile typeof(x)*)&(x))
#define cmpxchg(ptr, old, new) __atomic_compare_exchange_n(ptr, &old, new, 0, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#define prandom_u32_max(x) (rand() % (x))
#define atomic_add_return(i, v) __atomic_add_fetch(v, i, __ATOMIC_SEQ_CST)

extern unsigned long jiffies;
extern atomic_t *ip_idents;
extern u32 *ip_tstamps;
extern u32 ip_idents_mask;
#define IP_IDENTS_SZ 1024