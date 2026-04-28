#include <string.h>
#include <stdlib.h>

typedef struct _zend_encoding zend_encoding;

typedef struct {
    int motorola_intel;
    const char *decode_unicode_be;
    const char *decode_unicode_le;
    const char *encode_unicode;
    const char *decode_jis_be;
    const char *decode_jis_le;
    const char *encode_jis;
} image_info_type;

extern char *estrdup(const char *s);
extern size_t exif_process_string_raw(char **pszInfoPtr, char *szValuePtr, int ByteCount);
extern void exif_process_string(char **pszInfoPtr, char *szValuePtr, int ByteCount);
extern zend_encoding *zend_multibyte_fetch_encoding(const char *encoding_name);
extern size_t zend_multibyte_encoding_converter(unsigned char **target, size_t *target_length, unsigned char *source, size_t source_length, zend_encoding *to, zend_encoding *from);