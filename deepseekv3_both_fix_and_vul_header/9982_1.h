#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

#define HTTP_OK 200
#define HTTP_BAD_REQUEST 400
#define HTTP_UNAUTHORIZED 401
#define HTTP_NOT_FOUND 404
#define HTTP_INTERNAL_SERVER_ERROR 500
#define HTTP_SERVICE_UNAVAILABLE 503

#define UPNP_WRITE 0
#define UPNP_INFO 0
#define HTTP 0

typedef enum {
    PARSE_OK,
    PARSE_INCOMPLETE_ENTITY,
    PARSE_SUCCESS,
    PARSE_CONTINUE_1,
    PARSE_INCOMPLETE,
    PARSE_FAILURE
} parse_status_t;

typedef enum {
    POS_ENTITY,
    POS_COMPLETE
} parser_position_t;

typedef struct {
    size_t length;
} entity_t;

typedef struct {
    char *buf;
    size_t length;
} membuffer_t;

typedef struct {
    entity_t entity;
    membuffer_t msg;
} http_message_t;

typedef struct {
    parser_position_t position;
    http_message_t msg;
    size_t entity_start_position;
    int http_error_code;
} http_parser_t;

typedef struct SendInstruction {
    int IsVirtualFile;
} SendInstruction;

typedef struct {
    FILE* (*open)(const char*, int);
    int (*write)(FILE*, const void*, size_t);
    void (*close)(FILE*);
} VirtualDirCallback;

extern VirtualDirCallback virtualDirCallback;

typedef struct {
    int dummy;
} SOCKINFO;

int sock_read(SOCKINFO *info, char *buf, int len, int *timeout);
int parser_parse_entity(http_parser_t *parser);
void UpnpPrintf(int level, int module, const char *file, int line, const char *fmt, ...);
void print_http_headers(http_message_t *msg);
int membuffer_append(membuffer_t *buf, const char *data, size_t size);