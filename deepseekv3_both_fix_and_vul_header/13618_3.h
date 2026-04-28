#include <pthread.h>

struct clocksource;
static pthread_mutex_t clocksource_mutex = PTHREAD_MUTEX_INITIALIZER;
static struct clocksource *curr_clocksource;
static int finished_booting;

struct clocksource* clocksource_default_clock(void);
void clocksource_watchdog_kthread(void*);
void clocksource_select(void);

#define __init