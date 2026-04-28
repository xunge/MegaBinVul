#include <stdbool.h>
#include <stddef.h>

typedef struct http_parser http_parser;

struct http_parser_settings {
    int (*on_message_begin)(http_parser*);
    int (*on_method)(http_parser*, const char*, size_t);
    int (*on_url)(http_parser*, const char*, size_t);
    int (*on_header_field)(http_parser*, const char*, size_t);
    int (*on_header_value)(http_parser*, const char*, size_t);
    int (*on_headers_complete)(http_parser*);
    int (*on_body)(http_parser*, const char*, size_t);
    int (*on_message_complete)(http_parser*);
};

extern bool message_complete;
extern int http_errno;
extern int CHPE_OK;
extern http_parser* parser_ctx;

int http_parser_execute(http_parser* parser, const http_parser_settings* settings, const char* data, size_t len);

int on_message_begin(http_parser*);
int on_method(http_parser*, const char*, size_t);
int on_url(http_parser*, const char*, size_t);
int on_header_field(http_parser*, const char*, size_t);
int on_header_value(http_parser*, const char*, size_t);
int on_headers_complete(http_parser*);
int on_body(http_parser*, const char*, size_t);
int on_message_complete(http_parser*);

#define this parser_ctx