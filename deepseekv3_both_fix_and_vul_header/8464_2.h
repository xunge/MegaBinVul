#include <sys/types.h>
#include <stddef.h>

struct archive_read_filter_bidder;
struct archive_read_filter;

extern const unsigned char *__archive_read_filter_ahead(struct archive_read_filter *, size_t, ssize_t *);