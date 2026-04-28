#include <stdio.h>

typedef struct {
    int qntsty;
    int numguard;
    int numstepsizes;
    unsigned int *stepsizes;
} jpc_qccp_t;

typedef struct {
    jpc_qccp_t compparms;
} jpc_qcd_t;

typedef struct {
    union {
        jpc_qcd_t qcd;
    } parms;
} jpc_ms_t;

#define JAS_CAST(type, expr) ((type)(expr))
#define JPC_QCX_GETEXPN(x) ((x) >> 11)
#define JPC_QCX_GETMANT(x) ((x) & 0x7ff)