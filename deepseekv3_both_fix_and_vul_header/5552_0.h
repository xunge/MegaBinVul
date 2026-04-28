#include <linux/sched.h>
#include <linux/personality.h>

#define PF_RANDOMIZE 0
#define ADDR_NO_RANDOMIZE 0
#define STACK_RND_MASK 0
#define PAGE_SHIFT 0

struct task_struct {
    unsigned int flags;
    unsigned int personality;
};

extern struct task_struct *current;