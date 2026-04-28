#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define coroutine_fn

typedef struct MirrorOp MirrorOp;
typedef struct MirrorBlockJob MirrorBlockJob;

struct MirrorOp {
    uint64_t offset;
    uint64_t bytes;
    bool is_waiting;
    MirrorOp *waiting_for_op;
    MirrorOp *next;
    void *waiting_requests;
};

struct MirrorBlockJob {
    unsigned long *in_flight_bitmap;
    uint64_t granularity;
    int ret;
    MirrorOp *ops_in_flight;
};

static inline bool ranges_overlap(uint64_t first1, uint64_t len1,
                                 uint64_t first2, uint64_t len2)
{
    uint64_t last1 = first1 + len1 - 1;
    uint64_t last2 = first2 + len2 - 1;
    return !(last2 < first1 || last1 < first2);
}

static inline unsigned long find_next_bit(const unsigned long *addr,
                                         unsigned long size,
                                         unsigned long offset)
{
    for (; offset < size; offset++) {
        if (addr[offset / (sizeof(*addr) * 8)] & (1UL << (offset % (sizeof(*addr) * 8)))) {
            return offset;
        }
    }
    return size;
}

static void qemu_co_queue_wait(void *queue, void *lock) {
    (void)queue;
    (void)lock;
}

#define QTAILQ_FOREACH(op, head, field) \
    for ((op) = *(head); (op) != NULL; (op) = (op)->next)