#include <stddef.h>

typedef struct _mbfl_encoding mbfl_encoding;
typedef struct _mbfl_identify_filter mbfl_identify_filter;
typedef struct _mbfl_encoding_detector mbfl_encoding_detector;

struct _mbfl_encoding_detector {
    mbfl_identify_filter **filter_list;
    int filter_list_size;
    int strict;
};

struct _mbfl_identify_filter {
    const mbfl_encoding *encoding;
    int flag;
    int status;
};