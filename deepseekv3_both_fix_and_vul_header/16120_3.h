#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <inttypes.h>

#define NR_ISAIRQS 16
#define XENLOG_WARNING 1
#define HVM_PARAM_VPT_ALIGN 0

typedef struct list_head {
    struct list_head *next, *prev;
} list_head_t;

typedef struct spinlock {
    int lock;
} spinlock_t;

typedef void (*time_cb)(void *);

struct timer {
    void (*function)(void *);
    void *data;
    unsigned int processor;
};

enum pt_source {
    PTSRC_isa,
    PTSRC_ioapic,
    PTSRC_lapic
};

struct hvm_domain_irq {
    unsigned int nr_gsis;
};

struct domain {
    struct {
        struct {
            struct {
                spinlock_t pt_migrate;
            } *pl_time;
            uint32_t params[1];
        } hvm;
    } arch;
};

struct vcpu {
    struct domain *domain;
    unsigned int processor;
    struct {
        struct {
            list_head_t tm_list;
            spinlock_t tm_lock;
        } hvm;
    } arch;
};

struct periodic_time {
    enum pt_source source;
    uint8_t irq;
    uint64_t period;
    uint64_t scheduled;
    uint64_t last_plt_gtime;
    struct vcpu *vcpu;
    time_cb *cb;
    void *priv;
    bool one_shot;
    bool level;
    bool on_list;
    bool *warned_timeout_too_short;
    bool irq_issued;
    bool do_not_freeze;
    unsigned int pending_intr_nr;
    list_head_t list;
    struct timer timer;
};

static inline uint64_t NOW(void) { return 0; }
static inline uint64_t hvm_get_guest_time(struct vcpu *v) { return 0; }
static inline uint64_t align_timer(uint64_t time, uint64_t period) { return 0; }
static inline void init_timer(struct timer *t, void (*fn)(void *), void *data, unsigned int cpu) {}
static inline void set_timer(struct timer *t, uint64_t expires) {}
static inline void destroy_periodic_time(struct periodic_time *pt) {}
static inline bool test_and_set_bool(bool *b) { bool old = *b; *b = true; return old; }
static inline void gdprintk(int level, const char *fmt, ...) {}
static inline void ASSERT_UNREACHABLE(void) {}
static inline void write_lock(spinlock_t *lock) {}
static inline void write_unlock(spinlock_t *lock) {}
static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}
static inline void list_add(list_head_t *new, list_head_t *head) {}
static inline struct hvm_domain_irq *hvm_domain_irq(struct domain *d) { return NULL; }
static inline void pt_timer_fn(void *data) {}