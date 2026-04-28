#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define BINPRM_BUF_SIZE 256

struct file {
    int dummy;
};

struct Node {
    char *interpreter;
    int flags;
};

struct linux_binprm {
    struct file *file;
    unsigned long interp_flags;
    int interp_data;
    const char *interp;
    int argc;
    char buf[BINPRM_BUF_SIZE];
};

#define MISC_FMT_PRESERVE_ARGV0 (1 << 0)
#define MISC_FMT_OPEN_BINARY (1 << 1)
#define MISC_FMT_CREDENTIALS (1 << 2)
#define BINPRM_FLAGS_EXECFD (1 << 0)

static int enabled;
static pthread_rwlock_t entries_lock = PTHREAD_RWLOCK_INITIALIZER;
static struct Node *check_file(struct linux_binprm *bprm) { return NULL; }
static int remove_arg_zero(struct linux_binprm *bprm) { return 0; }
static int get_unused_fd(void) { return open("/dev/null", O_RDONLY); }
static void fd_install(int fd, struct file *file) {}
static void would_dump(struct linux_binprm *bprm, struct file *file) {}
static void allow_write_access(struct file *file) {}
static int copy_strings_kernel(int argc, const char **argv, struct linux_binprm *bprm) { return 0; }
static struct file *open_exec(const char *name) { return NULL; }
static int prepare_binprm(struct linux_binprm *bprm) { return 0; }
static int search_binary_handler(struct linux_binprm *bprm) { return 0; }
static void sys_close(int fd) { close(fd); }
static void read_lock(pthread_rwlock_t *lock) { pthread_rwlock_rdlock(lock); }
static void read_unlock(pthread_rwlock_t *lock) { pthread_rwlock_unlock(lock); }
static size_t strlcpy(char *dst, const char *src, size_t size) { return snprintf(dst, size, "%s", src); }
static void fput(struct file *file) {}
static long PTR_ERR(const void *ptr) { return (long)ptr; }
static int IS_ERR(const void *ptr) { return (long)ptr < 0 && (long)ptr >= -4095; }
static ssize_t kernel_read(struct file *file, loff_t offset, void *buf, size_t count) { return 0; }

typedef struct Node Node;