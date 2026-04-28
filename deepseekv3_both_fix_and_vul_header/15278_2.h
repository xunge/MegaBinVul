#include <stddef.h>
#include <string.h>

typedef unsigned long ulong;

#define MAX_EVENTS 256
#define TRACE2(x)

typedef struct gdth_evt_str {
    int event_source;
} gdth_evt_str;

typedef struct gdth_ha_str {
    ulong smp_lock;
} gdth_ha_str;

extern gdth_evt_str *ebuffer;
extern int eoldidx;
extern int elastidx;