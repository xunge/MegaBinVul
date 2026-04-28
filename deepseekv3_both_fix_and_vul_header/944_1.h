#include <stdlib.h>

#define HB_MAGIC 0x12345678
#define HASHBIN_SIZE 32
#define HB_LOCK 0x0001

typedef void (*FREE_FUNC)(void*);

typedef struct irda_queue_t {
    struct irda_queue_t* q_next;
    struct irda_queue_t* q_prev;
} irda_queue_t;

typedef struct hashbin_t {
    int magic;
    int hb_type;
    int hb_spinlock;
    irda_queue_t* hb_queue[HASHBIN_SIZE];
    irda_queue_t* hb_current;
} hashbin_t;

extern int hashbin_lock_depth;

#define IRDA_ASSERT(expr, ret) \
    do { if (!(expr)) { ret; } } while (0)

#define spin_lock_irqsave_nested(lock, flags, depth) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define kfree(ptr) free(ptr)

irda_queue_t* dequeue_first(irda_queue_t** queue);