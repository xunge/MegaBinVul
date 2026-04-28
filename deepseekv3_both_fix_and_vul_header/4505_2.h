#include <stdio.h>
#include <float.h>
#include <assert.h>
#include <stdint.h>

#define JVP_DTOA_FMT_MAX_LEN 32
#define MAX_PRINT_DEPTH 256

enum jv_kind {
    JV_KIND_INVALID,
    JV_KIND_NULL,
    JV_KIND_FALSE,
    JV_KIND_TRUE,
    JV_KIND_NUMBER,
    JV_KIND_STRING,
    JV_KIND_ARRAY,
    JV_KIND_OBJECT
};

#define JV_PRINT_REFCOUNT 0x1
#define JV_PRINT_COLOR 0x2
#define JV_PRINT_ISATTY 0x4
#define JV_PRINT_INVALID 0x8
#define JV_PRINT_ASCII 0x10
#define JV_PRINT_PRETTY 0x20
#define JV_PRINT_SORTED 0x40

struct dtoa_context;
typedef struct jv {
    enum jv_kind kind;
    uint32_t refcnt;
    union {
        double number;
        struct {
            char* str;
            int len;
        } string;
        struct {
            struct jv* elems;
            int len;
        } array;
        struct {
            struct jv* keys;
            struct jv* values;
            int len;
        } object;
    } u;
} *jv;

static const enum jv_kind color_kinds[] = {0};
static const char* colors[] = {0};
static const char COLRESET[] = "";
static const char FIELD_COLOR[] = "";

static void put_str(const char* str, FILE* F, jv* S, int isatty) {}
static void put_char(char c, FILE* F, jv* S, int isatty) {}
static void put_indent(int indent, int flags, FILE* F, jv* S, int isatty) {}
static void put_refcnt(struct dtoa_context* C, double refcnt, FILE* F, jv* S, int isatty) {}
static double jv_get_refcnt(jv x) { return 0; }
static enum jv_kind jv_get_kind(jv x) { return JV_KIND_INVALID; }
static jv jv_copy(jv x) { return x; }
static jv jv_invalid_get_msg(jv x) { return x; }
static void jvp_dump_string(jv x, int ascii, FILE* F, jv* S, int isatty) {}
static const char* jvp_dtoa_fmt(struct dtoa_context* C, char buf[JVP_DTOA_FMT_MAX_LEN], double d) { return ""; }
static double jv_number_value(jv x) { return 0; }
static int jv_array_length(jv x) { return 0; }
#define jv_array_foreach(x, i, elem) for (int i = 0, _ = 0; _ < 1; _++) for (jv elem = jv_copy(x); i < jv_array_length(elem); i++)
static int jv_object_length(jv x) { return 0; }
static jv jv_keys(jv x) { return x; }
static jv jv_array_get(jv x, int i) { return x; }
static jv jv_object_get(jv x, jv key) { return x; }
static int jv_object_iter(jv x) { return 0; }
static int jv_object_iter_next(jv x, int i) { return 0; }
static int jv_object_iter_valid(jv x, int i) { return 0; }
static jv jv_object_iter_key(jv x, int i) { return x; }
static jv jv_object_iter_value(jv x, int i) { return x; }
static void jv_free(jv x) {}
static jv jv_null() { return 0; }