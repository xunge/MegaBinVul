#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#define JSONTREE_PRETTY 1
#define JSONTREE_MAX_DEPTH 32

enum json_type {
    JSON_TYPE_OBJECT,
    JSON_TYPE_ARRAY,
    JSON_TYPE_STRING,
    JSON_TYPE_UINT,
    JSON_TYPE_INT,
    JSON_TYPE_CALLBACK,
    JSON_TYPE_S8PTR,
    JSON_TYPE_U8PTR,
    JSON_TYPE_S16PTR,
    JSON_TYPE_U16PTR,
    JSON_TYPE_S32PTR,
    JSON_TYPE_U32PTR
};

struct jsontree_value {
    enum json_type type;
};

struct jsontree_array {
    struct jsontree_value base;
    int count;
    struct jsontree_value **values;
};

struct jsontree_object {
    struct jsontree_array base;
    struct {
        const char *name;
        struct jsontree_value *value;
    } *pairs;
};

struct jsontree_string {
    struct jsontree_value base;
    const char *value;
};

struct jsontree_uint {
    struct jsontree_value base;
    uint32_t value;
};

struct jsontree_int {
    struct jsontree_value base;
    int32_t value;
};

struct jsontree_context;

struct jsontree_callback {
    struct jsontree_value base;
    int (*output)(struct jsontree_context *);
};

struct jsontree_ptr {
    struct jsontree_value base;
    void *value;
};

struct jsontree_context {
    struct jsontree_value **values;
    int *index;
    int depth;
    int callback_state;
    void (*putchar)(char);
};

#define PRINTF printf

void jsontree_write_string(struct jsontree_context *ctx, const char *str);
void jsontree_write_uint(struct jsontree_context *ctx, uint32_t val);
void jsontree_write_int(struct jsontree_context *ctx, int32_t val);