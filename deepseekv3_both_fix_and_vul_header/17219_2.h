#include <stdint.h>
#include <stddef.h>

typedef struct spinlock {
    int lock;
} spinlock_t;

struct list_head {
    struct list_head *next, *prev;
};

struct timer {
    void *data;
};

typedef void (*time_cb)(void *);

struct hvm_domain_irq {
    unsigned int nr_gsis;
};

struct vcpu {
    struct domain *domain;
    struct {
        struct hvm_vcpu {
            spinlock_t tm_lock;
            struct list_head tm_list;
        } hvm_vcpu;
    } arch;
    unsigned int processor;
};

struct periodic_time {
    unsigned int source;
    uint8_t irq;
    uint64_t period;
    uint64_t scheduled;
    uint64_t last_plt_gtime;
    unsigned int pending_intr_nr;
    unsigned int do_not_freeze;
    unsigned int irq_issued;
    unsigned int one_shot;
    unsigned int on_list;
    unsigned int warned_timeout_too_short;
    struct list_head list;
    struct timer timer;
    time_cb *cb;
    void *priv;
    struct vcpu *vcpu;
};

struct domain {
    struct {
        struct hvm_domain {
            unsigned long params[256];
        } hvm_domain;
    } arch;
};

enum {
    PTSRC_isa,
    PTSRC_ioapic,
    PTSRC_lapic
};

#define NR_ISAIRQS 16
#define HVM_PARAM_VPT_ALIGN 0
#define NOW() (0)
#define ASSERT_UNREACHABLE() do { } while (0)
#define ASSERT(x) do { } while (0)
#define PRIu64 "llu"
#define XENLOG_WARNING 1

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline void list_add(struct list_head *new, struct list_head *head) { (void)new; (void)head; }
static inline void init_timer(struct timer *timer, void (*fn)(void *), void *data, unsigned int cpu) { (void)timer; (void)fn; (void)data; (void)cpu; }
static inline void set_timer(struct timer *timer, uint64_t expires) { (void)timer; (void)expires; }
static inline uint64_t hvm_get_guest_time(struct vcpu *v) { (void)v; return 0; }
static inline uint64_t align_timer(uint64_t time, uint64_t period) { (void)time; (void)period; return 0; }
static inline int test_and_set_bool(unsigned int *b) { (void)b; return 0; }
static inline void gdprintk(int level, const char *fmt, ...) { (void)level; (void)fmt; }
static inline void destroy_periodic_time(struct periodic_time *pt) { (void)pt; }
static inline void pt_timer_fn(void *data) { (void)data; }
static inline struct hvm_domain_irq *hvm_domain_irq(struct domain *d) { (void)d; return NULL; }