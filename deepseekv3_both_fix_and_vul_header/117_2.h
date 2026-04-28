#include <sys/socket.h>
#include <errno.h>

struct sock {
    // basic sock structure members
};

struct timer_list {
    // timer structure members
};

struct neighbour {
    int use;
    // other neighbour structure members
};

struct rose_sock {
    struct sock sock;
    struct timer_list timer;
    int state;
    int condition;
    struct neighbour *neighbour;
};

#define ROSE_STATE_1 1
#define ROSE_STATE_2 2
#define ROSE_STATE_3 3
#define ROSE_STATE_4 4

#define ROSE_COND_ACK_PENDING (1 << 0)

#define ROSE_CLEAR_REQUEST 1
#define ETIMEDOUT 110

void bh_lock_sock(struct sock *sk);
void bh_unlock_sock(struct sock *sk);
void rose_write_internal(struct sock *sk, int type);
void rose_start_t3timer(struct sock *sk);
void rose_disconnect(struct sock *sk, int reason, int cause, int diagnostic);
void rose_enquiry_response(struct sock *sk);
#define from_timer(ptr, timer_ptr, timer_member) ((ptr))