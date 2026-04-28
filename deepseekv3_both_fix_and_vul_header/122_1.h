#include <sys/time.h>

struct timer_list {
    void (*function)(unsigned long);
    unsigned long expires;
};

struct rose_sock {
    struct timer_list timer;
    unsigned long t3;
};

unsigned long jiffies;

void rose_timer_expiry(unsigned long data);
struct rose_sock *rose_sk(struct sock *sk);
void del_timer(struct timer_list *timer);
void add_timer(struct timer_list *timer);