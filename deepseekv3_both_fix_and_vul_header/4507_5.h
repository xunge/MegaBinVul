#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ARCHIVE_OK 0
#define ARCHIVE_WARN 1
#define ARCHIVE_FATAL 2
#define ARCHIVE_ERRNO_FILE_FORMAT (-1)
#define ARCHIVE_ERRNO_MISC (-2)
#define ENOMEM 12
#define SEEK_SET 0

struct archive_format {
    void *data;
};

struct archive {
    struct archive_format *format;
};

struct archive_entry;

struct archive_read {
    struct archive archive;
    struct archive_format *format;
};

struct zip {
    void *data;
    int decompress_init;
#ifdef HAVE_ZLIB_H
    struct {
        void *next_in;
        unsigned int avail_in;
        unsigned long total_in;
        void *next_out;
        unsigned int avail_out;
        unsigned long total_out;
    } stream;
#endif
};

struct zip_entry {
    int compression;
    int64_t uncompressed_size;
    int64_t compressed_size;
    int64_t local_header_offset;
};

static int64_t archive_filter_bytes(struct archive *a, int n) { return 0; }
static void archive_set_error(struct archive *a, int err, const char *fmt, ...) {}
static void __archive_read_consume(struct archive_read *a, size_t n) {}
static void __archive_read_seek(struct archive_read *a, int64_t offset, int whence) {}
static const unsigned char *__archive_read_ahead(struct archive_read *a, int n, ssize_t *avail) { return NULL; }
static void archive_entry_copy_mac_metadata(struct archive_entry *entry, const void *p, size_t s) {}
static ssize_t zip_get_local_file_header_size(struct archive_read *a, int n) { return 0; }
static int zip_deflate_init(struct archive_read *a, struct zip *zip) { return ARCHIVE_OK; }
static const char *compression_name(int compression) { return "Unknown"; }