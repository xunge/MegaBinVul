#include <stdbool.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>

#define BLOCKSIZE 512
#define SAFE_READ_ERROR ((size_t)-1)

struct tar_sparse_file {
    int fd;
    struct stat_info *stat_info;
};

struct stat_info {
    const char *orig_file_name;
};

extern bool lseek_or_error(struct tar_sparse_file *file, off_t beg);
extern size_t safe_read(int fd, void *buf, size_t count);
extern void read_diag_details(const char *filename, off_t offset, size_t size);
extern void report_difference(struct stat_info *stat, const char *message, ...);
extern bool zero_block_p(const char *buffer, size_t size);
extern const char *offtostr(off_t offset, char *buf);
extern const char *_(const char *msg);

#define INT_BUFSIZE_BOUND(t) (sizeof(t) * CHAR_BIT / 3 + 3)