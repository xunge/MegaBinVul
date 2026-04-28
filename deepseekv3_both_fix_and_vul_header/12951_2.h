#include <stddef.h>

struct pt_regs {
    unsigned long gpr[32];
    unsigned long nip;
    unsigned long msr;
    unsigned long orig_gpr3;
    unsigned long ctr;
    unsigned long link;
    unsigned long xer;
    unsigned long ccr;
#ifdef __powerpc64__
    unsigned long softe;
#else
    unsigned long mq;
#endif
    unsigned long trap;
    unsigned long dar;
    unsigned long dsisr;
    unsigned long result;
};

struct user_pt_regs {
    unsigned long gpr[32];
    unsigned long nip;
    unsigned long msr;
    unsigned long orig_gpr3;
    unsigned long ctr;
    unsigned long link;
    unsigned long xer;
    unsigned long ccr;
#ifdef __powerpc64__
    unsigned long softe;
#else
    unsigned long mq;
#endif
    unsigned long trap;
    unsigned long dar;
    unsigned long dsisr;
    unsigned long result;
};

#define BUILD_BUG_ON(condition) ((void)0)

#define PT_R0 0
#define PT_R1 1
#define PT_R2 2
#define PT_R3 3
#define PT_R4 4
#define PT_R5 5
#define PT_R6 6
#define PT_R7 7
#define PT_R8 8
#define PT_R9 9
#define PT_R10 10
#define PT_R11 11
#define PT_R12 12
#define PT_R13 13
#define PT_R14 14
#define PT_R15 15
#define PT_R16 16
#define PT_R17 17
#define PT_R18 18
#define PT_R19 19
#define PT_R20 20
#define PT_R21 21
#define PT_R22 22
#define PT_R23 23
#define PT_R24 24
#define PT_R25 25
#define PT_R26 26
#define PT_R27 27
#define PT_R28 28
#define PT_R29 29
#define PT_R30 30
#define PT_R31 31
#define PT_NIP 32
#define PT_MSR 33
#define PT_ORIG_R3 34
#define PT_CTR 35
#define PT_LNK 36
#define PT_XER 37
#define PT_CCR 38
#ifdef __powerpc64__
#define PT_SOFTE 39
#else
#define PT_MQ 39
#endif
#define PT_TRAP 40
#define PT_DAR 41
#define PT_DSISR 42
#define PT_RESULT 43
#define PT_REGS_COUNT 44
#define PT_DSCR 44

#define __init
#define CONFIG_PPC64