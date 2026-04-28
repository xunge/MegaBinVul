#include <stddef.h>

typedef struct _mbfl_string {
    unsigned char *val;
    size_t len;
    int no_encoding;
} mbfl_string;

typedef struct _mbfl_encoding {
    const unsigned char *mblen_table;
    /* other members omitted */
} mbfl_encoding;

extern const mbfl_encoding *mbfl_no2encoding(int no_encoding);
extern void mbfl_string_init(mbfl_string *string);
extern const mbfl_string *mbfl_convert_encoding(const mbfl_string *from, mbfl_string *to, int encoding);
extern void mbfl_string_clear(mbfl_string *string);

#define mbfl_no_encoding_utf8 1