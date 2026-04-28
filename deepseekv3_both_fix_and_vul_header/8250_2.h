#include <stdlib.h>
#include <string.h>

#define MCRYPT_FAILED NULL
#define MCRYPT_OPEN_MODULE_FAILED "Module initialization failed"
#define MCRYPT_IV_WRONG_SIZE "The IV parameter must be as long as the blocksize"
#define MCRYPT_ENCRYPT 0
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define TSRMLS_DC
#define TSRMLS_CC
#define RETVAL_STRINGL(s, l, d) do { \
    (return_value)->value.str.val = (s); \
    (return_value)->value.str.len = (l); \
    (return_value)->type = 6; /* IS_STRING */ \
} while (0)
#define RETURN_FALSE do { \
    (return_value)->type = 2; /* IS_FALSE */ \
} while (0)

#define MCRYPT_GET_INI cipher_dir_string = NULL; module_dir_string = NULL;

typedef void* MCRYPT;

typedef struct _zval_struct {
    union {
        long lval;
        struct {
            char *val;
            int len;
        } str;
    } value;
    int type;
} zval;

#define E_WARNING 2
#define E_RECOVERABLE_ERROR 4096

void* mcrypt_module_open(const char*, const char*, const char*, const char*);
int mcrypt_enc_get_key_size(void*);
int* mcrypt_enc_get_supported_key_sizes(void*, int*);
int mcrypt_enc_get_iv_size(void*);
int mcrypt_enc_mode_has_iv(void*);
int mcrypt_enc_is_block_mode(void*);
int mcrypt_enc_get_block_size(void*);
int mcrypt_generic_init(void*, const char*, int, const char*);
void mcrypt_generic(void*, const char*, int);
void mdecrypt_generic(void*, const char*, int);
void mcrypt_generic_end(void*);
void mcrypt_free(void*);
void* emalloc(size_t);
void efree(void*);
void php_error_docref(const char*, int, const char*, ...);