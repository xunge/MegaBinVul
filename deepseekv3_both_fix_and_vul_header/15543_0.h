#include <stddef.h>

typedef struct http1_parser_s http1_parser_s;
typedef struct {
  int close;
  size_t buf_len;
  const char *buf;
  struct {
    unsigned long long uuid;
  } p;
} http_parser_s;

static inline http_parser_s *parser2http(http1_parser_s *parser) {
  return (http_parser_s *)parser;
}

#define FIO_LOG_DEBUG(...) 

void fio_close(unsigned long long uuid);