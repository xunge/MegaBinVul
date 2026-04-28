struct mm_struct {
    int dummy;
};

struct task_struct {
    struct mm_struct *mm;
};

struct security_operations {
    int (*vm_enough_memory)(struct mm_struct *mm, long pages);
};

extern struct security_operations *security_ops;
extern struct task_struct *current;

#define WARN_ON(condition) ((void)0)