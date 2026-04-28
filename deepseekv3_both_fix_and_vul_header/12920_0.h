#include <stdlib.h>

struct archive;
struct archive_write;
struct archive_write_filter {
    struct archive *archive;
    int state;
    struct archive_write_filter *next_filter;
};

#define ARCHIVE_WRITE_FILTER_STATE_NEW 0

struct archive_write {
    struct archive_write_filter *filter_first;
    struct archive_write_filter *filter_last;
};