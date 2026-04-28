#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint64_t u64;
typedef uint32_t u32;

#define RINGBUF_MAX_RECORD_SZ (1 << 24)
#define BPF_RINGBUF_HDR_SZ 8
#define BPF_RINGBUF_BUSY_BIT (1U << 31)

struct bpf_ringbuf_hdr {
    u32 len;
    u32 pg_off;
};

struct bpf_ringbuf {
    u64 mask;
    u64 consumer_pos;
    u64 producer_pos;
    void *data;
    unsigned long spinlock;
};

#define unlikely(x) __builtin_expect(!!(x), 0)
#define smp_load_acquire(p) (*(p))
#define smp_store_release(p, v) (*(p) = (v))

static inline bool in_nmi(void) { return false; }
static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) { (void)lock; (void)flags; }
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) { (void)lock; (void)flags; }
static inline bool spin_trylock_irqsave(unsigned long *lock, unsigned long flags) { (void)lock; (void)flags; return true; }

static inline u32 round_up(u32 x, u32 y) { return ((x + y - 1) / y) * y; }
static inline u32 bpf_ringbuf_rec_pg_off(struct bpf_ringbuf *rb, struct bpf_ringbuf_hdr *hdr) { (void)rb; (void)hdr; return 0; }