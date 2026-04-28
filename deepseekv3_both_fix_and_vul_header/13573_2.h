#include <assert.h>
#include <endian.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define TAG_LENGTH 32
#define OBJECT_TAG 1

typedef struct {
    uint32_t flags;
} JournalHeader;

typedef struct JournalFile {
    JournalHeader header;
    bool hmac_running;
    void *hmac;
    void *fsprg_state;
} JournalFile;

typedef struct TagObject {
    uint64_t seqnum;
    uint64_t epoch;
    uint8_t tag[TAG_LENGTH];
} TagObject;

typedef struct Object {
    TagObject tag;
} Object;

#define JOURNAL_HEADER_SEALED(header) ((header).flags & 1)

uint64_t journal_file_tag_seqnum(JournalFile *f);
int journal_file_append_object(JournalFile *f, int type, size_t size, Object **o, uint64_t *p);
int journal_file_hmac_put_object(JournalFile *f, int type, Object *o, uint64_t p);
void *gcry_md_read(void *hmac, int algo);
uint64_t FSPRG_GetEpoch(void *state);
uint64_t le64toh(uint64_t value);
uint64_t htole64(uint64_t value);
void log_debug(const char *format, ...);