#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct mg_str {
  const char *p;
  size_t len;
};

struct http_message {
  struct mg_str message;
  struct mg_str body;
  struct mg_str method;
  struct mg_str uri;
  struct mg_str proto;
  struct mg_str query_string;
  int resp_code;
  struct mg_str resp_status_msg;
};

int mg_http_get_request_len(const char *s, int n);
const char *mg_skip(const char *s, const char *end, const char *delims, struct mg_str *v);
const char *mg_http_parse_headers(const char *s, const char *end, int len, struct http_message *hm);
int mg_vcasecmp(const struct mg_str *str1, const char *str2);