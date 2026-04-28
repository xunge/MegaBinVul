#include <stdlib.h>
#include <errno.h>

#define ARCHIVE_FILTER_COMPRESS 0
#define ARCHIVE_OK 0
#define ARCHIVE_FATAL 1

struct archive {
    int dummy;
};

struct archive_read_filter {
    int code;
    const char *name;
    void *data;
    struct {
        struct archive archive;
    } *archive;
    int (*read)(struct archive_read_filter *, const void **);
    void (*skip)(struct archive_read_filter *, int64_t);
    int (*close)(struct archive_read_filter *);
};

struct private_data {
    size_t out_block_size;
    void *out_block;
    int maxcode_bits;
    int maxcode;
    int use_reset_code;
    int free_ent;
    unsigned char *stackp;
    unsigned char stack[8192];
    int bits;
    int section_end_code;
    int oldcode;
    unsigned short prefix[65536];
    unsigned char suffix[65536];
};

void archive_set_error(struct archive *, int, const char *, ...);
int getbits(struct archive_read_filter *, int);
void next_code(struct archive_read_filter *);
int compress_filter_read(struct archive_read_filter *, const void **);
int compress_filter_close(struct archive_read_filter *);