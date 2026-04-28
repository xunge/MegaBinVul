#include <stdlib.h>

typedef struct _mbfl_encoding {
    int no_encoding;
} mbfl_encoding;

typedef struct _mbfl_convert_filter {
    int (*filter_function)(int, void*);
    int (*filter_flush)(void*);
} mbfl_convert_filter;

typedef struct _mbfl_memory_device {
    int size;
    int increment;
} mbfl_memory_device;

typedef struct _mbfl_buffer_converter {
    const mbfl_encoding *from;
    const mbfl_encoding *to;
    mbfl_convert_filter *filter1;
    mbfl_convert_filter *filter2;
    mbfl_memory_device device;
} mbfl_buffer_converter;

#define mbfl_no_encoding_wchar 0

void *mbfl_malloc(size_t size);
mbfl_convert_filter *mbfl_convert_filter_new(int from, int to, 
    int (*output_function)(int, void*), 
    int (*flush_function)(void*), 
    void *data);
void mbfl_convert_filter_delete(mbfl_convert_filter *filter);
void mbfl_memory_device_init(mbfl_memory_device *device, int initsz, int incsz);
int mbfl_memory_device_output(int c, void *data);
const mbfl_encoding *mbfl_convert_filter_get_vtbl(int from, int to);