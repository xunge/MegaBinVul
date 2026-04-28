#include <string.h>
#include <locale.h>
#include <langinfo.h>

enum entity_charset {
    cs_utf_8
};

typedef struct _zend_encoding zend_encoding;

extern const zend_encoding *zend_multibyte_get_internal_encoding(void);
extern const char *zend_multibyte_get_encoding_name(const zend_encoding *);

struct charset_map_entry {
    const char *codeset;
    enum entity_charset charset;
};
extern struct charset_map_entry charset_map[];

#define TSRMLS_DC
#define TSRMLS_C
#define TSRMLS_CC
#define SG(x) NULL
#define E_WARNING 0

void php_error_docref(const char *ref, int type, const char *format, ...);