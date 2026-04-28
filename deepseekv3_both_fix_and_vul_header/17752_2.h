#include <ctype.h>
#include <string.h>

typedef unsigned long VALUE;
#define Qnil 0

static const char content_type[] = "Content-Type";
static const char content_length[] = "Content-Length";
static VALUE content_type_val;
static VALUE content_length_val;
static VALUE rb_eArgError;

static VALUE rb_hash_lookup2(VALUE hash, VALUE key, VALUE def);
static VALUE rb_hash_aset(VALUE hash, VALUE key, VALUE val);
static VALUE rb_str_new(const char *ptr, long len);
static VALUE rb_ary_new(void);
static void rb_ary_push(VALUE array, VALUE item);
static void rb_raise(VALUE exc, const char *fmt);