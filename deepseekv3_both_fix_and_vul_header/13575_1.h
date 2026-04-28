#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <endian.h>
#include <assert.h>

typedef struct {
    uint8_t bytes[16];
} sd_id128_t;

typedef struct Header {
    uint8_t signature[8];
    sd_id128_t file_id;
    sd_id128_t machine_id;
    sd_id128_t seqnum_id;
    uint64_t header_size;
    uint32_t incompatible_flags;
    uint32_t compatible_flags;
    uint64_t tail_entry_seqnum;
} Header;

typedef struct JournalFile {
    int fd;
    Header *header;
} JournalFile;

typedef uint64_t JournalFileFlags;

#define HAVE_GCRYPT 1
#define JOURNAL_SEAL (1 << 0)
#define JOURNAL_COMPRESS (1 << 1)
#define HEADER_INCOMPATIBLE_KEYED_HASH (1 << 0)
#define HEADER_INCOMPATIBLE_COMPACT (1 << 1)
#define HEADER_COMPATIBLE_SEALED (1 << 0)
#define HEADER_COMPATIBLE_SEALED_CONTINUOUS (1 << 2)
#define HEADER_COMPATIBLE_TAIL_ENTRY_BOOT_ID (1 << 1)
static const char HEADER_SIGNATURE[8] = {'L','P','K','S','H','H','R','H'};

#define FLAGS_SET(flags, mask) ((flags) & (mask))
#define ALIGN64(x) (((x) + 63) & ~63)
#define ERRNO_IS_MACHINE_ID_UNSET(e) ((e) == ENOMEDIUM || (e) == ENOENT)
#define COMPRESSION_TO_HEADER_INCOMPATIBLE_FLAG(x) (x)
#define assert_cc(expr) _Static_assert(expr, #expr)

static int compression_requested(void) { return 0; }
static bool keyed_hash_requested(void) { return false; }
static bool compact_mode_requested(void) { return false; }
static int journal_file_fss_load(JournalFile *f) { return -1; }
static int sd_id128_randomize(sd_id128_t *id) { return 0; }
static int sd_id128_get_machine(sd_id128_t *id) { return 0; }