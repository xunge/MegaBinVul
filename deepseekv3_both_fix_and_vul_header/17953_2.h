#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define NT_PRSTATUS 1
#define NT_PRFPREG 2
#define GFP_KERNEL 0

#define unlikely(x) (x)

typedef void* __user;

struct task_struct;

struct elf_prstatus {
    long pr_reg[0];
    int pr_fpvalid;
};

struct elf_note {
    char name[0];
    int type;
    unsigned int descsz;
    void *desc;
};

struct elf_thread_core_info {
    struct task_struct *task;
    struct elf_prstatus prstatus;
    struct elf_note notes[];
};

struct user_regset {
    int core_note_type;
    int (*active)(struct task_struct *target, const struct user_regset *regset);
    int (*get)(struct task_struct *target, const struct user_regset *regset,
               unsigned int pos, unsigned int count, void *kbuf, void *ubuf);
    size_t n;
    size_t size;
};

struct user_regset_view {
    unsigned int n;
    const struct user_regset *regsets;
};

static void fill_prstatus(struct elf_prstatus *prstatus, struct task_struct *task, long signr);
static size_t notesize(struct elf_note *note);
static void fill_note(struct elf_note *note, const char *name, int type, size_t size, void *data);
static void do_thread_regset_writeback(struct task_struct *task, const struct user_regset *regset);

static void* kmalloc(size_t size, int flags) { return malloc(size); }
static void kfree(void *ptr) { free(ptr); }