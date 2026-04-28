#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct OHCIState OHCIState;
typedef struct QEMUTimer QEMUTimer;

struct OHCIState {
    char *name;
    QEMUTimer *eof_timer;
};

void timer_del(QEMUTimer *timer);
void timer_free(QEMUTimer *timer);
void trace_usb_ohci_stop(const char *name);