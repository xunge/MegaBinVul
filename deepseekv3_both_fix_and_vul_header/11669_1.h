#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

typedef enum {
  CURLE_OK = 0,
  CURLE_OUT_OF_MEMORY,
} CURLcode;

struct Curl_easy;

extern CURLcode Curl_base64_encode(struct Curl_easy *data,
                                  const char *input,
                                  size_t size,
                                  char **outptr,
                                  size_t *outlen);

#define SIZE_T_MAX ((size_t)-1)