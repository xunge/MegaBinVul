#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <poll.h>

struct userfaultfd_ctx {
    struct {
        int lock;
    } event_wqh;
    struct {
        int dummy;
    } fd_wqh;
    int released;
};

struct userfaultfd_wait_queue {
    struct userfaultfd_ctx *ctx;
    struct {
        int dummy;
    } wq;
    struct {
        unsigned int event;
        struct {
            struct {
                unsigned long reserved1;
            } reserved;
        } arg;
    } msg;
};

#define PF_EXITING 0
#define TASK_KILLABLE 0
#define TASK_RUNNING 0
#define POLLIN 0
#define UFFD_EVENT_FORK 0
#define WARN_ON_ONCE(cond) (0)
#define ACCESS_ONCE(x) (x)
#define current ((struct { int flags; } *)0)

static void init_waitqueue_entry(void *a, void *b) {}
static void __add_wait_queue(void *a, void *b) {}
static void __remove_wait_queue(void *a, void *b) {}
static void set_current_state(int state) {}
static void __set_current_state(int state) {}
static int fatal_signal_pending(void *a) { return 0; }
static void wake_up_poll(void *a, int b) {}
static void schedule(void) {}
static void userfaultfd_ctx_put(void *a) {}
static void spin_lock(int *lock) {}
static void spin_unlock(int *lock) {}