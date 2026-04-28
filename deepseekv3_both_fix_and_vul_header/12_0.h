#include <string.h>

typedef struct ref {
    union {
        int intval;
        const unsigned char *const_bytes;
        unsigned char *bytes;
    } value;
} ref;

typedef struct i_ctx_t {
    // dummy definition since actual contents are not used in the function
} i_ctx_t;

extern void *imemory;

int array_get(void *imemory, ref *array, int index, ref *result);
int dict_find_string(ref *dict, const char *key, ref **result);
int r_size(ref *r);
int comparedictkey(i_ctx_t *i_ctx_p, ref *dict1, ref *dict2, char *key);