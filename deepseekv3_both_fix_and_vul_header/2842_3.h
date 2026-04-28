#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>

struct tar_sparse_file;
struct stat_info;

struct tar_sparse_file {
    int fd;
    bool seekable;
    off_t offset;
    off_t dumped_size;
    struct stat_info *stat_info;
};

struct stat_info {
    char *orig_file_name;
    off_t archive_file_size;
    struct {
        off_t offset;
        off_t numbytes;
    } *sparse_map;
};

#define BLOCKSIZE 512

union block {
    char buffer[BLOCKSIZE];
};

extern bool lseek_or_error(struct tar_sparse_file *file, off_t offset);
extern int sys_truncate(int fd);
extern void truncate_warn(const char *filename);
extern union block *find_next_block(void);
extern void set_next_block_after(union block *blk);
extern size_t blocking_write(int fd, const void *buf, size_t count);
extern void mv_size_left(off_t size_left);
extern void write_error_details(const char *filename, size_t written, size_t expected);
extern void ERROR(int code, int errnum, const char *message);
extern const char *_(const char *msgid);

#define ERROR(args) ERROR args