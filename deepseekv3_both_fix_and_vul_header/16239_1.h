#include <stdlib.h>
#include <stdint.h>

typedef uint32_t evtchn_port_t;
extern unsigned int xen_evtchn_max_channels(void);
extern int **evtchn_to_irq;
#define EVTCHN_ROW(evtchn) (evtchn / (8 * sizeof(int)))
#define EVTCHN_COL(evtchn) (evtchn % (8 * sizeof(int)))
extern void clear_evtchn_to_irq_row(unsigned row);
extern void *get_zeroed_page(unsigned int flags);
#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12