#include <sys/time.h>

struct timer_list {
    void (*function)(unsigned long);
    unsigned long expires;
};

struct rose_sock {
    struct timer_list timer;
    unsigned long hb;
};

extern struct rose_sock *rose_sk(struct sock *sk);
extern void rose_timer_expiry(unsigned long data);

unsigned long jiffies;