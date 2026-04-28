#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

#define INDEX_VERSION_NUMBER_COMP 2
#define INDEX_FOOTER_SIZE 20
#define GIT_IDXENTRY_EXTENDED 0x4000
#define GIT_IDXENTRY_NAMEMASK 0x0fff
#define minimal_entry_size sizeof(struct entry_short)

typedef int32_t git_time_t;

struct git_time {
    git_time_t seconds;
    uint32_t nanoseconds;
};

typedef struct {
    unsigned char id[20];
} git_oid;

typedef struct git_index_entry {
    struct git_time ctime;
    struct git_time mtime;
    uint32_t dev;
    uint32_t ino;
    uint32_t mode;
    uint32_t uid;
    uint32_t gid;
    uint32_t file_size;
    git_oid id;
    uint16_t flags;
    uint16_t flags_extended;
    char *path;
} git_index_entry;

typedef struct git_index {
    unsigned int version;
} git_index;

struct entry_short {
    struct git_time ctime;
    struct git_time mtime;
    uint32_t dev;
    uint32_t ino;
    uint32_t mode;
    uint32_t uid;
    uint32_t gid;
    uint32_t file_size;
    git_oid oid;
    uint16_t flags;
    char path[1];
};

struct entry_long {
    struct git_time ctime;
    struct git_time mtime;
    uint32_t dev;
    uint32_t ino;
    uint32_t mode;
    uint32_t uid;
    uint32_t gid;
    uint32_t file_size;
    git_oid oid;
    uint16_t flags;
    uint16_t flags_extended;
    char path[1];
};

static inline void git_oid_cpy(git_oid *dst, const git_oid *src) {
    memcpy(dst, src, sizeof(*dst));
}

static size_t git_decode_varint(const unsigned char *buf, size_t *varint_len);
static int index_entry_dup(git_index_entry **out, git_index *index, const git_index_entry *entry);
static size_t index_entry_size(size_t path_length, size_t varint_len, uint16_t flags);
static int index_error_invalid(const char *message);
static void *git__malloc(size_t size);
static void git__free(void *ptr);

#define GITERR_CHECK_ALLOC(ptr) if (!(ptr)) return -1
#define GITERR_CHECK_ALLOC_ADD(out, a, b) \
    do { \
        if ((a) > SIZE_MAX - (b)) return -1; \
        *(out) = (a) + (b); \
    } while (0)