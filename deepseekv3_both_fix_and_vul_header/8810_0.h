#include <stdint.h>
#include <inttypes.h>

#define VMW_IS_MULTIREG_ADDR(addr, reg, num, align) \
    (((addr) >= (reg)) && ((addr) < (reg) + (num) * (align)))
#define VMW_MULTIREG_IDX_BY_ADDR(addr, reg, align) \
    (((addr) - (reg)) / (align))

#define VMXNET3_REG_IMR 0
#define VMXNET3_MAX_INTRS 0
#define VMXNET3_REG_ALIGN 0

typedef uint64_t hwaddr;

typedef struct {
    int is_masked;
} InterruptState;

typedef struct VMXNET3State {
    InterruptState interrupt_states[VMXNET3_MAX_INTRS];
} VMXNET3State;

#define VMW_CBPRN(fmt, ...)