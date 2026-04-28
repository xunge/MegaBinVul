#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned int u32;
typedef unsigned long long u64;

struct file {
    int f_mode;
};

#define O_RDONLY 0
#define FMODE_NONOTIFY 0
#define SEEK_END 2
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define pr_err(fmt, ...) 
#define pr_info(fmt, ...) 

extern struct file *ksu_filp_open_compat(const char *path, int flags, int mode);
extern ssize_t ksu_kernel_read_compat(struct file *file, void *buf, size_t count, loff_t *pos);
extern loff_t generic_file_llseek(struct file *file, loff_t offset, int whence);
extern int filp_close(struct file *file, int flags);
extern bool check_block(struct file *fp, u32 *size4, loff_t *pos, uint32_t *offset, unsigned expected_size, const char *expected_sha256);