struct sock;

struct timer_list {
    unsigned long expires;
    void (*function)(unsigned long);
    unsigned long data;
};

struct rose_sock {
    struct timer_list idletimer;
};

static inline struct rose_sock *rose_sk(const struct sock *sk)
{
    return (struct rose_sock *)sk;
}

void del_timer(struct timer_list *timer);