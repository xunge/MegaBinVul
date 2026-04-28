#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <stddef.h>
#include <inttypes.h>
#include <sys/mman.h>

typedef uint64_t usec_t;

typedef struct sd_id128 {
    uint8_t bytes[16];
} sd_id128_t;

typedef struct MMapFileDescriptor MMapFileDescriptor;
typedef struct MMapCache MMapCache;

typedef struct Header {
    uint32_t compatible_flags;
    uint8_t reserved[0];
    uint64_t header_size;
    uint64_t tail_object_offset;
    uint64_t n_objects;
    uint64_t n_entries;
    uint64_t n_data;
    uint64_t n_fields;
    uint64_t n_tags;
    uint64_t n_entry_arrays;
    uint64_t entry_array_offset;
    uint64_t data_hash_table_offset;
    uint64_t data_hash_table_size;
    uint64_t field_hash_table_offset;
    uint64_t field_hash_table_size;
    uint64_t head_entry_seqnum;
    uint64_t head_entry_realtime;
    uint64_t tail_entry_seqnum;
    uint64_t tail_entry_realtime;
    uint64_t tail_entry_monotonic;
    sd_id128_t tail_entry_boot_id;
} Header;

typedef struct Object {
    struct {
        uint32_t type;
        uint32_t flags;
        uint64_t size;
    } object;
    union {
        struct {
            uint64_t seqnum;
            uint64_t monotonic;
            uint64_t realtime;
            sd_id128_t boot_id;
        } entry;
        struct {
            uint64_t seqnum;
            uint64_t epoch;
            uint8_t tag[32];
        } tag;
    };
} Object;

typedef struct JournalFile {
    int cache_fd;
    const char *path;
    struct stat last_stat;
    Header *header;
#if HAVE_GCRYPT
    uint64_t fss_start_usec;
    uint64_t fss_interval_usec;
    bool hmac_running;
    void *hmac;
#endif
} JournalFile;

#define USEC_INFINITY ((usec_t) -1)
#define HEADER_COMPATIBLE_SUPPORTED (0)
#define TAG_LENGTH (32)
#define HAVE_GCRYPT (0)

#define _cleanup_close_ 
#define _cleanup_fclose_ 

#define ALIGN64(x) (((x) + 7) & ~7)

#define JOURNAL_HEADER_SEALED(x) (0)
#define JOURNAL_HEADER_COMPRESSED_XZ(x) (0)
#define JOURNAL_HEADER_COMPRESSED_LZ4(x) (0)
#define JOURNAL_HEADER_COMPRESSED_ZSTD(x) (0)
#define JOURNAL_HEADER_CONTAINS(x, y) (0)
#define JOURNAL_HEADER_TAIL_ENTRY_BOOT_ID(x) (0)

#define OBJECT_UNUSED (0)
#define OBJECT_COMPRESSED_XZ (1 << 0)
#define OBJECT_COMPRESSED_LZ4 (1 << 1)
#define OBJECT_COMPRESSED_ZSTD (1 << 2)

enum {
    OBJECT_DATA,
    OBJECT_FIELD,
    OBJECT_ENTRY,
    OBJECT_DATA_HASH_TABLE,
    OBJECT_FIELD_HASH_TABLE,
    OBJECT_ENTRY_ARRAY,
    OBJECT_TAG
};

static inline bool sd_id128_equal(sd_id128_t a, sd_id128_t b) {
    return memcmp(&a, &b, sizeof(sd_id128_t)) == 0;
}

static inline uint64_t MAX(uint64_t a, uint64_t b) { return a > b ? a : b; }
static inline uint64_t MIN(uint64_t a, uint64_t b) { return a < b ? a : b; }