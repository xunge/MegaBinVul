#include <stdint.h>
#include <setjmp.h>

typedef struct _oe_callsite_t {
    uint32_t mxcsr;
    uint16_t fcw;
    uint64_t rflags;
    jmp_buf jmpbuf;
} oe_callsite_t;

typedef struct _oe_sgx_td_t {
    oe_callsite_t* callsites;
    uint16_t oret_func;
    uint16_t oret_result;
    uint64_t oret_arg;
} oe_sgx_td_t;

#define OE_INLINE static inline

void oe_longjmp(jmp_buf env, int val);