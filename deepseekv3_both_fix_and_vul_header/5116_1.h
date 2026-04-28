#include <stdint.h>

#define ARCHIVE_OK 0
#define ARCHIVE_FATAL 1
#define ARCHIVE_WARN 2
#define ARCHIVE_ERRNO_FILE_FORMAT 0

struct archive_read {
    struct {
        void *data;
    } *format;
    struct {
        int errno_file_format;
    } archive;
};

struct file_info {
    uint64_t ce_offset;
    uint64_t ce_size;
    uint64_t cl_offset;
    uint64_t rdev;
    uint32_t mode;
    uint32_t nlinks;
    uint32_t uid;
    uint32_t gid;
    uint32_t number;
    int re;
};

struct iso9660 {
    uint32_t logical_block_size;
    int seenRockridge;
    int seenSUSP;
};

static int register_CE(struct archive_read *a, int32_t location, struct file_info *file);
static void parse_rockridge_NM1(struct file_info *file, const unsigned char *data, int data_length);
static void parse_rockridge_SL1(struct file_info *file, const unsigned char *data, int data_length);
static void parse_rockridge_TF1(struct file_info *file, const unsigned char *data, int data_length);
static void parse_rockridge_ZF1(struct file_info *file, const unsigned char *data, int data_length);
static uint64_t toi(const unsigned char *p, int n);
static int32_t archive_le32dec(const unsigned char *p);
static void archive_set_error(void *archive, int errno_file_format, const char *msg);