#include <stdint.h>
#include <string.h>
#include <stdbool.h>

struct cpu_user_regs {
    uint64_t regs[32];
};

struct vcpu {
    struct domain *domain;
    struct {
        struct {
            uint64_t xcr0;
            struct {
                uint64_t msr_xss;
            } hvm;
            struct cpu_user_regs user_regs;
        } arch;
        unsigned int vcpu_id;
        int dirty_cpu;
    };
};

struct domain {
    struct {
        struct {
            void (*from)(struct vcpu *);
            void (*to)(struct vcpu *);
        } *ctxt_switch;
    } arch;
    unsigned long *dirty_cpumask;
};

struct desc_ptr {
    unsigned short limit;
    unsigned long base;
};

typedef struct { uint32_t a, b; } seg_desc_t;
typedef uint64_t l1_pgentry_t;
typedef uint64_t u64;

#define CTXT_SWITCH_STACK_BYTES 256
#define XSTATE_FP_SSE 0
#define X86_CR4_FSGSBASE 0
#define LAST_RESERVED_GDT_BYTE 0
#define FIRST_RESERVED_GDT_ENTRY 0
#define FIRST_RESERVED_GDT_PAGE 0
#define NR_RESERVED_GDT_PAGES 0
#define __PAGE_HYPERVISOR_RW 0
#define VCPU_CPU_CLEAN 0
#define GDT_VIRT_START(v) 0

struct vcpu *current;
struct vcpu *per_cpu_curr_vcpu[1];
seg_desc_t *per_cpu_gdt_table[1];
seg_desc_t *per_cpu_compat_gdt_table[1];
unsigned long dirty_cpumask;

#define per_cpu(var, cpu) (per_cpu_##var[cpu])
#define ASSERT(x) ((void)0)
#define BUG() (*(volatile int*)0 = 0)
#define is_idle_domain(d) 0
#define is_pv_32bit_domain(d) 0
#define is_pv_domain(d) 0
#define is_hvm_vcpu(v) 0
#define need_full_gdt(d) 0
#define vcpu_cpu_dirty(v) 0
#define cpu_has_xsave 0
#define cpu_has_xsaves 0
#define cpu_has_svm 0
#define cpu_has_fsgsbase 0
#define CONFIG_PV 0
#define CONFIG_HVM 0

static inline struct cpu_user_regs *guest_cpu_user_regs(void) { 
    static struct cpu_user_regs regs;
    return &regs; 
}
static inline unsigned int smp_processor_id(void) { return 0; }
static inline void vcpu_save_fpu(struct vcpu *v) {}
static inline void vcpu_restore_fpu_nonlazy(struct vcpu *v, bool b) {}
static inline uint64_t get_xcr0(void) { return 0; }
static inline bool set_xcr0(uint64_t x) { return false; }
static inline void set_msr_xss(uint64_t x) {}
static inline void psr_ctxt_switch_to(struct domain *d) {}
static inline unsigned long virt_to_mfn(void *p) { return 0; }
static inline l1_pgentry_t *pv_gdt_ptes(struct vcpu *v) { return NULL; }
static inline void l1e_write(l1_pgentry_t *p, l1_pgentry_t v) {}
static inline l1_pgentry_t l1e_from_pfn(unsigned long p, unsigned long f) { return 0; }
static inline void lgdt(struct desc_ptr *d) {}
static inline void write_ptbase(struct vcpu *v) {}
static inline void svm_load_segs(int a, int b, int c, int d, int e, int f, int g) {}
static inline unsigned long read_cr4(void) { return 0; }
static inline void cpumask_set_cpu(unsigned int c, unsigned long *m) { *m |= (1UL << c); }
static inline void cpumask_clear_cpu(unsigned int c, unsigned long *m) { *m &= ~(1UL << c); }
static inline void write_atomic(int *p, int v) { *p = v; }