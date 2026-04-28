#include <stddef.h>
#include <stdint.h>

struct archive_read {
    struct {
        void *data;
    } *format;
    struct {
        int archive;
    } archive;
};

struct rar {
    int has_encrypted_entries;
    size_t bytes_unconsumed;
    int entry_eof;
    int64_t offset_seek;
    int64_t unp_size;
    int64_t offset;
    int compression_method;
    int start_new_table;
    void *ppmd7_context;
};

struct {
    void (*Ppmd7_Free)(void *);
} __archive_ppmd7_functions;

#define ARCHIVE_READ_FORMAT_ENCRYPTION_DONT_KNOW 0
#define ARCHIVE_EOF 1
#define ARCHIVE_OK 0
#define ARCHIVE_WARN 1
#define ARCHIVE_FATAL 2
#define ARCHIVE_ERRNO_FILE_FORMAT 0

enum {
    COMPRESS_METHOD_STORE,
    COMPRESS_METHOD_FASTEST,
    COMPRESS_METHOD_FAST,
    COMPRESS_METHOD_NORMAL,
    COMPRESS_METHOD_GOOD,
    COMPRESS_METHOD_BEST
};

int __archive_read_consume(struct archive_read *, size_t);
int read_data_stored(struct archive_read *, const void **, size_t *, int64_t *);
int read_data_compressed(struct archive_read *, const void **, size_t *, int64_t *);
void archive_set_error(void *, int, const char *);