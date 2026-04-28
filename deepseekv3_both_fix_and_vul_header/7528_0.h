#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct multipart_parser multipart_parser;
typedef struct multipart_parser_data_t multipart_parser_data_t;

enum {
    OGS_SBI_CONTENT_JSON_TYPE = 1,
    OGS_SBI_CONTENT_5GNAS_TYPE,
    OGS_SBI_CONTENT_NGAP_TYPE
};

#define OGS_HUGE_LEN 1024
#define OGS_SBI_MAX_NUM_OF_PART 16
#define OGS_LOG_ERROR 1
#define OGS_LOG_FATAL 2

#define ogs_assert(expr) 
#define ogs_assert_if_reached() 
#define ogs_error(fmt, ...) 
#define ogs_log_hexdump(level, data, len) 
#define ogs_malloc(size) malloc(size)
#define ogs_realloc(ptr, size) realloc(ptr, size)

#define SWITCH(x) switch((intptr_t)(x)) {
#define CASE(x) case x:
#define DEFAULT default:
#define END }

struct multipart_parser_data_t {
    struct {
        const char *content_type;
        char *content;
        size_t content_length;
    } part[16];
    int num_of_part;
};

static multipart_parser_data_t *multipart_parser_get_data(multipart_parser *parser) { return NULL; }