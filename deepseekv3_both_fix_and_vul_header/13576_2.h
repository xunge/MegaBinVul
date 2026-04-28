#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <stddef.h>

#define HEADER_COMPATIBLE_ANY 0xFFFFFFFF
#define HEADER_INCOMPATIBLE_ANY 0xFFFFFFFF
#define HEADER_COMPATIBLE_SUPPORTED 0x0
#define HEADER_INCOMPATIBLE_SUPPORTED 0x0
#define HEADER_COMPATIBLE_SEALED 0x1
#define HEADER_COMPATIBLE_SEALED_CONTINUOUS 0x2
#define HEADER_INCOMPATIBLE_COMPRESSED_XZ 0x1
#define HEADER_INCOMPATIBLE_COMPRESSED_LZ4 0x2
#define HEADER_INCOMPATIBLE_COMPRESSED_ZSTD 0x4
#define HEADER_INCOMPATIBLE_KEYED_HASH 0x8
#define HEADER_INCOMPATIBLE_COMPACT 0x10

#define ELEMENTSOF(arr) (sizeof(arr)/sizeof((arr)[0]))

typedef struct JournalHeader {
    uint32_t compatible_flags;
    uint32_t incompatible_flags;
} JournalHeader;

typedef struct JournalFile {
    const char *path;
    JournalHeader *header;
} JournalFile;

static inline uint32_t le32toh(uint32_t v) { return v; }

char *strv_join(char **strv, const char *separator);
void log_debug(const char *format, ...);
const char *strnull(const char *s);

#define _cleanup_free_ __attribute__((cleanup(freep)))
void freep(void *p);