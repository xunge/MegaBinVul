#include <sys/types.h>
#include <stdbool.h>

struct net {
    struct {
        unsigned long fib6_gc_lock;
        unsigned long ip6_fib_timer;
        struct {
            int ip6_rt_gc_interval;
        } sysctl;
        unsigned long ip6_rt_last_gc;
    } ipv6;
};

struct fib6_gc_args {
    int timeout;
    int more;
};

void fib6_clean_all(struct net *net, void (*func)(void), struct fib6_gc_args *args);
void fib6_age(void);
void spin_lock_bh(unsigned long *lock);
int spin_trylock_bh(unsigned long *lock);
void spin_unlock_bh(unsigned long *lock);
void mod_timer(unsigned long *timer, unsigned long expires);
void del_timer(unsigned long *timer);
unsigned long jiffies;
#define HZ 100
unsigned long round_jiffies(unsigned long j);