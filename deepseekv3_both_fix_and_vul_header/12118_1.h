#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_COMP_SIZE 32
#define SIZE_MAX ULONG_MAX

#define VALIDATE_READ_BOOL(zck)
#define ZCK_LOG_ERROR 1
#define ZCK_LOG_DEBUG 2

typedef struct {
    int digest_size;
} HashType;

typedef struct zckCtx {
    HashType hash_type;
    int prep_hash_type;
    size_t header_length;
    size_t hdr_digest_loc;
    char *header_digest;
    char *header;
    size_t header_size;
    char *lead_string;
    size_t lead_size;
    bool header_only;
    char *prep_digest;
    int prep_hdr_size;
} zckCtx;

void zck_log(int level, const char *format, ...);
void *zmalloc(size_t size);
void *zrealloc(void *ptr, size_t size);
ssize_t read_data(zckCtx *zck, void *buf, size_t count);
bool compint_to_int(zckCtx *zck, int *out, const char *buf, size_t *pos, size_t max);
bool compint_to_size(zckCtx *zck, size_t *out, const char *buf, size_t *pos, size_t max);
bool hash_setup(zckCtx *zck, HashType *hash, int type);
void hash_reset(HashType *hash);
void set_error(zckCtx *zck, const char *msg, ...);
const char *zck_hash_name_from_type(int type);
char *get_digest_string(const char *digest, size_t size);