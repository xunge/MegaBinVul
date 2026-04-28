#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

struct io_ring_ctx {
    int sqo_sq_wait;
    bool sqo_dead;
};

#define DEFINE_WAIT(name) int name
#define TASK_INTERRUPTIBLE 1
#define unlikely(x) (x)
#define EOWNERDEAD 130
#define current getpid()

void prepare_to_wait(int *wq, int *wait, int state);
void finish_wait(int *wq, int *wait);
int io_sqring_full(struct io_ring_ctx *ctx);
int signal_pending(pid_t pid);
void schedule(void);