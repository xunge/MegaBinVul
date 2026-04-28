#include <stdlib.h>
#include <string.h>

typedef struct _mbfl_string {
    unsigned char *val;
    unsigned int len;
    int no_language;
    int no_encoding;
} mbfl_string;

typedef struct _mbfl_encoding {
    int flag;
    const unsigned char *mblen_table;
    int (*mblen)(int, const unsigned char *);
} mbfl_encoding;

typedef struct _mbfl_memory_device {
    unsigned char *buffer;
    unsigned int length;
    unsigned int pos;
} mbfl_memory_device;

typedef struct _mbfl_convert_filter {
    int (*filter_function)(int, struct _mbfl_convert_filter *);
    int (*filter_flush)(struct _mbfl_convert_filter *);
    void (*filter_dtor)(struct _mbfl_convert_filter *);
    int (*output_function)(int, void*);
    int (*flush_function)(void*);
    void *data;
} mbfl_convert_filter;

extern const mbfl_encoding *mbfl_no2encoding(int no_encoding);
extern void mbfl_string_init(mbfl_string *string);
extern void *mbfl_calloc(size_t nmemb, size_t size);
extern mbfl_convert_filter *mbfl_convert_filter_new(int from, int to, int (*output_function)(int, void*), int (*flush_function)(void*), void *data);
extern void mbfl_convert_filter_delete(mbfl_convert_filter *filter);
extern void mbfl_convert_filter_copy(mbfl_convert_filter *src, mbfl_convert_filter *dest);
extern void mbfl_memory_device_init(mbfl_memory_device *device, int initsz, int allocsz);
extern int mbfl_memory_device_output(int c, void *data);
extern int mbfl_filter_output_null(int c, void *data);
extern mbfl_string *mbfl_memory_device_result(mbfl_memory_device *device, mbfl_string *result);

#define MBFL_ENCTYPE_SBCS      0x0001
#define MBFL_ENCTYPE_WCS2BE    0x0002  
#define MBFL_ENCTYPE_WCS2LE    0x0004
#define MBFL_ENCTYPE_WCS4BE    0x0008
#define MBFL_ENCTYPE_WCS4LE    0x0010

extern int mbfl_no_encoding_wchar;