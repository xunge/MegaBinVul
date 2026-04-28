#include <sys/time.h>

struct sock {
    struct {
        void (*function)(unsigned long);
        unsigned long expires;
    } sk_timer;
};

extern unsigned long jiffies;
#define HZ 100

void rose_heartbeat_expiry(unsigned long data);
void del_timer(struct sock *sk);
void add_timer(struct sock *sk);