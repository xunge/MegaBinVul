#include <stdatomic.h>
#include <stdint.h>

typedef uint16_t __u16;

struct inet_peer {
    _Atomic unsigned int ip_id_count;
};

static inline unsigned int atomic_add_return(int val, _Atomic unsigned int *ptr) {
    return atomic_fetch_add(ptr, val) + val;
}

static inline void inet_peer_refcheck(struct inet_peer *p) {
    (void)p;
}