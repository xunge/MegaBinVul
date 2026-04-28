#include <stddef.h>
#include <string.h>

typedef struct {
    unsigned int num;
    unsigned int den;
} ifd_urational;

typedef struct {
    int num;
    int den;
} ifd_srational;

typedef struct image_info_value {
    char *s;
    unsigned int u;
    int i;
    float f;
    double d;
    ifd_urational ur;
    ifd_srational sr;
    struct image_info_value *list;
} image_info_value;

typedef struct {
    int tag;
    int format;
    int length;
    char *name;
    image_info_value value;
    image_info_value *list;
} image_info_data;

typedef struct {
    image_info_data *list;
    size_t count;
} image_info_list;

typedef struct {
    image_info_list *info_list;
    int sections_found;
} image_info_type;

#define TAG_FMT_STRING 2
#define TAG_FMT_UNDEFINED 7
#define TAG_FMT_SBYTE 6
#define TAG_FMT_BYTE 1
#define TAG_FMT_USHORT 3
#define TAG_FMT_ULONG 4
#define TAG_FMT_URATIONAL 5
#define TAG_FMT_SSHORT 8
#define TAG_FMT_SLONG 9
#define TAG_FMT_SRATIONAL 10
#define TAG_FMT_SINGLE 11
#define TAG_FMT_DOUBLE 12

#define TAG_MAKER_NOTE 0x927C
#define EXIFERR_CC
#define E_WARNING 2

extern int php_tiff_bytes_per_format[];
extern void *safe_erealloc(void *ptr, size_t nmemb, size_t size, size_t offset);
extern void *safe_emalloc(size_t nmemb, size_t size, size_t offset);
extern char *estrdup(const char *s);
extern char *estrndup(const char *s, size_t length);
extern size_t php_strnlen(const char *s, size_t maxlen);
extern unsigned short php_ifd_get16u(void *value, int motorola_intel);
extern unsigned int php_ifd_get32u(void *value, int motorola_intel);
extern short php_ifd_get16s(void *value, int motorola_intel);
extern int php_ifd_get32s(void *value, int motorola_intel);
extern void exif_error_docref(const char *err_reference, image_info_type *image_info, int level, const char *format, ...);