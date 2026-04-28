#include <stddef.h>
#include <sys/types.h>
#include <stdbool.h>

struct file {
    void *private_data;
};

struct ib_ucm_file;
struct ib_ucm_cmd_hdr {
    unsigned int cmd;
    unsigned int in;
    unsigned int out;
};

typedef ssize_t (*ucm_cmd_func)(struct ib_ucm_file *, const char *, unsigned int, unsigned int);

extern bool ib_safe_file_access(struct file *filp);
extern int copy_from_user(void *dst, const void *src, size_t size);
extern ucm_cmd_func ucm_cmd_table[10];  // 假设有10个命令

#define WARN_ON_ONCE(cond) (cond)
#define __user
#define loff_t long
#define EACCES 13
#define EINVAL 22
#define EFAULT 14
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))