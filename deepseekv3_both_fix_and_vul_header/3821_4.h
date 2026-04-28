#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

typedef int njs_int_t;
typedef unsigned char u_char;

typedef struct njs_value_s njs_value_t;
typedef struct njs_object_s njs_object_t;
typedef struct njs_vm_s njs_vm_t;
typedef struct njs_chb_s njs_chb_t;
typedef struct njs_json_stringify_s njs_json_stringify_t;
typedef struct njs_json_state_s njs_json_state_t;

struct njs_value_s {
    int type;
    union {
        double num;
        struct {
            u_char *start;
            size_t length;
        } str;
        struct {
            njs_value_t *start;
            size_t length;
        } arr;
    } data;
};

struct njs_object_s {
    // minimal object definition
};

struct njs_vm_s {
    void *mem_pool;
    njs_value_t retval;
};

struct njs_chb_s {
    u_char *start;
    u_char *pos;
    u_char *end;
    void *mem_pool;
};

struct njs_json_stringify_s {
    njs_value_t retval;
    struct {
        size_t length;
    } space;
};

struct njs_json_state_s {
    int type;
    size_t index;
    size_t length;
    int array;
    int written;
    njs_value_t value;
    struct {
        size_t length;
        njs_value_t *start;
    } *keys;
};

#define njs_slow_path(cond) (cond)
#define njs_length(s) (sizeof(s) - 1)
#define njs_set_number(v, n) do { (v)->type = 1; (v)->data.num = (n); } while (0)
#define njs_set_null(v) do { (v)->type = 2; } while (0)
#define njs_set_undefined(v) do { (v)->type = 3; } while (0)
#define njs_is_undefined(v) ((v)->type == 3)
#define njs_is_symbol(v) ((v)->type == 4)
#define njs_is_function(v) ((v)->type == 5)
#define njs_is_valid(v) ((v)->type != 6)
#define njs_json_is_object(v) ((v)->type == 7)

enum {
    NJS_OK,
    NJS_ERROR,
    NJS_DECLINED
};

enum {
    NJS_JSON_OBJECT,
    NJS_JSON_ARRAY
};

static njs_int_t njs_json_wrap_value(njs_vm_t *vm, njs_value_t *wrapper, njs_value_t *value);
static njs_json_state_t *njs_json_push_stringify_state(njs_vm_t *vm, njs_json_stringify_t *stringify, njs_value_t *value);
static void njs_chb_init(njs_chb_t *chain, void *mem_pool);
static void njs_chb_append(njs_chb_t *chain, const char *str, size_t len);
static void njs_json_stringify_indent(njs_json_stringify_t *stringify, njs_chb_t *chain, int level);
static njs_json_state_t *njs_json_pop_stringify_state(njs_json_stringify_t *stringify);
static njs_int_t njs_value_property(njs_vm_t *vm, njs_value_t *object, njs_value_t *key, njs_value_t *retval);
static njs_int_t njs_json_stringify_to_json(njs_json_stringify_t *stringify, njs_json_state_t *state, njs_value_t *key, njs_value_t *value);
static njs_int_t njs_json_stringify_replacer(njs_json_stringify_t *stringify, njs_json_state_t *state, njs_value_t *key, njs_value_t *value);
static void njs_chb_append_literal(njs_chb_t *chain, const char *str);
static void njs_json_append_string(njs_chb_t *chain, njs_value_t *value, char quote);
static size_t njs_array_len(njs_value_t *array);
static njs_value_t *njs_array_start(njs_value_t *array);
static void njs_chb_drain(njs_chb_t *chain, size_t len);
static void njs_chb_drop(njs_chb_t *chain, size_t len);
static int64_t njs_chb_size(njs_chb_t *chain);
static void njs_chb_destroy(njs_chb_t *chain);
static int64_t njs_chb_utf8_length(njs_chb_t *chain);
static u_char *njs_string_alloc(njs_vm_t *vm, njs_value_t *value, size_t size, int64_t length);
static void njs_chb_join_to(njs_chb_t *chain, u_char *dst);
static void njs_memory_error(njs_vm_t *vm);