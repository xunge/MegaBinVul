#include <stdio.h>
#include <assert.h>
#include <stdint.h>

typedef struct EHCIQueue {
    int async;
    // other queue fields would be here
} EHCIQueue;

typedef struct EHCIState {
    int async_stepdown;
    int periodic_sched_active;
    // other state fields would be here
} EHCIState;

enum {
    EST_WAITLISTHEAD,
    EST_FETCHENTRY,
    EST_FETCHQH,
    EST_FETCHITD,
    EST_FETCHSITD,
    EST_ADVANCEQUEUE,
    EST_FETCHQTD,
    EST_HORIZONTALQH,
    EST_EXECUTE,
    EST_EXECUTING,
    EST_WRITEBACK
};

enum {
    PERIODIC_ACTIVE
};

int ehci_get_state(EHCIState *ehci, int async);
int ehci_state_waitlisthead(EHCIState *ehci, int async);
int ehci_state_fetchentry(EHCIState *ehci, int async);
EHCIQueue *ehci_state_fetchqh(EHCIState *ehci, int async);
int ehci_state_fetchitd(EHCIState *ehci, int async);
int ehci_state_fetchsitd(EHCIState *ehci, int async);
int ehci_state_advqueue(EHCIQueue *q);
int ehci_state_fetchqtd(EHCIQueue *q);
int ehci_state_horizqh(EHCIQueue *q);
int ehci_state_execute(EHCIQueue *q);
int ehci_state_executing(EHCIQueue *q);
int ehci_state_writeback(EHCIQueue *q);
void ehci_reset(EHCIState *ehci);