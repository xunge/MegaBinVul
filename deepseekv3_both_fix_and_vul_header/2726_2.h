#include <string.h>
#include <errno.h>

#define BINPRM_BUF_SIZE 256

struct linux_binprm {
    char buf[BINPRM_BUF_SIZE];
    void *file;
    const char *interp;
    int argc;
};

struct file;

static inline int IS_ERR(const void *ptr) { return (long)ptr < 0 && (long)ptr >= -4095; }
static inline long PTR_ERR(const void *ptr) { return (long)ptr; }

int allow_write_access(struct file *);
void fput(struct file *);
struct file *open_exec(const char *);
int prepare_binprm(struct linux_binprm *);
int search_binary_handler(struct linux_binprm *);
int remove_arg_zero(struct linux_binprm *);
int copy_strings_kernel(int, const char **, struct linux_binprm *);