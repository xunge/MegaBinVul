#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define ISXDIGIT(x) (isdigit((x)) || (tolower((x)) >= 'a' && tolower((x)) <= 'f'))

typedef enum {
  CURLE_OK = 0,
  CURLE_OUT_OF_MEMORY
} CURLcode;

typedef struct {
  int dummy;
} CURL;

unsigned char curlx_ultouc(unsigned long ulnum);
int curlx_uztosi(size_t uznum);
CURLcode Curl_convert_from_network(CURL *handle, unsigned char *buffer, size_t length);
CURLcode Curl_urldecode(CURL *handle, const char *string, size_t length, char **ostring, size_t *olen, int reject_ctrl);