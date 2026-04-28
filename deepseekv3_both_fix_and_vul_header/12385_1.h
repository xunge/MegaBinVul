#include <stdint.h>
#include <stddef.h>

#define CONFIG_ARM_32
#define FSC_LL_MASK 0x3F
#define FSC_FLT_PERM 0xD
#define FSC_FLT_TRANS 0x4
#define XENLOG_WARNING 1
#define XENLOG_DEBUG 2
#define PRIregister "lx"
#define PRIvaddr "lx"
#define PRIpaddr "lx"
#define EFAULT (-14)
#define GV2M_READ 0
#define INVALID_MFN ((mfn_t){0})

struct cpu_user_regs {
    uint64_t pc;
};

struct hsr_dabt {
    uint32_t dfsc;
    uint8_t write;
    uint8_t s1ptw;
    uint8_t eat;
};

union hsr {
    uint32_t bits;
    struct hsr_dabt dabt;
};

struct npfec {
    uint8_t read_access;
    uint8_t write_access;
    uint8_t gla_valid;
    uint8_t kind;
};

enum npfec_kind {
    npfec_kind_in_gpt,
    npfec_kind_with_gla
};

typedef struct {
    uint64_t mfn;
} mfn_t;

typedef struct {
    struct hsr_dabt dabt;
    uint64_t gva;
    uint64_t gpa;
} mmio_info_t;

struct domain;
struct domain *current;

#define READ_CP32(reg) (0)
#define READ_SYSREG64(reg) (0)
#define gprintk(level, fmt, ...)
#define gdprintk(level, fmt, ...)
#define p2m_lookup(domain, gfn, p2mt) ((mfn_t){0})
#define p2m_mem_access_check(gpa, gva, npfec)
#define try_handle_mmio(regs, info) (0)
#define advance_pc(regs, hsr)
#define inject_dabt_exception(regs, gva, len)
#define domain_crash_synchronous()
#define hpfar_is_valid(s1ptw, fsc) (0)
#define get_faulting_ipa(gva) (0)
#define gva_to_ipa(gva, ipa, flags) (0)
#define paddr_to_pfn(paddr) (0)
#define _gfn(pfn) (0)
#define mfn_eq(a, b) (0)