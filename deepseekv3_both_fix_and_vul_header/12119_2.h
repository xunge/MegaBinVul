#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

#define ZCK_LOG_ERROR 1
#define ZCK_LOG_DEBUG 2

typedef struct zckHash zckHash;

typedef struct zckCtx {
    size_t lead_size;
    size_t header_length;
    size_t header_size;
    size_t hdr_digest_loc;
    char *header;
    char *lead_string;
    zckHash *check_full_hash;
    int hash_type;
} zckCtx;

extern void set_error(zckCtx *zck, const char *msg);
extern void set_fatal_error(zckCtx *zck, const char *msg, ...);
extern void *zrealloc(void *ptr, size_t size);
extern void zck_log(int level, const char *format, ...);
extern ssize_t read_data(zckCtx *zck, void *buf, size_t len);
extern bool hash_init(zckCtx *zck, zckHash **hash, int *type);
extern bool hash_update(zckCtx *zck, zckHash *hash, const void *data, size_t len);
extern int validate_header(zckCtx *zck);