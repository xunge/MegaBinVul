#include <sys/time.h>

struct timer_list {
    void (*function)(unsigned long);
    unsigned long expires;
};

struct rose_sock {
    struct timer_list idletimer;
    unsigned long idle;
};

extern unsigned long jiffies;
struct rose_sock *rose_sk(struct sock *sk);
void rose_idletimer_expiry(unsigned long data);
void add_timer(struct timer_list *timer);
void del_timer(struct timer_list *timer);