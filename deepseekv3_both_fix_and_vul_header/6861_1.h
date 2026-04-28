#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>

struct archive_read {
    struct {
        struct warc_s *data;
    } *format;
};

struct warc_s {
    int64_t cntoff;
    int64_t cntlen;
    size_t unconsumed;
};

#define ARCHIVE_EOF 1
#define ARCHIVE_OK 0

extern const char *__archive_read_ahead(struct archive_read *, size_t, ssize_t *);