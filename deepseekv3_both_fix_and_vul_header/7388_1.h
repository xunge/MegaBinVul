#include <stdint.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

#define smp_processor_id() 0
#define read_atomic(ptr) (*(ptr))
#define unlikely(cond) (cond)
#define likely(cond) (cond)
#define ASSERT(cond) ((void)0)
#define local_irq_is_enabled() true
#define local_irq_disable() ((void)0)
#define local_irq_enable() ((void)0)
#define DEFINE_PER_CPU(type, name) type name
#define this_cpu(var) var
#define per_cpu(var, cpu) var
#define BUILD_BUG_ON(cond) ((void)0)
#define wrmsrl(msr, val) ((void)0)

#define FLUSH_VCPU_STATE 0
#define VCPU_CPU_CLEAN 0
#define PRED_CMD_IBPB 0
#define MSR_PRED_CMD 0
#define MAX_VIRT_CPUS 0xffff
#define NP2M_SCHEDLE_OUT 0
#define NP2M_SCHEDLE_IN 0
#define SCF_verw 0

struct vcpu {
    struct domain *domain;
    unsigned int dirty_cpu;
    struct {
        struct {
            struct list_head tm_list;
        } hvm;
    } arch;
    unsigned int vcpu_id;
};

struct domain {
    unsigned int domain_id;
    struct {
        bool verw;
        struct {
            void *tail;
        } *ctxt_switch;
    } arch;
};

struct cpu_info {
    bool use_pv_cr3;
    unsigned int xen_cr3;
    unsigned int spec_ctrl_flags;
};

static struct cpu_info cpu_info;
static bool opt_ibpb;
static struct vcpu *curr_vcpu;

static inline struct cpu_info *get_cpu_info(void) { return &cpu_info; }
static inline void flush_mask(int mask, int flags) {}
static inline bool vcpu_cpu_dirty(struct vcpu *v) { return false; }
static inline void _update_runstate_area(struct vcpu *v) {}
static inline void vpmu_switch_from(struct vcpu *v) {}
static inline void vpmu_switch_to(struct vcpu *v) {}
static inline void np2m_schedule(int cmd) {}
static inline bool is_hvm_domain(const struct domain *d) { return false; }
static inline bool list_empty(const struct list_head *head) { return true; }
static inline void pt_save_timer(struct vcpu *v) {}
static inline void set_current(struct vcpu *v) {}
static inline bool is_idle_domain(const struct domain *d) { return false; }
static inline bool cpu_online(int cpu) { return true; }
static inline void __context_switch(void) {}
static inline bool is_pv_domain(const struct domain *d) { return false; }
static inline void load_segments(struct vcpu *v) {}
static inline void ctxt_switch_levelling(struct vcpu *v) {}
static inline void sched_context_switched(struct vcpu *prev, struct vcpu *next) {}
static inline void update_vcpu_system_time(struct vcpu *v) {}
static inline void reset_stack_and_jump_ind(void *addr) {}
static inline int cpumask_of(int cpu) { return 0; }