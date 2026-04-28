#include <sys/types.h>
#include <stdatomic.h>
#include <stdlib.h>

struct f2fs_sb_info {
    struct super_block *sb;
    struct {
        struct flush_cmd_control *fcc_info;
    } *sm_info;
};

struct super_block {
    struct block_device *s_bdev;
};

struct block_device {
    dev_t bd_dev;
};

struct flush_cmd_control {
    _Atomic int issued_flush;
    _Atomic int issing_flush;
    void *flush_wait_queue;
    void *issue_list;
    void *f2fs_issue_flush;
};

struct task_struct;

#define ENOMEM 12
#define GFP_KERNEL 0
#define PTR_ERR(ptr) ((long)(ptr))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define MAJOR(dev) ((dev) >> 8)
#define MINOR(dev) ((dev) & 0xff)
#define test_opt(sbi, opt) 0
#define FLUSH_MERGE 0

#define SM_I(sbi) ((sbi)->sm_info)

void *issue_flush_thread(void *data);
void atomic_set(_Atomic int *atomic, int value);
void init_waitqueue_head(void *queue);
void init_llist_head(void *head);
void *kzalloc(size_t size, int flags);
void kfree(void *ptr);
void *kthread_run(void *func, void *data, const char *name_fmt, ...);