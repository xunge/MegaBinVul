#include <stdint.h>
#include <stddef.h>

#define LOGICAL_BLOCK_SIZE 2048
#define ARCHIVE_OK 0
#define ARCHIVE_FATAL -1
#define ARCHIVE_ERRNO_MISC (-1)
#define ARCHIVE_FORMAT_ISO9660_ROCKRIDGE 0

struct archive {
    int archive_format;
    char *archive_format_name;
};

struct archive_read {
    struct archive archive;
};

struct vd {
    int location;
    int size;
};

struct file_info;

struct iso9660 {
    struct vd primary;
    struct vd joliet;
    int opt_support_joliet;
    char seenJoliet;
    char seenRockridge;
    int64_t current_position;
};

int __archive_read_consume(struct archive_read *, int64_t);
const void *__archive_read_ahead(struct archive_read *, int, void *);
void archive_set_error(struct archive *, int, const char *);
struct file_info *parse_file_info(struct archive_read *, void *, const void *, ...);
int add_entry(struct archive_read *, struct iso9660 *, struct file_info *);