#include <stddef.h>

#define MBFL_ENCTYPE_SBCS    0x0001
#define MBFL_ENCTYPE_WCS2BE  0x0002  
#define MBFL_ENCTYPE_WCS2LE  0x0004
#define MBFL_ENCTYPE_WCS4BE  0x0008
#define MBFL_ENCTYPE_WCS4LE  0x0010

typedef struct _mbfl_encoding mbfl_encoding;
typedef struct _mbfl_string mbfl_string;

struct _mbfl_string {
    unsigned char *val;
    size_t len;
    int no_encoding;
};

struct _mbfl_encoding {
    int flag;
    const unsigned char *mblen_table;
};

const mbfl_encoding *mbfl_no2encoding(int no_encoding);