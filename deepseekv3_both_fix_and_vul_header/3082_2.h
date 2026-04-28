#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define ISXDIGIT(x) (isdigit(x) || (x >= 'a' && x <= 'f') || (x >= 'A' && x <= 'F'))

typedef enum {
    CURLE_OK,
    CURLE_OUT_OF_MEMORY,
    CURLE_URL_MALFORMAT
} CURLcode;

struct SessionHandle;

unsigned char curlx_ultouc(unsigned long ulnum);
CURLcode Curl_convert_from_network(struct SessionHandle *data, unsigned char *in, size_t length);