#include <stdbool.h>
#include <linux/errno.h>

struct io_kiocb;
struct task_work_struct;

extern void init_task_work(struct task_work_struct *twork, void (*func)(struct io_kiocb *));
extern bool io_wq_current_is_worker(void);
extern int io_req_task_work_add(struct io_kiocb *req, struct task_work_struct *twork);
extern void io_rw_resubmit(struct io_kiocb *req);