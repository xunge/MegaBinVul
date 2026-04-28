#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>
#include <assert.h>
#include <inttypes.h>
#include <unistd.h>

typedef struct {
    uint8_t id[16];
} sd_id128_t;

typedef struct {
    uint32_t compatible_flags;
    uint32_t incompatible_flags;
    uint64_t header_size;
    uint64_t arena_size;
    uint64_t data_hash_table_size;
    uint64_t field_hash_table_size;
    uint64_t head_entry_seqnum;
    uint64_t tail_entry_seqnum;
    uint64_t head_entry_realtime;
    uint64_t tail_entry_realtime;
    uint64_t tail_entry_monotonic;
    uint64_t n_objects;
    uint64_t n_entries;
    uint64_t n_data;
    uint64_t n_fields;
    uint64_t n_tags;
    uint64_t n_entry_arrays;
    uint64_t field_hash_chain_depth;
    uint64_t data_hash_chain_depth;
    sd_id128_t file_id;
    sd_id128_t machine_id;
    sd_id128_t tail_entry_boot_id;
    sd_id128_t seqnum_id;
    int state;
} JournalHeader;

typedef struct {
    JournalHeader *header;
    char *path;
    int fd;
} JournalFile;

typedef struct {
    uint64_t key;
    uint64_t next_offset;
    uint64_t hash;
} HashItem;

#define STATE_OFFLINE 0
#define STATE_ONLINE 1
#define STATE_ARCHIVED 2
#define HEADER_COMPATIBLE_ANY 0
#define HEADER_INCOMPATIBLE_ANY 0
#define LOG_DEBUG 0
#define USEC_PER_MSEC 1000

#define SD_ID128_TO_STRING(id) "id-string"
#define JOURNAL_HEADER_SEALED(h) 0
#define JOURNAL_HEADER_TAIL_ENTRY_BOOT_ID(h) 0
#define JOURNAL_HEADER_COMPRESSED_XZ(h) 0
#define JOURNAL_HEADER_COMPRESSED_LZ4(h) 0
#define JOURNAL_HEADER_COMPRESSED_ZSTD(h) 0
#define JOURNAL_HEADER_KEYED_HASH(h) 0
#define JOURNAL_HEADER_COMPACT(h) 0
#define JOURNAL_HEADER_CONTAINS(h, field) 0
#define FORMAT_TIMESTAMP_SAFE(t) "timestamp"
#define FORMAT_TIMESPAN(t, u) "timespan"
#define FORMAT_BYTES(b) "bytes"
#define yes_no(b) ((b) ? "yes" : "no")

static inline uint32_t le32toh(uint32_t v) { return v; }
static inline uint64_t le64toh(uint64_t v) { return v; }

static int journal_file_rotate_suggested(JournalFile *f, int unused1, int unused2) { return 0; }