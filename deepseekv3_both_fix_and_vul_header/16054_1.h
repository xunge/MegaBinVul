#include <string.h>

#define MG_MAX_HTTP_HEADERS 64

struct mg_str {
  const char *p;
  size_t len;
};

struct http_message {
  struct mg_str header_names[MG_MAX_HTTP_HEADERS];
  struct mg_str header_values[MG_MAX_HTTP_HEADERS];
};

int mg_ncasecmp(const char *s1, const char *s2, size_t len);