#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct archive_entry;
struct archive_string_conv;
struct archive_format {
    void *data;
};
struct archive {
    int dummy;
};
struct archive_read {
    struct archive_format *format;
    struct archive archive;
};
struct cpio {
    struct archive_string_conv *opt_sconv;
    struct archive_string_conv *sconv_default;
    int init_default_conversion;
    int (*read_header)(struct archive_read *, struct cpio *, struct archive_entry *, size_t *, size_t *);
    size_t entry_offset;
    size_t entry_bytes_remaining;
};

#define ARCHIVE_WARN 0
#define ARCHIVE_FATAL 1
#define ARCHIVE_EOF 2
#define ARCHIVE_OK 0
#define ARCHIVE_ERRNO_FILE_FORMAT 0
#define AE_IFLNK 0120000

const void *__archive_read_ahead(struct archive_read *, size_t, void *);
void __archive_read_consume(struct archive_read *, size_t);
int archive_entry_copy_pathname_l(struct archive_entry *, const char *, size_t, struct archive_string_conv *);
int archive_entry_copy_symlink_l(struct archive_entry *, const char *, size_t, struct archive_string_conv *);
int archive_entry_filetype(struct archive_entry *);
void archive_set_error(struct archive *, int, const char *, ...);
void archive_clear_error(struct archive *);
struct archive_string_conv *archive_string_default_conversion_for_read(struct archive *);
const char *archive_string_conversion_charset_name(struct archive_string_conv *);
int record_hardlink(struct archive_read *, struct cpio *, struct archive_entry *);