#include <stddef.h>

#define INET_DIAG_BC_AUTO   0
#define INET_DIAG_BC_S_COND 1
#define INET_DIAG_BC_D_COND 2
#define INET_DIAG_BC_S_GE   3
#define INET_DIAG_BC_S_LE   4
#define INET_DIAG_BC_D_GE   5
#define INET_DIAG_BC_D_LE   6
#define INET_DIAG_BC_JMP    7
#define INET_DIAG_BC_NOP    8

#define EINVAL 22

struct inet_diag_bc_op {
    unsigned char code;
    unsigned char yes;
    unsigned char no;
};

static int valid_cc(const void *bytecode, int bytecode_len, int len);