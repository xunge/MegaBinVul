#include <stdint.h>
#include <stddef.h>

#define EVTCHN_ROW(evtchn) (evtchn / (sizeof(unsigned) * 8))
#define EVTCHN_COL(evtchn) (evtchn % (sizeof(unsigned) * 8))

typedef uint32_t evtchn_port_t;
extern unsigned **evtchn_to_irq;
extern unsigned xen_evtchn_max_channels(void);