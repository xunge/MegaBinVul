#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

typedef char *flb_sds_t;

struct flb_time {
    struct timespec tm;
};

typedef struct msgpack_object {
    int type;
    union {
        struct {
            size_t size;
            struct msgpack_object *ptr;
        } array;
        struct {
            size_t size;
            struct {
                struct msgpack_object *key;
                struct msgpack_object *val;
            } *ptr;
        } map;
    } via;
} msgpack_object;

typedef struct {
    char *data;
    size_t size;
    size_t alloc;
} msgpack_sbuffer;

typedef struct {
    msgpack_sbuffer *data;
    void (*callback)(msgpack_sbuffer*, const char*, size_t);
} msgpack_packer;

typedef struct {
    msgpack_object data;
} msgpack_unpacked;

#define MSGPACK_UNPACK_SUCCESS 0
#define MSGPACK_OBJECT_ARRAY 1
#define MSGPACK_OBJECT_MAP 2
#define FLB_PACK_JSON_FORMAT_LINES 0
#define FLB_PACK_JSON_FORMAT_STREAM 1
#define FLB_PACK_JSON_FORMAT_JSON 2
#define FLB_PACK_JSON_DATE_DOUBLE 0
#define FLB_PACK_JSON_DATE_ISO8601 1
#define FLB_PACK_JSON_DATE_EPOCH 2
#define FLB_PACK_JSON_DATE_ISO8601_FMT "%Y-%m-%dT%H:%M:%S"

static void msgpack_sbuffer_write(msgpack_sbuffer *sbuf, const char *data, size_t len) {
    memcpy(sbuf->data + sbuf->size, data, len);
    sbuf->size += len;
}

extern int flb_mp_count(const char *data, uint64_t bytes);
extern flb_sds_t flb_sds_create_size(size_t size);
extern void flb_errno(void);
extern flb_sds_t flb_msgpack_raw_to_json_sds(const char *data, size_t bytes);
extern flb_sds_t flb_sds_cat(flb_sds_t s, const char *str, size_t len);
extern size_t flb_sds_len(flb_sds_t s);
extern void flb_sds_destroy(flb_sds_t s);
extern void flb_time_pop_from_msgpack(struct flb_time *tm, msgpack_unpacked *result, msgpack_object **obj);
extern double flb_time_to_double(struct flb_time *tm);
extern void msgpack_sbuffer_init(msgpack_sbuffer *sbuf);
extern void msgpack_packer_init(msgpack_packer *pk, msgpack_sbuffer *sbuf, void (*write)(msgpack_sbuffer*, const char*, size_t));
extern void msgpack_unpacked_init(msgpack_unpacked *result);
extern int msgpack_unpack_next(msgpack_unpacked *result, const char *data, size_t len, size_t *off);
extern void msgpack_unpacked_destroy(msgpack_unpacked *result);
extern void msgpack_pack_array(msgpack_packer *pk, unsigned int n);
extern void msgpack_pack_map(msgpack_packer *pk, unsigned int n);
extern void msgpack_pack_str(msgpack_packer *pk, size_t l);
extern void msgpack_pack_str_body(msgpack_packer *pk, const char *b, size_t l);
extern void msgpack_pack_double(msgpack_packer *pk, double d);
extern void msgpack_pack_uint64(msgpack_packer *pk, uint64_t d);
extern void msgpack_pack_object(msgpack_packer *pk, msgpack_object o);
extern void msgpack_sbuffer_destroy(msgpack_sbuffer *sbuf);
extern void msgpack_sbuffer_clear(msgpack_sbuffer *sbuf);