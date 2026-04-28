#include <sys/socket.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <signal.h>

struct sock {
    int sk_err;
};

struct sctp_association {
    struct {
        struct sock *sk;
        int dead;
    } base;
    int state;
    long wait;
};

#define SCTP_STATE_SHUTDOWN_PENDING 0
#define TASK_INTERRUPTIBLE 0
#define EPIPE 32
#define EAGAIN 11

#define DEFINE_WAIT(name)
#define prepare_to_wait_exclusive(wait_queue, wait, state)
#define finish_wait(wait_queue, wait)
#define schedule_timeout(timeout) 0
#define release_sock(sk)
#define lock_sock(sk)
#define BUG_ON(cond)
#define signal_pending(current) 0
#define current 0
#define sock_intr_errno(timeo) 0
#define pr_debug(fmt, ...)

static void sctp_association_hold(struct sctp_association *asoc) {}
static void sctp_association_put(struct sctp_association *asoc) {}
static size_t sctp_wspace(struct sctp_association *asoc) { return 0; }