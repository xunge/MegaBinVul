#include <string.h>
#include <stddef.h>
#include <stdint.h>

struct mg_str {
  const char *ptr;
  size_t len;
};

struct mg_http_header {
  struct mg_str name;
  struct mg_str value;
};

struct mg_http_message {
  struct mg_str message;
  struct mg_str body;
  struct mg_str head;
  struct mg_str chunk;
  struct mg_str method;
  struct mg_str uri;
  struct mg_str proto;
  struct mg_str query;
  struct mg_http_header headers[30];
};

int mg_http_get_request_len(unsigned char *buf, size_t buf_len);
const char *skip(const char *s, const char *end, const char *delims, struct mg_str *v);
void mg_http_parse_headers(const char *s, const char *end, struct mg_http_header *h, size_t max_headers);
struct mg_str *mg_http_get_header(struct mg_http_message *hm, const char *name);
int mg_ncasecmp(const char *s1, const char *s2, size_t len);
int mg_vcasecmp(const struct mg_str *s1, const char *s2);
int64_t mg_to64(struct mg_str str);