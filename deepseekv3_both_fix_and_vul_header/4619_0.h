#include <stdlib.h>

typedef struct _mbfl_string {
    unsigned char *val;
    size_t len;
    int no_encoding;
} mbfl_string;

typedef struct _mbfl_encoding {
    int no_encoding;
} mbfl_encoding;

typedef struct _mbfl_memory_device {
    unsigned char *buffer;
    size_t length;
    size_t pos;
} mbfl_memory_device;

typedef struct _mbfl_convert_filter {
    // filter structure members
} mbfl_convert_filter;

typedef struct _mbfl_buffer_converter {
    mbfl_convert_filter *filter1;
    mbfl_convert_filter *filter2;
    mbfl_memory_device device;
    mbfl_encoding *to;
} mbfl_buffer_converter;

void mbfl_buffer_converter_feed(mbfl_buffer_converter *convd, mbfl_string *string);
void mbfl_convert_filter_flush(mbfl_convert_filter *filter);
mbfl_string *mbfl_memory_device_result(mbfl_memory_device *device, mbfl_string *result);