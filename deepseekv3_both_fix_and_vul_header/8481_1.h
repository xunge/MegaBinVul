#include <stdlib.h>

#define ARCHIVE_OK 0
#define ARCHIVE_FATAL 1
#define ARCHIVE_ERRNO_FILE_FORMAT 0

struct archive_read_filter_bidder {
    int (*bid)(struct archive_read_filter_bidder *, struct archive_read_filter *);
    int (*init)(struct archive_read_filter *);
};

struct archive_read_filter {
    struct archive_read_filter_bidder *bidder;
    struct archive_read *archive;
    struct archive_read_filter *upstream;
    const char *name;
    int code;
};

struct archive {
    const char *compression_name;
    int compression_code;
};

struct archive_read {
    struct archive_read_filter_bidder bidders[1];
    struct archive_read_filter *filter;
    struct archive archive;
};

ssize_t __archive_read_filter_ahead(struct archive_read_filter *, int, ssize_t *);
void __archive_read_close_filters(struct archive_read *);
void __archive_read_free_filters(struct archive_read *);
void archive_set_error(struct archive *, int, const char *);