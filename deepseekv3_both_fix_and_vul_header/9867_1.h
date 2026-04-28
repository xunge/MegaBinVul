#include <stdbool.h>
#include <stdlib.h>

#define __user
#define GFP_KERNEL 0
#define MAX_ARG_STRINGS 0
#define ENOMEM 12
#define PTR_ERR(x) ((long)(x))
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))

struct pt_regs {};
struct linux_binprm {
    struct file *file;
    const char *filename;
    const char *interp;
    int argc;
    int envc;
    void *p;
    void *exec;
    void *mm;
};
struct file {};
struct files_struct {};
struct task_struct {
    int in_execve;
    struct {
        int in_exec;
    } *fs;
};
extern struct task_struct *current;

void *kzalloc(size_t size, int flags);
void free_bprm(struct linux_binprm *bprm);
int unshare_files(struct files_struct **displaced);
int prepare_bprm_creds(struct linux_binprm *bprm);
int check_unsafe_exec(struct linux_binprm *bprm);
struct file *open_exec(const char *filename);
void sched_exec(void);
int bprm_mm_init(struct linux_binprm *bprm);
int count(const char __user *const __user *argv, int max);
int prepare_binprm(struct linux_binprm *bprm);
int copy_strings_kernel(int argc, const char **argv, struct linux_binprm *bprm);
int copy_strings(int argc, const char __user *const __user *argv, struct linux_binprm *bprm);
int search_binary_handler(struct linux_binprm *bprm, struct pt_regs *regs);
void acct_update_integrals(struct task_struct *tsk);
void put_files_struct(struct files_struct *fs);
void mmput(void *mm);
void allow_write_access(struct file *file);
void fput(struct file *file);
void reset_files_struct(struct files_struct *fs);