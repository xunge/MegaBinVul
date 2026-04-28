#include <stdint.h>

typedef struct http1_parser_s http1_parser_s;

typedef struct http_request_s {
  char *method;
} http_request_s;

typedef struct http1pr_s {
  struct {
    uint64_t uuid;
    void *settings;
  } p;
  http_request_s request;
  int stop;
  int close;
  void *handler;
} http1pr_s;

http1pr_s *parser2http(http1_parser_s *parser);
void http_on_request_handler______internal(void *handler, void *settings);
void http_finish(http_request_s *request);
void h1_reset(http1pr_s *p);
int fio_is_closed(uint64_t uuid);
void *http1_pr2handle(http1pr_s *p);

#define http1_pr2handle(p) ((p)->handler)