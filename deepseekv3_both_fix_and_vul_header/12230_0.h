#include <stdbool.h>
#include <stdint.h>

typedef uint8_t uint8;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int32_t int32;
typedef int64_t int64;
typedef float float32;
typedef double float64;

#define CHECK_BUF(p, end, size) \
    do { if ((p) + (size) > (end)) goto fail; } while (0)

#define NULL_REF 0

enum {
    INIT_EXPR_TYPE_I32_CONST,
    INIT_EXPR_TYPE_I64_CONST,
    INIT_EXPR_TYPE_F32_CONST,
    INIT_EXPR_TYPE_F64_CONST,
    INIT_EXPR_TYPE_V128_CONST,
    INIT_EXPR_TYPE_FUNCREF_CONST,
    INIT_EXPR_TYPE_REFNULL_CONST,
    INIT_EXPR_TYPE_GET_GLOBAL
};

enum {
    VALUE_TYPE_I32,
    VALUE_TYPE_I64,
    VALUE_TYPE_F32,
    VALUE_TYPE_F64,
    VALUE_TYPE_V128,
    VALUE_TYPE_FUNCREF
};

typedef union {
    int32 i32;
    int64 i64;
    float32 f32;
    float64 f64;
    struct {
        uint64 i64x2[2];
    } v128;
    uint32 ref_index;
    uint32 global_index;
} InitializerExpressionValue;

typedef struct {
    uint8 init_expr_type;
    InitializerExpressionValue u;
} InitializerExpression;

static uint8 read_uint8(const uint8 **p) {
    uint8 val = **p;
    (*p)++;
    return val;
}

static void read_leb_int32(const uint8 **p, const uint8 *end, int32 *result) {
    // Implementation needed
}

static void read_leb_int64(const uint8 **p, const uint8 *end, int64 *result) {
    // Implementation needed
}

static void read_leb_uint32(const uint8 **p, const uint8 *end, uint32 *result) {
    // Implementation needed
}

static void wasm_runtime_read_v128(const uint8 *p, uint64 *high, uint64 *low) {
    // Implementation needed
}

static void set_error_buf(char *error_buf, uint32 error_buf_size, const char *message) {
    // Implementation needed
}