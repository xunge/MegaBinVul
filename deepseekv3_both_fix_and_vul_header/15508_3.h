#include <stdint.h>
#include <string>
#include <cstddef>

#define MAX_REQ_SIZE 8192
#define PARSE_REQ_OVER 1
#define NEED_MORE_STATUS 2
#define HTTP_PARSER_ERRNO(p) ((p)->http_errno)

struct http_parser {
    int http_errno;
};

struct http_parser_settings {};

struct Request {
    static int _total_req_size;
    static int _parse_err;
    static int _parse_part;
    static http_parser _parser;
    static http_parser_settings _settings;
    
    static ssize_t http_parser_execute(http_parser* parser, const http_parser_settings* settings,
                                     const char* data, size_t len);
    static const char* http_errno_description(int err);
    static int parse_request(const char* read_buffer, int read_size);
};

#define LOG_INFO(fmt, ...)
#define LOG_DEBUG(fmt, ...)
#define LOG_ERROR(fmt, ...)