#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

typedef uintptr_t FIOBJ;

typedef struct fio_str_info_s {
    char *data;
    size_t len;
} fio_str_info_s;

typedef struct http_s {
    FIOBJ headers;
    FIOBJ method;
    int status;
} http_s;

#define HTTP_INVALID_HANDLE(h) 0
#define HTTP_HEADER_LAST_MODIFIED 0
#define HTTP_HEADER_CACHE_CONTROL 0
#define HTTP_HEADER_ETAG 0
#define HTTP_HEADER_CONTENT_RANGE 0
#define HTTP_HEADER_ACCEPT_RANGES 0
#define HTTP_HEADER_CONTENT_LENGTH 0
#define HTTP_HEADER_CONTENT_ENCODING 0
#define HTTP_HEADER_CONTENT_TYPE 0
#define HTTP_HVALUE_MAX_AGE 0
#define HTTP_HVALUE_BYTES 0
#define HTTP_HVALUE_GZIP 0
#define FIOBJ_T_ARRAY 0
#define FIOBJ_TYPE_IS(obj, type) 0

static FIOBJ fiobj_str_tmp(void) { return 0; }
static void fiobj_str_capa_assert(FIOBJ obj, size_t capa) {}
static void fiobj_str_write(FIOBJ obj, const char *data, size_t len) {}
static fio_str_info_s fiobj_obj2cstr(FIOBJ obj) { return (fio_str_info_s){0}; }
static void fiobj_str_resize(FIOBJ obj, size_t len) {}
static uint64_t fiobj_hash_string(const void *str, size_t len) { return 0; }
static FIOBJ fiobj_hash_get2(FIOBJ hash, uint64_t key) { return 0; }
static FIOBJ fiobj_str_buf(size_t capa) { return 0; }
static size_t http_time2str(char *dest, time_t t) { return 0; }
static void http_set_header(http_s *h, int header, FIOBJ value) {}
static FIOBJ fiobj_dup(FIOBJ obj) { return 0; }
static size_t fio_base64_encode(char *dest, void *src, size_t len) { return 0; }
static int fiobj_iseq(FIOBJ obj1, FIOBJ obj2) { return 0; }
static void fiobj_hash_delete2(FIOBJ hash, uint64_t key) {}
static FIOBJ fiobj_ary_index(FIOBJ ary, size_t pos) { return 0; }
static int64_t fio_atol(char **pos) { return 0; }
static void http_finish(http_s *h) {}
static void http_send_error(http_s *h, int code) {}
static void http_set_header2(http_s *h, fio_str_info_s header, fio_str_info_s value) {}
static void http_sendfile(http_s *h, int fd, int64_t len, int64_t offset) {}
static FIOBJ http_mimetype_find(const char *ext, size_t len) { return 0; }
static FIOBJ fiobj_num_new(int64_t num) { return 0; }
static int hex2byte(uint8_t *dest, uint8_t *src) { return 0; }
static void fiobj_str_printf(FIOBJ obj, const char *format, ...) {}
static void FIO_LOG_ERROR(const char *format, ...) {}