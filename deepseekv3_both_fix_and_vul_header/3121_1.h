#include <limits.h>
#include <sys/types.h>

#define ARCHIVE_WRITE_MAGIC 0xdeb0c5
#define ARCHIVE_STATE_DATA 1

struct archive {
    int magic;
};

struct archive_write {
    struct archive archive;
    ssize_t (*format_write_data)(struct archive_write *, const void *, size_t);
};

void archive_check_magic(struct archive *, int, int, const char *);
void archive_clear_error(struct archive *);