#include <stdlib.h>
#include <string.h>

typedef unsigned int OnigOptionType;
typedef unsigned char OnigUChar;

struct OnigRegion {
    int num_regs;
    int *beg;
    int *end;
};

struct OnigSyntaxType {
    int dummy;
};

typedef struct _zval_struct zval;
typedef struct _zval_struct *zval_ptr;
typedef struct _zval_struct **zval_ptr_ptr;

struct _zval_struct {
    int type;
    union {
        long lval;
        struct {
            char *val;
            int len;
        } str;
    } value;
};

typedef struct _zend_fcall_info {
    int param_count;
    zval_ptr_ptr *params;
    zval_ptr_ptr *retval_ptr_ptr;
} zend_fcall_info;

typedef struct _zend_fcall_info_cache {
    int dummy;
} zend_fcall_info_cache;

typedef struct _php_mb_regex_t {
    int dummy;
} php_mb_regex_t;

typedef struct _mbfl_encoding {
    int dummy;
} mbfl_encoding;

typedef struct _smart_str {
    char *c;
    size_t len;
    size_t a;
} smart_str;

typedef struct _zend_executor_globals {
    struct _zend_object *exception;
} zend_executor_globals;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval_ptr return_value, zval_ptr_ptr return_value_ptr, zval_ptr this_ptr, int return_value_used
#define TSRMLS_CC
#define ZEND_NUM_ARGS() ht
#define FAILURE (-1)
#define SUCCESS 0
#define IS_STRING 6
#define E_WARNING 2
#define E_ERROR 1
#define PHP_EOL "\n"
#define ONIG_MAX_ERROR_MESSAGE_LEN 256

#define RETURN_FALSE do { return_value->value.lval = 0; return; } while (0)
#define RETVAL_FALSE RETURN_FALSE
#define RETURN_TRUE do { return_value->value.lval = 1; return; } while (0)
#define RETURN_STRINGL(s, l, dup) do { \
    return_value->value.str.val = (dup ? strndup((s), (l)) : (s)); \
    return_value->value.str.len = (l); \
    return_value->type = IS_STRING; \
    return; \
} while (0)

#define MBREX(x) (x)

/* Global variables */
extern int current_mbctype;
extern OnigOptionType regex_default_options;
extern struct OnigSyntaxType *regex_default_syntax;
extern zend_executor_globals executor_globals;
#define EG(v) (executor_globals.v)

/* Function declarations */
void _php_mb_regex_init_options(char *option_str, int option_str_len, OnigOptionType *options, struct OnigSyntaxType **syntax, int *eval);
const char *_php_mb_regex_mbctype2name(int mbctype);
const struct _mbfl_encoding *mbfl_name2encoding(const char *name);
void php_error_docref(const char *docref, int type, const char *format, ...);
int zend_parse_parameters(int num_args, const char *type_spec, ...);
php_mb_regex_t *php_mbregex_compile_pattern(char *pattern, int pattern_len, OnigOptionType options, int mbctype, struct OnigSyntaxType *syntax);
char *zend_make_compiled_string_description(const char *description);
struct OnigRegion *onig_region_new();
int onig_search(php_mb_regex_t *regex, const OnigUChar *str, const OnigUChar *end, const OnigUChar *start, const OnigUChar *range, struct OnigRegion *regs, OnigOptionType options);
void onig_error_code_to_str(OnigUChar *s, int code);
void onig_region_free(struct OnigRegion *regs, int free_self);
void smart_str_appendl(struct _smart_str *str, const char *ptr, size_t len);
void smart_str_0(struct _smart_str *str);
void smart_str_free(struct _smart_str *str);
void smart_str_appendc(struct _smart_str *str, char c);
void zval_dtor(zval *z);
void zval_ptr_dtor(zval **z);
void convert_to_string(zval *op);
void convert_to_string_ex(zval **op);
void convert_to_long_ex(zval **op);
int zend_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache);
int zend_eval_stringl(char *str, int str_len, zval *retval_ptr, const char *string_name);
void efree(void *ptr);
void array_init(zval *arg);
void add_next_index_stringl(zval *arg, const char *str, uint length, int duplicate);
void MAKE_STD_ZVAL(zval *pzval);
int php_mb_mbchar_bytes_ex(const char *p, const struct _mbfl_encoding *enc);

/* Macro definitions for Zend engine macros */
#define Z_TYPE_PP(ppzval) ((*ppzval)->type)
#define Z_STRVAL_PP(ppzval) ((*ppzval)->value.str.val)
#define Z_STRLEN_PP(ppzval) ((*ppzval)->value.str.len)
#define Z_LVAL_PP(ppzval) ((*ppzval)->value.lval)
#define Z_STRVAL(zval) (zval).value.str.val
#define Z_STRLEN(zval) (zval).value.str.len
#define Z_STRVAL_P(zval_p) (*(zval_p)).value.str.val
#define Z_STRLEN_P(zval_p) (*(zval_p)).value.str.len
#define RETVAL_STRINGL(s, l, dup) RETURN_STRINGL(s, l, dup)

/* Type aliases for structs */
typedef struct OnigRegion OnigRegion;
typedef struct OnigSyntaxType OnigSyntaxType;