#include <stddef.h>

#define CK(x) do { if ((x) < 0) return -1; } while (0)

#define MBFL_WCSGROUP_MASK 0xffff
#define MBFL_WCSGROUP_THROUGH 0x10000
#define MBFL_WCSPLANE_MASK 0xffff
#define MBFL_WCSPLANE_BIG5 0x30000

enum {
    mbfl_no_encoding_cp950
};

typedef struct _mbfl_convert_filter mbfl_convert_filter;
typedef struct _mbfl_encoding mbfl_encoding;

struct _mbfl_convert_filter {
    int (*output_function)(int, void*);
    void *data;
    const mbfl_encoding *from;
    const mbfl_encoding *to;
    int status;
    int cache;
};

struct _mbfl_encoding {
    int no_encoding;
};

extern const unsigned short big5_ucs_table[];
extern const size_t big5_ucs_table_size;
extern const unsigned short (*cp950_pua_tbl)[4];