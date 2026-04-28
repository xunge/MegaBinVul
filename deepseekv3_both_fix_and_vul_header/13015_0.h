#include <sys/types.h>
#include <unistd.h>

struct gru_thread_state {
    struct gru_state *ts_gru;
    pid_t ts_tgid_owner;
};

struct gru_state;

struct task_struct {
    pid_t tgid;
};

extern struct task_struct *current;

#define EINVAL 22

#define STAT(x)

int gru_check_chiplet_assignment(struct gru_state *gru, struct gru_thread_state *gts);
int gru_retarget_intr(struct gru_thread_state *gts);