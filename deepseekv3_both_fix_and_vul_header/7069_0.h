struct files_struct;
struct io_uring_task {
    void *xa;
};
struct task_struct {
    struct io_uring_task *io_uring;
};
extern struct task_struct *current;
extern int xa_empty(void *xa);
extern void __io_uring_files_cancel(struct files_struct *files);
extern void __io_uring_cancel(bool cancel_all);