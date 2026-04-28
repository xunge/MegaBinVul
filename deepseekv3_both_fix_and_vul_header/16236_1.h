#include <stdbool.h>
#include <stddef.h>

static void __evtchn_fifo_handle_events(unsigned int cpu, bool *handled);