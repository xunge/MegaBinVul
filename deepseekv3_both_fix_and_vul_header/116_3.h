#include <sys/socket.h>

struct timer_list {
    // minimal timer_list definition
    unsigned long expires;
    void (*function)(unsigned long);
    unsigned long data;
};

struct sock {
    struct timer_list timer;
};

static inline void del_timer(struct timer_list *timer) {}

static inline struct sock *rose_sk(struct sock *sk) {
    return sk;
}