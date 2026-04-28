#include <stddef.h>

#define JSONTREE_MAX_DEPTH 32

enum json_type {
    JSON_TYPE_OBJECT,
    JSON_TYPE_ARRAY
};

struct jsontree_value {
    enum json_type type;
};

struct jsontree_array {
    struct jsontree_value base;
    int count;
    struct jsontree_value **values;
};

struct jsontree_pair {
    struct jsontree_value *value;
};

struct jsontree_object {
    struct jsontree_array base;
    struct jsontree_pair *pairs;
};

struct jsontree_context {
    int depth;
    int index[JSONTREE_MAX_DEPTH];
    struct jsontree_value *values[JSONTREE_MAX_DEPTH];
};