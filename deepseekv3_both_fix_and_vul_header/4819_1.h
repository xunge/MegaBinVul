#include <stdint.h>
#include <stdlib.h>

typedef struct QEMUTimer QEMUTimer;
typedef struct OHCIState OHCIState;

#define QEMU_CLOCK_VIRTUAL 1

struct OHCIState {
    char *name;
    QEMUTimer *eof_timer;
};

struct QEMUTimer {
    int dummy;
};

void ohci_eof_timer(OHCIState *ohci) {}
void ohci_frame_boundary(void *opaque) {}
void ohci_die(OHCIState *ohci) {}
QEMUTimer *timer_new_ns(int type, void (*cb)(void *), void *opaque) { return NULL; }
void trace_usb_ohci_start(const char *name) {}
void trace_usb_ohci_bus_eof_timer_failed(const char *name) {}