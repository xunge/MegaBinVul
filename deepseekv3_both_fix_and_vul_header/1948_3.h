#include <stddef.h>

struct task_struct;
struct thread_info {
    char xtregs_cp[0];
    char xtregs_user[0];
};
struct pt_regs {
    char xtregs_opt[0];
};
typedef struct elf_xtregs_t {
    struct {
        char cp0[0];
    };
    char opt[0];
    char user[0];
} elf_xtregs_t;
typedef char xtregs_coprocessor_t[0];

#define VERIFY_READ 0
#define XTENSA_HAVE_COPROCESSORS 0
#define EFAULT 1
#define __user

static inline int access_ok(int type, const void *addr, unsigned long size) { return 1; }
static inline struct thread_info *task_thread_info(struct task_struct *task) { return NULL; }
static inline struct pt_regs *task_pt_regs(struct task_struct *task) { return NULL; }
static inline void coprocessor_flush_all(struct thread_info *ti) {}
static inline void coprocessor_release_all(struct thread_info *ti) {}
static inline int __copy_from_user(void *to, const void *from, unsigned long n) { return 0; }