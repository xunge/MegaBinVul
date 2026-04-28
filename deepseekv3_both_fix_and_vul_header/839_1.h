#include <stdbool.h>
#include <stddef.h>

struct vcpu {
    struct domain *domain;
    struct {
        unsigned long flags;
        unsigned long cr3;
        struct {
            bool need_update_runstate_area;
            struct {
                int version;
            } pending_system_time;
            bool pcid;
        } pv;
    } arch;
};

struct domain {
    struct {
        struct {
            bool xpti;
            bool pcid;
        } pv;
    } arch;
};

struct cpu_info {
    bool root_pgt_changed;
    unsigned long pv_cr3;
};

extern unsigned long root_pgt;

static inline unsigned long __pa(const void *p) { return 0; }
static inline unsigned long get_pcid_bits(struct vcpu *v, bool b) { return 0; }
static inline bool shadow_mode_enabled(const struct domain *d) { return false; }
static inline void update_cr3(struct vcpu *v) {}
static inline bool update_runstate_area(struct vcpu *v) { return false; }
static inline bool update_secondary_system_time(struct vcpu *v, void *p) { return false; }
static inline void write_cr3(unsigned long cr3) {}
static inline struct cpu_info *get_cpu_info(void) { return NULL; }
static inline void *this_cpu(void *p) { return NULL; }

#define TF_kernel_mode 0
#define X86_CR3_NOFLUSH 0