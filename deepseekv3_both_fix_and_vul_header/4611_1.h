#include <stdlib.h>

typedef struct _mbfl_encoding mbfl_encoding;
typedef struct _mbfl_string mbfl_string;
typedef struct _mbfl_identify_filter mbfl_identify_filter;

enum mbfl_no_encoding {
    /* dummy value since actual enum values are not provided */
    MBFL_ENCODING_DUMMY
};

struct _mbfl_identify_filter {
    int flag;
    int status;
    const mbfl_encoding *encoding;
    void (*filter_function)(unsigned char, mbfl_identify_filter*);
};

struct _mbfl_string {
    unsigned char *val;
    int len;
};

extern void *mbfl_calloc(size_t, size_t);
extern void mbfl_free(void *);
extern int mbfl_identify_filter_init(mbfl_identify_filter *, enum mbfl_no_encoding);
extern void mbfl_identify_filter_cleanup(mbfl_identify_filter *);