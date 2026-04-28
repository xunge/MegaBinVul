#include <stdlib.h>
#include <stdint.h>
#include <time.h>

struct timer_list {
    unsigned long expires;
};

struct ip_mc_list {
    int tm_running;
    struct timer_list timer;
    int refcnt;
};

unsigned int get_random_u32_below(unsigned int max);
int mod_timer(struct timer_list *timer, unsigned long expires);
void refcount_inc(int *refcnt);

extern unsigned long jiffies;