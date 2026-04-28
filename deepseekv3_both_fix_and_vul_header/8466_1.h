#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define kNumUnPackStream 0
#define kSize 1
#define kCRC 2
#define kEnd 3
#define UMAX_ENTRY SIZE_MAX

struct _7z_substream_info {
    size_t unpack_streams;
    uint64_t *unpackSizes;
    unsigned char *digestsDefined;
    uint32_t *digests;
};

struct _7z_folder {
    size_t numUnpackStreams;
    int digest_defined;
    uint32_t digest;
};

struct _7z_digests {
    unsigned char *defineds;
    uint32_t *digests;
};

struct archive_read;

static const unsigned char *header_bytes(struct archive_read *a, size_t bytes);
static int parse_7zip_uint64(struct archive_read *a, uint64_t *val);
static uint64_t folder_uncompressed_size(struct _7z_folder *f);
static int read_Digests(struct archive_read *a, struct _7z_digests *d, uint32_t num);
static void free_Digest(struct _7z_digests *d);