#include <stdbool.h>

#define KVM_NR_VAR_MTRR 8
#define MSR_MTRRfix64K_00000 0x250
#define MSR_MTRRfix16K_80000 0x258
#define MSR_MTRRfix16K_A0000 0x259
#define MSR_MTRRfix4K_C0000 0x268
#define MSR_MTRRfix4K_C8000 0x269
#define MSR_MTRRfix4K_D0000 0x26A
#define MSR_MTRRfix4K_D8000 0x26B
#define MSR_MTRRfix4K_E0000 0x26C
#define MSR_MTRRfix4K_E8000 0x26D
#define MSR_MTRRfix4K_F0000 0x26E
#define MSR_MTRRfix4K_F8000 0x26F
#define MSR_MTRRdefType 0x2FF
#define MSR_IA32_CR_PAT 0x277