#include <stdint.h>
#include <stddef.h>

#define ENOENT 2
#define EINVAL 22

#define EVTCHN_FIFO_LINK_BITS 0
#define EVTCHN_FIFO_NR_CHANNELS 0

#define PAGE_SIZE 4096

struct vcpu {
    struct domain *domain;
};

struct domain {
    struct vcpu *vcpu;
    unsigned int max_evtchns;
    void *evtchn_fifo;
    void *evtchn_port_ops;
    void *event_lock;
};

struct current_struct {
    struct domain *domain;
};

extern struct current_struct *current;

struct evtchn_init_control {
    uint32_t vcpu;
    uint64_t control_gfn;
    uint32_t offset;
    uint32_t link_bits;
};

struct evtchn_fifo_control_block {
    uint8_t data[64];
};

typedef struct evtchn_fifo_control_block evtchn_fifo_control_block_t;

static inline uint32_t array_index_nospec(uint32_t index, uint32_t size) {
    return index;
}

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}

static inline struct vcpu *domain_vcpu(struct domain *d, uint32_t vcpu_id) {
    return NULL;
}

static inline int setup_control_block(struct vcpu *v) {
    return 0;
}

static inline int setup_event_array(struct domain *d) {
    return 0;
}

static inline int map_control_block(struct vcpu *v, uint64_t gfn, uint32_t offset) {
    return 0;
}

static inline void evtchn_fifo_destroy(struct domain *d) {}
static inline void setup_ports(struct domain *d, ...) {}

static inline unsigned int max_evtchns(struct domain *d) {
    return 0;
}

#define for_each_vcpu(d, v) for (v = d->vcpu; v != NULL; v = NULL)

struct evtchn_port_ops_fifo {
    int dummy;
};

extern struct evtchn_port_ops_fifo evtchn_port_ops_fifo;