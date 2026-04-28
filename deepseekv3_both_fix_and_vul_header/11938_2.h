#include <sys/types.h>
#include <stddef.h>

struct archive_read;
struct archive_entry;

struct rar {
    size_t bytes_remaining;
    unsigned int main_flags;
    unsigned int file_flags;
    int filename_must_match;
    int has_endarc_header;
};

struct archive_format {
    void *data;
};

struct archive {
    int read_data_is_posix_read;
    size_t read_data_requested;
};

struct archive_read {
    struct archive_format *format;
    struct archive archive;
    struct archive_entry *entry;
};

#define MHD_VOLUME 0x0001
#define FHD_SPLIT_AFTER 0x0001
#define ARCHIVE_EOF 1
#define ARCHIVE_OK 0

const void *__archive_read_ahead(struct archive_read *, size_t, ssize_t *);
int archive_read_format_rar_read_header(struct archive_read *, struct archive_entry *);