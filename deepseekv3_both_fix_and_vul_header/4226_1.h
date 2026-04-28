#include <stdint.h>

struct vcpu {
    uint8_t fpu_dirtied;
    uint8_t fpu_initialised;
};

#define ASSERT(x) 
#define is_idle_vcpu(v) (0)
#define clts() 
#define cpu_has_xsave (0)
#define XSTATE_LAZY 0
#define fpu_xrstor(v, x) 
#define fpu_fxrstor(v) 
#define fpu_init()