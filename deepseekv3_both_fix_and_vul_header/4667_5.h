#include <sys/types.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint32_t __u32;
typedef uint16_t __u16;
typedef off_t loff_t;

struct ucma_file;
struct file {
    void *private_data;
};

struct rdma_ucm_cmd_hdr {
    __u32 cmd;
    __u32 in;
    __u32 out;
    __u16 reserved;
};

#define __user
#define WARN_ON_ONCE(cond) (cond)

typedef ssize_t (*ucma_cmd_func)(struct ucma_file *, const char *, size_t, size_t);
extern ucma_cmd_func ucma_cmd_table[];
extern const size_t ucma_cmd_table_size;
extern bool ib_safe_file_access(struct file *filp);
extern int copy_from_user(void *to, const void __user *from, unsigned long n);

#define EACCES 13
#define EINVAL 22
#define EFAULT 14
#define ENOSYS 38