#include <stdint.h>
#include <string.h>

#define HTML_ESCAPE_MAX_LEN 6

typedef unsigned long VALUE;

struct html_escape_entry {
    const char *str;
    uint8_t len;
};

extern struct html_escape_entry html_escape_table[];

#define ALLOCV_N(type, v, n) ((type*)ruby_xmalloc((n) * sizeof(type)))
#define ALLOCV_END(v) ruby_xfree(v)
#define RSTRING_LEN(str) (0)
#define RSTRING_PTR(str) (NULL)

static VALUE rb_str_new(const char *ptr, long len) { return 0; }
static VALUE rb_str_dup(VALUE str) { return 0; }
static void preserve_original_state(VALUE orig, VALUE escaped) {}
static void *ruby_xmalloc(size_t size) { return NULL; }
static void ruby_xfree(void *ptr) {}