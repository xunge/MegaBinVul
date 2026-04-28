#include <stddef.h>
#include <signal.h>
#include <stdbool.h>

#define BINPRM_FLAGS_PATH_INACCESSIBLE (1 << 0)

struct linux_binprm {
    struct file *file;
    char *fdpath;
    int interp_flags;
    int point_of_no_return;
    void *cred;
};

struct filename {
    char *name;
};

struct file {
    // minimal file struct definition
};

struct files_struct {
    struct fdtable *fdt;
};

struct fdtable {
    // minimal fdtable definition
};

struct task_struct {
    int in_execve;
    struct fs_struct *fs;
    struct files_struct *files;
};

struct fs_struct {
    int in_exec;
};

#define PTR_ERR(ptr) ((long)(ptr))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define rcu_dereference_raw(p) (p)

static int unshare_files(struct files_struct **);
static int prepare_bprm_creds(struct linux_binprm *);
static void check_unsafe_exec(struct linux_binprm *);
static struct file *do_open_execat(int, struct filename *, int);
static void sched_exec(void);
static int close_on_exec(int, struct fdtable *);
static int security_bprm_creds_for_exec(struct linux_binprm *);
static int exec_binprm(struct linux_binprm *);
static void rseq_execve(struct task_struct *);
static void acct_update_integrals(struct task_struct *);
static void task_numa_free(struct task_struct *, bool);
static void put_files_struct(struct files_struct *);
static int fatal_signal_pending(struct task_struct *);
static void force_sigsegv(int);
static void reset_files_struct(struct files_struct *);

extern struct task_struct *current;