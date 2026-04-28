#define IOPRIO_CLASS_NONE 0
#define IOPRIO_NORM 4
#define IOPRIO_PRIO_VALUE(class, data) (((class) << 8) | (data))

struct task_struct {
    struct io_context *io_context;
};

struct io_context {
    int ioprio;
};

static inline int security_task_getioprio(struct task_struct *p) { return 0; }