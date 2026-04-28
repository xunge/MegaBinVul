#include <stdint.h>
#include <string.h>

#define HTML_ESCAPE_MAX_LEN 6

struct html_escape_entry {
    const char *str;
    uint8_t len;
};

extern struct html_escape_entry html_escape_table[];

#define ALLOCV_N(type, v, s) ((type *)rb_alloc_tmp_buffer2(&(v), (s), sizeof(type)))
#define ALLOCV_END(v) rb_free_tmp_buffer(&(v))
#define RSTRING_LEN(str) (0)
#define RSTRING_PTR(str) (NULL)

typedef int VALUE;

static VALUE rb_str_new(const char *ptr, long len) { return 0; }
static VALUE rb_str_dup(VALUE str) { return 0; }
static void preserve_original_state(VALUE orig, VALUE escaped) {}
static void *rb_alloc_tmp_buffer2(VALUE *v, long s, size_t t) { return NULL; }
static void rb_free_tmp_buffer(VALUE *v) {}