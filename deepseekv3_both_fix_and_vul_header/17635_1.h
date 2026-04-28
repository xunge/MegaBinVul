#include <stdbool.h>
#include <sys/resource.h>

#define _STK_LIM (8 * 1024 * 1024)  /* 8MB default stack limit */
#define SUID_DUMP_USER 1
#define BINPRM_FLAGS_ENFORCE_NONDUMP (1 << 0)
#define TASK_SIZE ((unsigned long)(-1))

struct linux_binprm {
    unsigned int secureexec;
    unsigned int cap_elevated;
    struct rlimit rlim_stack;
    unsigned int interp_flags;
    const char *filename;
};

struct task_struct {
    unsigned int pdeath_signal;
    struct mm_struct *mm;
    unsigned long sas_ss_sp;
    unsigned long sas_ss_size;
    unsigned long self_exec_id;
};

struct mm_struct {
    unsigned long task_size;
};

extern struct task_struct *current;
extern int suid_dumpable;

void arch_pick_mmap_layout(struct mm_struct *mm, struct rlimit *rlim_stack);
void arch_setup_new_exec(void);
void perf_event_exec(void);
void __set_task_comm(struct task_struct *tsk, const char *buf, bool exec);
void set_dumpable(struct mm_struct *mm, int value);
void flush_signal_handlers(struct task_struct *tsk, int force);
const char *kbasename(const char *path);
bool uid_eq(unsigned int left, unsigned int right);
bool gid_eq(unsigned int left, unsigned int right);
unsigned int current_euid(void);
unsigned int current_uid(void);
unsigned int current_egid(void);
unsigned int current_gid(void);