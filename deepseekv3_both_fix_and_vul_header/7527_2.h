#include <string.h>
#include <stdlib.h>

#define OGS_SBI_MAX_NUM_OF_PART 16
#define OGS_LOG_ERROR 1

typedef struct multipart_parser multipart_parser;
typedef struct multipart_parser_settings multipart_parser_settings;
typedef struct multipart_parser_data_t multipart_parser_data_t;

typedef struct {
    char *content_id;
    char *content_type;
    void *pkbuf;
} ogs_sbi_part_t;

typedef struct {
    ogs_sbi_part_t part[OGS_SBI_MAX_NUM_OF_PART];
    int num_of_part;
} ogs_sbi_message_t;

typedef struct {
    char *content;
    size_t content_length;
    ogs_sbi_part_t part[OGS_SBI_MAX_NUM_OF_PART];
    int num_of_part;
} ogs_sbi_http_message_t;

typedef int (*multipart_data_cb)(multipart_parser*, const char *at, size_t length);
typedef int (*multipart_notify_cb)(multipart_parser*);

struct multipart_parser_settings {
    multipart_data_cb on_header_field;
    multipart_data_cb on_header_value;
    multipart_data_cb on_part_data;
    multipart_notify_cb on_part_data_end;
};

struct multipart_parser_data_t {
    int num_of_part;
    struct {
        char *content_id;
        char *content_type;
        char *content;
        size_t content_length;
    } part[OGS_SBI_MAX_NUM_OF_PART];
    char *header_field;
};

#define OGS_SBI_CONTENT_JSON_TYPE "application/json"
#define OGS_SBI_CONTENT_5GNAS_TYPE "application/vnd.5gnas"
#define OGS_SBI_CONTENT_NGAP_TYPE "application/vnd.ngap"
#define OGS_OK 0
#define OGS_ERROR -1

#define SWITCH(x) do {
#define CASE(x) } while(0); if (strcmp(data.part[i].content_type, x) == 0) {
#define DEFAULT } else {
#define END }

extern multipart_parser* multipart_parser_init(const char *boundary, const multipart_parser_settings *settings);
extern size_t multipart_parser_execute(multipart_parser *parser, const char *buf, size_t len);
extern void multipart_parser_free(multipart_parser *parser);
extern void multipart_parser_set_data(multipart_parser *parser, void *data);
extern int on_header_field(multipart_parser*, const char *at, size_t length);
extern int on_header_value(multipart_parser*, const char *at, size_t length);
extern int on_part_data(multipart_parser*, const char *at, size_t length);
extern int on_part_data_end(multipart_parser*);
extern void ogs_assert(void *ptr);
extern char *ogs_strndup(const char *str, size_t n);
extern void ogs_free(void *ptr);
extern void *ogs_pkbuf_alloc(void *pool, size_t size);
extern void *ogs_pkbuf_copy(void *pkbuf);
extern void ogs_pkbuf_put_data(void *pkbuf, const void *data, size_t len);
extern void ogs_error(const char *fmt, ...);
extern void ogs_log_hexdump(int level, const unsigned char *data, size_t len);
extern int ogs_expect_or_return_val(void *ptr, int val);
extern int parse_json(ogs_sbi_message_t *message, const char *content_type, const char *content);