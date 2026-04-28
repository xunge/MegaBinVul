#include <stdbool.h>

#define APIC_DEFAULT_PHYS_BASE 0xFEE00000
#define PAGE_ORDER_4K 0
#define MTRR_TYPE_WRBACK 0
#define INVALID_MFN 0

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;

struct vmx {
    mfn_t apic_access_mfn;
};

struct hvm {
    struct vmx vmx;
};

struct arch {
    struct hvm hvm;
};

struct domain {
    struct arch arch;
};

extern mfn_t apic_access_mfn;
extern mfn_t _mfn(unsigned long);
extern bool mfn_eq(mfn_t, mfn_t);
extern int epte_get_entry_emt(struct domain *, gfn_t, mfn_t, int, bool *, int);
extern int set_mmio_p2m_entry(struct domain *, gfn_t, mfn_t, int);
extern void domain_crash(struct domain *);
extern gfn_t gaddr_to_gfn(unsigned long);
extern void ASSERT(bool);

#define p2m_mmio_direct 0
#define cf_check