#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

struct archive_entry;

struct archive {
    int archive;
};

struct archive_read {
    struct archive archive;
};

struct rar5 {
    struct {
        int split_after;
        int split_before;
        int size;
        int last_header_id;
        int endarc;
        int volume;
        int vol_no;
    } generic;
    struct {
        int endarc;
        int volume;
        int vol_no;
    } main;
    struct {
        unsigned int expected_vol_no;
    } vol;
};

#define ARCHIVE_OK 0
#define ARCHIVE_EOF 1
#define ARCHIVE_FATAL 2
#define ARCHIVE_RETRY 3
#define ARCHIVE_ERRNO_FILE_FORMAT 4
#define ARCHIVE_ERRNO_PROGRAMMER 5

#define HFL_SPLIT_AFTER (1 << 0)
#define HFL_SPLIT_BEFORE (1 << 1)
#define HFL_SKIP_IF_UNKNOWN (1 << 2)

static uint32_t crc32(uint32_t crc, const void *buf, size_t size) {
    return 0;
}

static int skip_unprocessed_bytes(struct archive_read* a) {
    return ARCHIVE_OK;
}

static int read_u32(struct archive_read* a, uint32_t* val) {
    return 1;
}

static int read_var_sized(struct archive_read* a, size_t* val, size_t* len) {
    return 1;
}

static int read_ahead(struct archive_read* a, size_t size, const uint8_t** p) {
    return 1;
}

static int consume(struct archive_read* a, size_t len) {
    return ARCHIVE_OK;
}

static int scan_for_signature(struct archive_read* a) {
    return ARCHIVE_OK;
}

static int process_head_main(struct archive_read* a, struct rar5* rar, struct archive_entry* entry, size_t flags) {
    return ARCHIVE_OK;
}

static int process_head_service(struct archive_read* a, struct rar5* rar, struct archive_entry* entry, size_t flags) {
    return ARCHIVE_OK;
}

static int process_head_file(struct archive_read* a, struct rar5* rar, struct archive_entry* entry, size_t flags) {
    return ARCHIVE_OK;
}

static void archive_set_error(struct archive* a, int err, const char* fmt, ...) {
}

static struct rar5* get_context(struct archive_read* a) {
    static struct rar5 r;
    return &r;
}