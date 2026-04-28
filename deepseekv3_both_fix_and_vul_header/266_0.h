#include <iconv.h>
#include <errno.h>
#include <string.h>

typedef enum {
    PHP_ICONV_ERR_SUCCESS,
    PHP_ICONV_ERR_WRONG_CHARSET,
    PHP_ICONV_ERR_CONVERTER,
    PHP_ICONV_ERR_UNKNOWN,
    PHP_ICONV_ERR_MALFORMED
} php_iconv_err_t;

typedef enum {
    PHP_ICONV_ENC_SCHEME_BASE64,
    PHP_ICONV_ENC_SCHEME_QPRINT
} php_iconv_enc_scheme_t;

#define ICONV_ASCII_ENCODING "ASCII"
#define ICONV_SUPPORTS_ERRNO 1

#define PHP_ICONV_MIME_DECODE_CONTINUE_ON_ERROR (1<<0)
#define PHP_ICONV_MIME_DECODE_STRICT (1<<1)

typedef struct {
    char *c;
    size_t len;
    size_t a;
} smart_str;

typedef struct _zend_string {
    char *val;
    size_t len;
} zend_string;

static zend_string *php_base64_decode(unsigned char *input, size_t len);
static zend_string *php_quot_print_decode(unsigned char *input, size_t len, int flag);
static void zend_string_release_ex(zend_string *s, int persistent);
static void smart_str_0(smart_str *str);
static php_iconv_err_t _php_iconv_appendc(smart_str *pretval, char c, iconv_t cd);
static php_iconv_err_t _php_iconv_appendl(smart_str *pretval, const char *s, size_t len, iconv_t cd);