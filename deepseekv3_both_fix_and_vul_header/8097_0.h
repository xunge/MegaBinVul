#include <string.h>
#include <stdlib.h>

typedef struct _image_info_type {
    int motorola_intel;
    char *encode_unicode;
    char *decode_unicode_be;
    char *decode_unicode_le;
    char *encode_jis;
    char *decode_jis_be;
    char *decode_jis_le;
} image_info_type;

typedef struct _zend_encoding zend_encoding;

#define TSRMLS_DC
#define TSRMLS_CC
#define estrdup(str) strdup(str)

size_t exif_process_string_raw(char **pszInfoPtr, char *szValuePtr, int ByteCount);
size_t exif_process_string(char **pszInfoPtr, char *szValuePtr, int ByteCount TSRMLS_DC);
const zend_encoding *zend_multibyte_fetch_encoding(const char *encoding TSRMLS_DC);
size_t zend_multibyte_encoding_converter(unsigned char **target, size_t *target_len, unsigned char *source, size_t source_len, const zend_encoding *to, const zend_encoding *from TSRMLS_DC);