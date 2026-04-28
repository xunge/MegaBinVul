#include <signal.h>

struct sigaction;

struct k_sigaction {
    struct sigaction sa;
};

struct sighand_struct {
    struct k_sigaction action[NSIG];
};

struct task_struct {
    struct sighand_struct *sighand;
};