#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DEF_DELIM ","
#define MAX_INTERVALS 100
#define EOL '\n'
#define CR '\r'

typedef unsigned long VALUE;
typedef unsigned long ID;

#define Qnil 0
#define T_NIL 0
#define rb_eRuntimeError 0

struct pair_st {
    long low;
    long high;
};

static VALUE rb_scan_args(int argc, VALUE* argv, const char* fmt, ...) { return Qnil; }
static const char* StringValueCStr(VALUE str) { return ""; }
static void rb_raise(VALUE exc, const char* msg) {}
static VALUE rb_ary_entry(VALUE ary, long index) { return Qnil; }
static long NUM2INT(VALUE num) { return 0; }
static VALUE rb_funcall(VALUE obj, ID method, int argc, ...) { return Qnil; }
static ID rb_intern(const char* name) { return 0; }
static int TYPE(VALUE obj) { return 0; }
static int rb_respond_to(VALUE obj, ID method) { return 0; }
static long NUM2LONG(VALUE num) { return 0; }
static VALUE rb_ary_new() { return Qnil; }
static void rb_ary_store(VALUE ary, long index, VALUE val) {}
static VALUE rb_str_new(const char* ptr, long len) { return Qnil; }
static void rb_yield(VALUE val) {}