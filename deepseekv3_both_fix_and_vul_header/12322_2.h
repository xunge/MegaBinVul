#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define UMAX_ENTRY 0xFFFFFFFF
#define UBUFF_SIZE 1024
#define AE_IFMT 0170000
#define AE_IFDIR 0040000
#define AE_IFREG 0100000
#define HAS_STREAM 0x01
#define CRC32_IS_SET 0x02

#define kHeader 0x01
#define kArchiveProperties 0x02
#define kMainStreamsInfo 0x03
#define kEnd 0x04
#define kFilesInfo 0x05
#define kEmptyStream 0x06
#define kEmptyFile 0x07
#define kAnti 0x08
#define kCTime 0x09
#define kATime 0x0A
#define kMTime 0x0B
#define kName 0x0C
#define kAttributes 0x0D
#define kDummy 0x0E

struct archive_read {
    struct {
        void *data;
    } *format;
};

struct _7z_stream_info {
    struct {
        struct _7z_folder *folders;
        uint32_t numFolders;
    } ci;
    struct {
        uint32_t unpack_streams;
        unsigned char *digestsDefined;
    } ss;
};

struct _7z_folder {
    uint32_t numUnpackStreams;
};

struct _7zip {
    struct _7z_stream_info si;
    uint64_t numFiles;
    struct _7zip_entry *entries;
    unsigned char *entry_names;
    size_t header_bytes_remaining;
};

struct _7zip_entry {
    unsigned char *utf16name;
    size_t name_len;
    uint32_t attr;
    uint32_t mode;
    int flg;
    int ssIndex;
    int folderIndex;
};

struct _7z_header_info {
    unsigned char *emptyStreamBools;
    unsigned char *emptyFileBools;
    unsigned char *antiBools;
    unsigned char *attrBools;
};

static inline uint32_t archive_le32dec(const unsigned char *p) {
    return ((uint32_t)p[0]) | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static const unsigned char *header_bytes(struct archive_read *a, size_t bytes);
static int parse_7zip_uint64(struct archive_read *a, uint64_t *val);
static int read_Bools(struct archive_read *a, unsigned char *bools, size_t num);
static int read_Times(struct archive_read *a, struct _7z_header_info *h, int type);
static int read_StreamsInfo(struct archive_read *a, struct _7z_stream_info *si);