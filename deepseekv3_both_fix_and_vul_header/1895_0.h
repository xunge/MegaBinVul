#include <string.h>
#include <stdlib.h>

#define LABEL_BUF_SIZE 256

int ossl_punycode_decode(const char *in, size_t inlen, unsigned int *out, unsigned int *outlen);
size_t codepoint2utf8(unsigned char *out, unsigned int cp);