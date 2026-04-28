#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef int32_t loff_t;
typedef uint32_t u32;
typedef uint64_t u64;

struct file {
    int f_mode;
};

#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define FMODE_NONOTIFY (0)
#define O_RDONLY (0)
#define SEEK_END (0)

static inline void pr_err(const char *fmt, ...) {}
static inline void pr_info(const char *fmt, ...) {}

static inline loff_t generic_file_llseek(struct file *file, loff_t offset, int whence) { return 0; }
static inline struct file *ksu_filp_open_compat(const char *path, int flags, int mode) { return NULL; }
static inline int ksu_kernel_read_compat(struct file *file, void *buf, size_t count, loff_t *pos) { return 0; }
static inline int filp_close(struct file *file, int flags) { return 0; }
static inline bool check_block(struct file *fp, u32 *size4, loff_t *pos, uint32_t *offset, unsigned expected_size, const char *expected_sha256) { return false; }
static inline bool has_v1_signature_file(struct file *fp) { return false; }