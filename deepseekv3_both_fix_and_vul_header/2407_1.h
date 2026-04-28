#include <string.h>
#include <assert.h>

typedef struct yajl_buf_t *yajl_buf;

void yajl_buf_append(yajl_buf buf, const void *data, unsigned int len);
void hexToDigit(unsigned int *codepoint, const unsigned char *str);
void Utf32toUtf8(unsigned int codepoint, char utf8Buf[5]);