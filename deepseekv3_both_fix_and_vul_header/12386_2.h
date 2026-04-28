#include <stdint.h>
#include <stddef.h>

typedef unsigned long register_t;
typedef uint64_t paddr_t;

typedef struct {
    unsigned long far_el2;
} sysreg_t;

#define READ_SYSREG(reg) (sysreg_t){}.far_el2

union hsr {
    struct {
        unsigned int ifsc;
        unsigned int eat;
        unsigned int s1ptw;
    } iabt;
    unsigned int len;
};

struct domain;
struct cpu_user_regs;

typedef struct {
    struct domain *domain;
} current_t;

extern current_t *current;

struct npfec {
    int insn_fetch;
    int gla_valid;
    int kind;
};

enum npfec_kind {
    npfec_kind_in_gpt,
    npfec_kind_with_gla
};

typedef struct {
    unsigned long mfn;
} mfn_t;

#define INVALID_MFN ((mfn_t){0})
#define FSC_LL_MASK 0x3F
#define FSC_FLT_PERM 0xD
#define FSC_FLT_TRANS 0x4
#define GV2M_READ 0
#define EFAULT 14

#define mfn_eq(a, b) ((a).mfn == (b).mfn)
#define _gfn(x) (x)
#define paddr_to_pfn(x) ((x) >> 12)

void domain_crash_synchronous(void);
int hpfar_is_valid(unsigned int s1ptw, uint8_t fsc);
paddr_t get_faulting_ipa(register_t gva);
void flush_tlb_local(void);
int gva_to_ipa(register_t gva, paddr_t *gpa, int flags);
void p2m_mem_access_check(paddr_t gpa, register_t gva, struct npfec npfec);
mfn_t p2m_lookup(struct domain *d, unsigned long gfn, void *null);
void inject_iabt_exception(struct cpu_user_regs *regs, register_t gva, unsigned int len);