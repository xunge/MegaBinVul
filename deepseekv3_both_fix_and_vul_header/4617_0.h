#include <stdlib.h>

typedef struct _mbfl_encoding mbfl_encoding;
typedef struct _mbfl_string mbfl_string;
typedef struct _mbfl_identify_filter mbfl_identify_filter;

struct _mbfl_string {
    unsigned char *val;
    int len;
};

struct _mbfl_identify_filter {
    int flag;
    int status;
    const mbfl_encoding *encoding;
    void (*filter_function)(unsigned char c, mbfl_identify_filter *filter);
};

void *mbfl_calloc(size_t nmemb, size_t size);
void mbfl_free(void *ptr);
int mbfl_identify_filter_init2(mbfl_identify_filter *filter, const mbfl_encoding *encoding);
void mbfl_identify_filter_cleanup(mbfl_identify_filter *filter);