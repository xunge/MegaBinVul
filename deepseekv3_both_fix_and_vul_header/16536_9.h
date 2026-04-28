#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

typedef char *flb_sds_t;

struct flb_avro_fields {
    char *schema_id;
    flb_sds_t schema_str;
};

struct msgpack_object {
    int type;
    void *ptr;
};

struct msgpack_unpacked {
    struct msgpack_object data;
};

typedef struct msgpack_object msgpack_object;
typedef struct msgpack_unpacked msgpack_unpacked;

typedef void *avro_writer_t;
typedef void *avro_value_t;
typedef void *avro_value_iface_t;
typedef void *avro_schema_t;

#define MSGPACK_UNPACK_SUCCESS 0
#define FLB_TRUE 1
#define FLB_FALSE 0

size_t flb_sds_len(flb_sds_t s);
flb_sds_t flb_sds_create_len(const char *str, size_t len);
size_t flb_sds_alloc(flb_sds_t s);
size_t flb_sds_avail(flb_sds_t s);
void *flb_malloc(size_t size);
void flb_free(void *ptr);
void flb_debug(const char *fmt, ...);
void flb_error(const char *fmt, ...);
int flb_errno(void);
const char *avro_strerror(void);
void msgpack_unpacked_init(msgpack_unpacked *result);
int msgpack_unpack_next(msgpack_unpacked *result, const void *buf, size_t len, size_t *off);
void msgpack_unpacked_destroy(msgpack_unpacked *result);
avro_value_iface_t *flb_avro_init(avro_value_t *val, char *schema_str, size_t schema_len, avro_schema_t *schema);
int flb_msgpack_to_avro(avro_value_t *avro_val, msgpack_object *obj);
avro_writer_t avro_writer_memory(char *buf, size_t len);
void avro_writer_free(avro_writer_t writer);
void avro_writer_flush(avro_writer_t writer);
int64_t avro_writer_tell(avro_writer_t writer);
int avro_write(avro_writer_t writer, const void *buf, size_t len);
int avro_value_write(avro_writer_t writer, avro_value_t *val);
void avro_value_decref(avro_value_t *val);
void avro_value_iface_decref(avro_value_iface_t *iface);
void avro_schema_decref(avro_schema_t schema);