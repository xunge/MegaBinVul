#include <stdint.h>

#define MPI_IOC_STATE_OPERATIONAL 0x01
#define MPI_IOCSTATUS_INVALID_STATE 0x02

typedef struct MPTSASState {
    int state;
    void *request_post;
} MPTSASState;

#define MPTSAS_FIFO_EMPTY(s, fifo) (0)

void mptsas_set_fault(MPTSASState *s, int status);
void mptsas_fetch_request(MPTSASState *s);