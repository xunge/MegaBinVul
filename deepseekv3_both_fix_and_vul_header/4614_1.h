#include <stddef.h>

typedef struct _mbfl_encoding mbfl_encoding;
typedef struct _mbfl_string mbfl_string;
typedef struct _mbfl_convert_filter mbfl_convert_filter;

#define MBFL_ENCTYPE_SBCS      0x0001
#define MBFL_ENCTYPE_WCS2BE    0x0002
#define MBFL_ENCTYPE_WCS2LE    0x0003
#define MBFL_ENCTYPE_WCS4BE    0x0004
#define MBFL_ENCTYPE_WCS4LE    0x0005

struct _mbfl_encoding {
    int flag;
    const unsigned char *mblen_table;
};

struct _mbfl_string {
    unsigned char *val;
    size_t len;
    int no_encoding;
};

struct _mbfl_convert_filter {
    int (*filter_function)(int c, mbfl_convert_filter *filter);
};

extern const mbfl_encoding *mbfl_no2encoding(int no_encoding);
extern mbfl_convert_filter *mbfl_convert_filter_new(int from, int to, int (*output_function)(int, void*), int (*flush_function)(void*), void *data);
extern void mbfl_convert_filter_delete(mbfl_convert_filter *filter);
extern int filter_count_output(int c, void *data);
extern int mbfl_no_encoding_wchar;