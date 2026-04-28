#include <stddef.h>

struct sock {
    int sk_state;
    int sk_err;
    int sk_shutdown;
    void (*sk_state_change)(struct sock *);
};

struct timer_list {
    // Minimal definition for compilation
};

struct rose_sock {
    struct sock sock;
    struct timer_list idletimer;
    unsigned char state;
};

#define from_timer(ptr, timer, member) \
    ((ptr) = (typeof(ptr))((char *)(timer) - offsetof(typeof(*(ptr)), member)))

#define TCP_CLOSE 7
#define SEND_SHUTDOWN 1
#define SOCK_DEAD 0x04
#define ROSE_CLEAR_REQUEST 0x0D
#define ROSE_STATE_2 2

void bh_lock_sock(struct sock *sk);
void bh_unlock_sock(struct sock *sk);
void rose_clear_queues(struct sock *sk);
void rose_write_internal(struct sock *sk, int cmd);
void rose_start_t3timer(struct sock *sk);
int sock_flag(struct sock *sk, int flag);
void sock_set_flag(struct sock *sk, int flag);
struct rose_sock *rose_sk(struct sock *sk);