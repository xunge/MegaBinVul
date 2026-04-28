#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <time.h>

typedef char *flb_sds_t;

struct flb_time {
    struct timespec tm;
};

struct flb_gelf_fields {
    flb_sds_t host_key;
    flb_sds_t timestamp_key;
    flb_sds_t level_key;
    flb_sds_t short_message_key;
    flb_sds_t full_message_key;
};

enum {
    FLB_FALSE = 0,
    FLB_TRUE = 1
};

typedef struct msgpack_object {
    int type;
    union {
        uint64_t u64;
        int64_t i64;
        double f64;
        struct {
            const char *ptr;
            uint32_t size;
        } str;
        struct {
            const char *ptr;
            uint32_t size;
        } bin;
        struct {
            const char *ptr;
            uint32_t size;
        } ext;
        struct {
            uint32_t size;
            struct msgpack_object_kv *ptr;
        } map;
        struct {
            uint32_t size;
            struct msgpack_object *ptr;
        } array;
        bool boolean;
    } via;
} msgpack_object;

typedef struct msgpack_object_kv {
    msgpack_object key;
    msgpack_object val;
} msgpack_object_kv;

#define MSGPACK_OBJECT_NIL 0
#define MSGPACK_OBJECT_BOOLEAN 1
#define MSGPACK_OBJECT_POSITIVE_INTEGER 2
#define MSGPACK_OBJECT_NEGATIVE_INTEGER 3
#define MSGPACK_OBJECT_FLOAT 4
#define MSGPACK_OBJECT_STR 5
#define MSGPACK_OBJECT_BIN 6
#define MSGPACK_OBJECT_ARRAY 7
#define MSGPACK_OBJECT_MAP 8
#define MSGPACK_OBJECT_EXT 9

extern flb_sds_t flb_sds_cat(flb_sds_t s, const char *str, size_t len);
extern size_t flb_sds_len(flb_sds_t s);
extern flb_sds_t flb_sds_printf(flb_sds_t *s, const char *fmt, ...);
extern void *flb_calloc(size_t n, size_t size);
extern void flb_free(void *ptr);
extern flb_sds_t flb_msgpack_gelf_flatten(flb_sds_t *s, msgpack_object *o, char *prefix, int prefix_len, int quote);
extern flb_sds_t flb_msgpack_gelf_key(flb_sds_t *s, int quote, const char *prefix, int prefix_len, int custom, const char *key, int key_len);
extern flb_sds_t flb_msgpack_gelf_value(flb_sds_t *s, int quote, const char *val, int val_len);
extern flb_sds_t flb_msgpack_gelf_value_ext(flb_sds_t *s, int quote, const char *val, int val_len);
extern void flb_warn(const char *fmt, ...);
extern void flb_error(const char *fmt, ...);