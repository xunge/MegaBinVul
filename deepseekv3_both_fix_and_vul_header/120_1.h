#include <sys/time.h>

struct sock;
struct timer_list {
    void (*function)(unsigned long);
    unsigned long expires;
};

struct rose_sock {
    struct timer_list timer;
    unsigned long t2;
};

static inline struct rose_sock *rose_sk(const struct sock *sk)
{
    return (struct rose_sock *)sk;
}

extern unsigned long jiffies;
void del_timer(struct timer_list *);
void add_timer(struct timer_list *);
void rose_timer_expiry(unsigned long);