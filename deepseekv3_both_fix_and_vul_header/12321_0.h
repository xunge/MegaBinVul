#include <sys/types.h>
#include <stddef.h>

struct archive_read;

ssize_t get_line_size(const char *b, ssize_t avail, ssize_t *nl);
const char *__archive_read_ahead(struct archive_read *a, size_t nbytes_req, ssize_t *avail);