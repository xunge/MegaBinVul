#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define BLKIF_PROTOCOL_NATIVE 0
#define BLKIF_PROTOCOL_X86_32 1
#define BLKIF_PROTOCOL_X86_64 2

typedef uint64_t u64;

struct blkif_response {
    u64 id;
    unsigned short operation;
    int status;
};

struct xen_blkif {
    int blk_protocol;
};

union blkif_back_rings {
    struct {
        void *rsp_prod_pvt;
    } common;
    struct {
        void *rsp_prod_pvt;
    } native;
    struct {
        void *rsp_prod_pvt;
    } x86_32;
    struct {
        void *rsp_prod_pvt;
    } x86_64;
};

struct xen_blkif_ring {
    struct xen_blkif *blkif;
    union blkif_back_rings blk_rings;
    unsigned long blk_ring_lock;
    int irq;
};

#define RING_GET_RESPONSE(_r, _p) (_p)
#define RING_PUSH_RESPONSES_AND_CHECK_NOTIFY(_r, _n) do { _n = 0; } while (0)
#define BUG() abort()

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void notify_remote_via_irq(int irq) {}