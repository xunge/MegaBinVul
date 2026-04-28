#include <sys/types.h>
#include <stddef.h>

#define _7Z_COPY 0
#define ARCHIVE_FATAL -1
#define ARCHIVE_ERRNO_FILE_FORMAT 1
#define ARCHIVE_ERRNO_MISC 2

struct _7zip {
    unsigned long codec;
    unsigned long codec2;
    size_t uncompressed_buffer_bytes_remaining;
    const void *uncompressed_buffer_pointer;
    size_t pack_stream_bytes_unconsumed;
};

struct archive {
    int dummy;
};

struct archive_format_descriptor {
    void *data;
};

struct archive_read {
    struct archive archive;
    struct archive_format_descriptor *format;
};

void *__archive_read_ahead(struct archive_read *, size_t, ssize_t *);
int extract_pack_stream(struct archive_read *, size_t);
void archive_set_error(struct archive *, int, const char *);