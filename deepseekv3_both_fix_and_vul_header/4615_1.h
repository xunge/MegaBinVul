#include <stdlib.h>

typedef struct _mbfl_string {
    unsigned char *val;
    unsigned int len;
    int no_language;
    int no_encoding;
} mbfl_string;

typedef struct _mbfl_encoding {
    int no_encoding;
} mbfl_encoding;

typedef struct _mbfl_memory_device {
    unsigned char *buffer;
    unsigned int length;
    unsigned int pos;
} mbfl_memory_device;

typedef struct _mbfl_convert_filter {
    int (*filter_function)(int, void*);
    int (*filter_flush)(void*);
    void *opaque;
    struct _mbfl_convert_filter *next;
} mbfl_convert_filter;

typedef struct _mbfl_filt_tl_jisx0201_jisx0208_param {
    int mode;
} mbfl_filt_tl_jisx0201_jisx0208_param;

struct mbfl_convert_vtable;

extern const mbfl_encoding *mbfl_no2encoding(int no_encoding);
extern void mbfl_memory_device_init(mbfl_memory_device *device, unsigned int initsz, unsigned int allocsz);
extern void mbfl_string_init(mbfl_string *string);
extern mbfl_convert_filter *mbfl_convert_filter_new(int from, int to, int (*output_function)(int, void*), int (*flush_function)(void*), void *data);
extern void *mbfl_malloc(size_t size);
extern void mbfl_free(void *ptr);
extern mbfl_convert_filter *mbfl_convert_filter_new2(const struct mbfl_convert_vtable *vtbl, int (*output_function)(int, void*), int (*flush_function)(void*), mbfl_convert_filter *next);
extern int mbfl_memory_device_output(int c, void *data);
extern int mbfl_convert_filter_flush(mbfl_convert_filter *filter);
extern mbfl_string *mbfl_memory_device_result(mbfl_memory_device *device, mbfl_string *result);
extern void mbfl_convert_filter_delete(mbfl_convert_filter *filter);

extern const struct mbfl_convert_vtable vtbl_tl_jisx0201_jisx0208;
extern const int mbfl_no_encoding_wchar;