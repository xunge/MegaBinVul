#include <stdbool.h>

extern unsigned int unix_tot_inflight;
extern bool gc_in_progress;
extern int unix_gc_wait;
#define UNIX_INFLIGHT_TRIGGER_GC 100

void unix_gc(void);
void wait_event(int wait_queue, bool condition);