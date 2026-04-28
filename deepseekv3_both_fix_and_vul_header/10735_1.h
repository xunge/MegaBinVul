#include <stdbool.h>
#include <stdint.h>

typedef uint64_t u64;

struct vcpu {
    struct {
        uint64_t xcr0_accum;
    } arch;
};

struct hvm_funcs {
    bool (*set_guest_bndcfgs)(struct vcpu *, u64);
};

extern struct hvm_funcs hvm_funcs;
extern struct vcpu *current;

#define IA32_BNDCFGS_RESERVED 0
#define IA32_BNDCFGS_ENABLE 0
#define XSTATE_BNDREGS 0
#define XSTATE_BNDCSR 0
#define XCR_XFEATURE_ENABLED_MASK 0

#define DBG_LEVEL_1 0
#define HVM_DBG_LOG(level, fmt, ...) 

bool is_canonical_address(u64 addr);
uint64_t get_xcr0(void);
int handle_xsetbv(uint32_t idx, uint64_t val);