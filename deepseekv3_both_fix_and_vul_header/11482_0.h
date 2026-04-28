#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef enum {
   BSON_TYPE_EOD = 0x00,
   BSON_TYPE_DOUBLE = 0x01,
   BSON_TYPE_UTF8 = 0x02,
   BSON_TYPE_DOCUMENT = 0x03,
   BSON_TYPE_ARRAY = 0x04,
   BSON_TYPE_BINARY = 0x05,
   BSON_TYPE_UNDEFINED = 0x06,
   BSON_TYPE_OID = 0x07,
   BSON_TYPE_BOOL = 0x08,
   BSON_TYPE_DATE_TIME = 0x09,
   BSON_TYPE_NULL = 0x0A,
   BSON_TYPE_REGEX = 0x0B,
   BSON_TYPE_DBPOINTER = 0x0C,
   BSON_TYPE_CODE = 0x0D,
   BSON_TYPE_SYMBOL = 0x0E,
   BSON_TYPE_CODEWSCOPE = 0x0F,
   BSON_TYPE_INT32 = 0x10,
   BSON_TYPE_TIMESTAMP = 0x11,
   BSON_TYPE_INT64 = 0x12,
   BSON_TYPE_DECIMAL128 = 0x13,
   BSON_TYPE_MINKEY = 0xFF,
   BSON_TYPE_MAXKEY = 0x7F
} bson_type_t;

typedef enum {
   BSON_SUBTYPE_BINARY = 0x00,
   BSON_SUBTYPE_FUNCTION = 0x01,
   BSON_SUBTYPE_BINARY_DEPRECATED = 0x02,
   BSON_SUBTYPE_UUID_DEPRECATED = 0x03,
   BSON_SUBTYPE_UUID = 0x04,
   BSON_SUBTYPE_MD5 = 0x05,
   BSON_SUBTYPE_USER = 0x80
} bson_subtype_t;

typedef struct {
   const uint8_t *raw;
   uint32_t len;
   uint32_t off;
   uint32_t type;
   uint32_t key;
   uint32_t d1;
   uint32_t d2;
   uint32_t d3;
   uint32_t d4;
   uint32_t next_off;
   uint32_t err_off;
} bson_iter_t;

#define BSON_ASSERT(expr) ((void)0)
#define BSON_UINT32_FROM_LE(val) (val)
#define BSON_UNLIKELY(expr) (expr)
#define ITER_TYPE(iter) ((iter)->type)

static const char *bson_iter_key_unsafe(const bson_iter_t *iter);