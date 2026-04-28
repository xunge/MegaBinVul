#include <stddef.h>
#include <sys/types.h>

#define NT_PRSTATUS 1
#define NT_PRFPREG 2
#define GFP_KERNEL 0

struct task_struct;

struct elf_note {
    char name[8];
    unsigned int type;
    unsigned int datasz;
    void *data;
};

struct elf_prstatus {
    int pr_reg[32];  // Simplified register set
    // Other fields would be needed for full implementation
};

struct user_regset {
    unsigned int core_note_type;
    int (*get)(struct task_struct *target,
               const struct user_regset *regset,
               unsigned int pos, unsigned int count,
               void *kbuf, void *ubuf);
    int (*active)(struct task_struct *target,
                  const struct user_regset *regset);
};

struct user_regset_view {
    unsigned int n;
    struct user_regset regsets[];
};

struct elf_thread_core_info {
    struct task_struct *task;
    struct elf_prstatus prstatus;
    struct elf_note notes[];
};

#define PRSTATUS_SIZE(prstatus, regset_size) (sizeof(struct elf_prstatus) + regset_size)
#define SET_PR_FPVALID(prstatus, val, size) ((void)0)
#define unlikely(x) (x)

extern size_t regset_size(struct task_struct *task, const struct user_regset *regset);
extern void fill_prstatus(struct elf_prstatus *prstatus, struct task_struct *task, long signr);
extern void fill_note(struct elf_note *note, const char *name, int type, size_t datasz, const void *data);
extern size_t notesize(const struct elf_note *note);
extern void do_thread_regset_writeback(struct task_struct *task, const struct user_regset *regset);
extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);