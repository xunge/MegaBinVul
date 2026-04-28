#include <stdatomic.h>
#include <errno.h>
#include <stddef.h>

struct bpf_stab {
    atomic_flag lock;
};

struct sock;

static void sock_map_unref(struct sock *sk, struct sock **psk);
#define likely(x) (x)
#define raw_spin_lock_bh(lock) atomic_flag_test_and_set(lock)
#define raw_spin_unlock_bh(lock) atomic_flag_clear(lock)
#define EINVAL 22
#define xchg(ptr, val) atomic_exchange(ptr, val)