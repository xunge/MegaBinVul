#include <stddef.h>

typedef unsigned long VALUE;
#define Qnil 0
#define T_HASH 0
#define T_STRING 0

struct rb_eArgError {};
struct rb_eRuntimeError {};
struct rb_eLoadError {};

static VALUE filename_id;
static VALUE template_id;
struct rb_data_type_t {
    // dummy fields
};
static const struct rb_data_type_t iodine_mustache_data_type;

typedef struct fio_str_s {
    // dummy definition
} fio_str_s;
#define FIO_STR_INIT {}

typedef struct mustache_s mustache_s;

typedef enum {
  MUSTACHE_OK,
  MUSTACHE_ERR_TOO_DEEP,
  MUSTACHE_ERR_CLOSURE_MISMATCH,
  MUSTACHE_ERR_FILE_NOT_FOUND,
  MUSTACHE_ERR_FILE_TOO_BIG,
  MUSTACHE_ERR_FILE_NAME_TOO_LONG,
  MUSTACHE_ERR_EMPTY_TEMPLATE,
  MUSTACHE_ERR_UNKNOWN,
  MUSTACHE_ERR_USER_ERROR,
  MUSTACHE_ERR_FILE_NAME_TOO_SHORT,
  MUSTACHE_ERR_DELIMITER_TOO_LONG,
  MUSTACHE_ERR_NAME_TOO_LONG
} mustache_error_en;

#define RB_TYPE_P(obj, type) (0)
#define rb_hash_aref(hash, key) (Qnil)
#define rb_raise(exception, msg) 
#define Check_Type(obj, type) 
#define TypedData_Get_Struct(obj, type, data_type, ptr) 
#define RSTRING_PTR(str) (NULL)
#define RSTRING_LEN(str) (0)
#define mustache_load(...) (NULL)