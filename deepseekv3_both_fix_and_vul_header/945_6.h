#include <stddef.h>
#include <linux/types.h>
#include <linux/errno.h>

#define TASK_INTERRUPTIBLE 1
#define SCTP_STATE_SHUTDOWN_PENDING 5
#define EPIPE 32
#define EAGAIN 11
#define MSG_FIN 0x200

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

struct sock {
    int sk_err;
};

struct sockaddr_storage {
    unsigned short ss_family;
    char __data[128];
};

struct list_head {
    struct list_head *next, *prev;
};

struct wait_queue_head {
    struct list_head head;
    unsigned int lock;
};

struct task_struct;
#define current ((struct task_struct *)0)

struct wait_queue_entry {
    unsigned int flags;
    void *private;
    int (*func)(void *);
    struct list_head entry;
};

#define DEFINE_WAIT(name) \
    struct wait_queue_entry name = { \
        .private = current, \
        .func = 0, \
        .entry = { NULL, NULL } \
    }

typedef int (*wait_queue_func_t)(void *);

struct sctp_association_base {
    struct sock *sk;
    int dead;
};

struct sctp_association {
    struct sctp_association_base base;
    struct wait_queue_head wait;
    int state;
    int sk_err;
};