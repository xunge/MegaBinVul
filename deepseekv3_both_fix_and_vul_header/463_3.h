#include <stdint.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

struct nvmet_fc_tgtport;
struct nvmet_fc_tgt_assoc;
struct nvmet_fc_tgt_queue;

#define NVMET_NR_QUEUES 128

typedef uint64_t u64;
typedef uint16_t u16;

struct list_head {
    struct list_head *next, *prev;
};

struct nvmet_fc_tgtport {
    int lock;
    struct list_head assoc_list;
};

struct nvmet_fc_tgt_assoc {
    u64 association_id;
    struct list_head a_list;
    struct nvmet_fc_tgt_queue *queues[NVMET_NR_QUEUES];
};

struct nvmet_fc_tgt_queue {
    atomic_int connected;
};

static inline u64 nvmet_fc_getassociationid(u64 connection_id) { return 0; }
static inline u16 nvmet_fc_getqueueid(u64 connection_id) { return 0; }
static inline bool nvmet_fc_tgt_q_get(struct nvmet_fc_tgt_queue *queue) { return false; }
static inline int atomic_read(atomic_int *obj) { return atomic_load(obj); }
static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
#define list_for_each_entry(pos, head, member) for (pos = NULL; pos != NULL; pos = NULL)