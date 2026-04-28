#include <stdbool.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define BLOCKSIZE 512
#define SAFE_READ_ERROR (-1)

struct tar_sparse_file;
struct stat_info;

struct sparse_map {
    off_t offset;
    off_t numbytes;
};

struct tar_sparse_file {
    int fd;
    off_t dumped_size;
    struct stat_info *stat_info;
};

struct stat_info {
    char *orig_file_name;
    off_t archive_file_size;
    struct sparse_map *sparse_map;
};

union block {
    char buffer[BLOCKSIZE];
};

extern bool lseek_or_error(struct tar_sparse_file *file, off_t offset);
extern void mv_size_left(off_t size);
extern union block *find_next_block(void);
extern void set_next_block_after(union block *blk);
extern size_t safe_read(int fd, void *buf, size_t count);
extern void read_diag_details(const char *filename, off_t offset, size_t size);
extern void report_difference(struct stat_info *st, const char *message);
extern void ERROR(int code, int errnum, const char *message);
extern struct stat_info current_stat_info;
extern const char *_(const char *msg);

#define ERROR(args) ERROR args