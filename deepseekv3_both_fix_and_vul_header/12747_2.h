#include <sys/socket.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <stddef.h>

#define TASK_INTERRUPTIBLE 1
#define SCTP_STATE_SHUTDOWN_PENDING 5

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

struct sock {
    int sk_err;
};

struct sctp_association {
    struct {
        struct sock *sk;
        int dead;
    } base;
    int state;
    struct list_head wait;
};

void sctp_association_hold(struct sctp_association *asoc);
void sctp_association_put(struct sctp_association *asoc);
size_t sctp_wspace(struct sctp_association *asoc);
void prepare_to_wait_exclusive(struct list_head *q, struct list_head *wait, int state);
void finish_wait(struct list_head *q, struct list_head *wait);
void release_sock(struct sock *sk);
void lock_sock(struct sock *sk);
long schedule_timeout(long timeout);
int signal_pending(long current);
int sock_intr_errno(long timeout);

#define current (get_current())
long get_current(void);

#define DEFINE_WAIT(name) struct list_head name = LIST_HEAD_INIT(name)

#define pr_debug(fmt, ...)