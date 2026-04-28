#include <sys/time.h>

struct timer_list {
    void (*function)(unsigned long);
    unsigned long expires;
};

struct rose_sock {
    struct timer_list timer;
    unsigned long t1;
};

struct sock;

extern struct rose_sock *rose_sk(struct sock *sk);
extern void rose_timer_expiry(unsigned long);
extern unsigned long jiffies;
extern void del_timer(struct timer_list *);
extern void add_timer(struct timer_list *);