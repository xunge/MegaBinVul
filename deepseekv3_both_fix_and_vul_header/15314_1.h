#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

struct linux_binprm {
    struct mm_struct *mm;
    struct file *file;
    char *filename;
    struct cred *cred;
    unsigned int interp_flags;
    unsigned int per_clear;
};

struct task_struct {
    char comm[16];
    struct mm_struct *mm;
    unsigned long flags;
    unsigned long sas_ss_sp;
    unsigned long sas_ss_size;
    int pdeath_signal;
    unsigned int personality;
    unsigned long self_exec_id;
    struct files_struct *files;
};

struct mm_struct {
    unsigned long task_size;
    int dumpable;
};

struct file;
struct cred {
    uid_t uid;
    gid_t gid;
};
struct files_struct;

#define PF_RANDOMIZE 0
#define TASK_SIZE 0
#define MAY_READ 0
#define BINPRM_FLAGS_ENFORCE_NONDUMP 0

extern struct task_struct *current;
extern int suid_dumpable;

int de_thread(struct task_struct *);
void set_mm_exe_file(struct mm_struct *, struct file *);
int exec_mmap(struct mm_struct *);
void set_dumpable(struct mm_struct *, int);
void set_task_comm(struct task_struct *, const char *);
void flush_thread(void);
int file_permission(struct file *, int);
void perf_event_exit_task(struct task_struct *);
void flush_signal_handlers(struct task_struct *, int);
void flush_old_files(struct files_struct *);

static inline uid_t current_euid(void) { return geteuid(); }
static inline uid_t current_uid(void) { return getuid(); }
static inline gid_t current_egid(void) { return getegid(); }
static inline gid_t current_gid(void) { return getgid(); }
static inline int get_dumpable(struct mm_struct *mm) { return mm->dumpable; }