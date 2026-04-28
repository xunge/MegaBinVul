#include <stddef.h>
#include <sys/types.h>

typedef off_t loff_t;

struct seq_file {
    void *private;
};

struct rb_node {
    struct rb_node *rb_left;
    struct rb_node *rb_right;
};

struct mm_struct {
    void *mmap_sem;
    struct rb_node mm_rb;
};

struct task_struct;
struct pid;

enum pid_type {
    PIDTYPE_PID
};

struct proc_maps_private {
    struct pid *pid;
    struct task_struct *task;
};

static inline struct task_struct *get_pid_task(struct pid *pid, enum pid_type type) { return NULL; }
static inline void put_task_struct(struct task_struct *t) {}
static inline struct mm_struct *mm_for_maps(struct task_struct *task) { return NULL; }
static inline void down_read(void *sem) {}
static inline struct rb_node *rb_first(const void *tree) { return NULL; }
static inline struct rb_node *rb_next(const struct rb_node *node) { return NULL; }