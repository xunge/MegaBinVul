#include <stddef.h>
#include <stdint.h>
#include <time.h>

#define H1_FIXED_SIZE 22
#define H1_HEADER_SIZE_OFFSET 0
#define H1_HEADER_SUM_OFFSET 1
#define H1_COMP_SIZE_OFFSET 2
#define H1_ORIG_SIZE_OFFSET 6
#define H1_DOS_TIME_OFFSET 10
#define H1_NAME_LEN_OFFSET 21
#define H1_FILE_NAME_OFFSET 22

#define ARCHIVE_OK 0
#define ARCHIVE_WARN 1
#define ARCHIVE_ERRNO_MISC 1
#define ARCHIVE_FATAL 2
#define ARCHIVE_ERRNO_FILE_FORMAT 1

#define CRC_IS_SET 1

struct archive_read {
    struct archive *archive;
};

struct archive {
    int dummy;
};

struct lha {
    size_t header_size;
    size_t compsize;
    size_t origsize;
    time_t mtime;
    struct {
        char *s;
        size_t length;
        size_t buffer_length;
    } filename;
    uint16_t crc;
    int setflag;
};

static int truncated_error(struct archive_read *a);
static time_t lha_dos_time(const unsigned char *p);
static unsigned char lha_calcsum(unsigned char sum, const unsigned char *p, size_t offset, size_t size);
static int lha_read_file_extended_header(struct archive_read *a, struct lha *lha, void *extd, int extdsize, size_t compsize, size_t *extdsize_out);
static void archive_strncpy(struct { char *s; size_t length; size_t buffer_length; } *as, const char *p, size_t n);
static uint32_t archive_le32dec(const unsigned char *p);
static uint16_t archive_le16dec(const unsigned char *p);
static const unsigned char *__archive_read_ahead(struct archive_read *a, size_t size, size_t *avail);
static void __archive_read_consume(struct archive_read *a, size_t size);
static void archive_set_error(struct archive *a, int error, const char *fmt, ...);