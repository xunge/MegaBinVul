#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define BLOCKSIZE 512
#define SAFE_READ_ERROR ((size_t)-1)
#define UINTMAX_STRSIZE_BOUND 21

struct tar_sparse_file;
struct stat_info;

union block {
    char buffer[BLOCKSIZE];
};

struct sparse_map_entry {
    off_t offset;
    off_t numbytes;
};

struct stat_info {
    char *orig_file_name;
    struct stat stat;
    struct sparse_map_entry *sparse_map;
};

struct tar_sparse_file {
    int fd;
    off_t dumped_size;
    struct stat_info *stat_info;
};

extern bool lseek_or_error(struct tar_sparse_file *file, off_t offset);
extern union block *find_next_block(void);
extern size_t safe_read(int fd, void *buf, size_t count);
extern void read_diag_details(const char *filename, off_t offset, size_t size);
extern void set_next_block_after(union block *blk);
extern void set_exit_status(int status);
extern char *quotearg_colon(const char *str);
extern const char *STRINGIFY_BIGINT(size_t n, char buf[UINTMAX_STRSIZE_BOUND]);
extern const char *ngettext(const char *msgid1, const char *msgid2, unsigned long int n);
extern void WARNOPT(int warnopt, ...);

extern bool ignore_failed_read_option;
extern int TAREXIT_DIFFERS;
extern int WARN_FILE_SHRANK;