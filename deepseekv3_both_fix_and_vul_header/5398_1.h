#include <stddef.h>

typedef struct _xp_field_type {
    int tag;
    char *value;
    int size;
} xp_field_type;

typedef struct _image_info_type {
    char *encode_unicode;
    char *decode_unicode_be;
    char *decode_unicode_le;
    int motorola_intel;
} image_info_type;

size_t zend_multibyte_encoding_converter(unsigned char **, int *, unsigned char *, int, void *, void * TSRMLS_DC);
void *zend_multibyte_fetch_encoding(const char * TSRMLS_DC);
int exif_process_string_raw(char **, char *, int);

#define TSRMLS_DC
#define TSRMLS_CC