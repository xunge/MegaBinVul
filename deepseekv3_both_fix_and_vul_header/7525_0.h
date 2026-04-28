#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef struct multipart_parser multipart_parser;

typedef enum {
    OGS_SBI_CONTENT_TYPE,
    OGS_SBI_CONTENT_ID
} ogs_sbi_header_field_t;

typedef struct {
    char *content_type;
    char *content_id;
} multipart_part_t;

typedef struct {
    ogs_sbi_header_field_t header_field;
    multipart_part_t *part;
    size_t num_of_part;
} multipart_parser_data_t;

#define OGS_SBI_MAX_NUM_OF_PART 16

#define ogs_assert(expr) ((void)0)
#define ogs_free(ptr) free(ptr)
#define ogs_strndup(str, len) strndup(str, len)
#define ogs_error(fmt, ...) ((void)0)

#define SWITCH(x) switch(x) {
#define CASE(x) case x:
#define DEFAULT default:
#define END }

multipart_parser_data_t *multipart_parser_get_data(multipart_parser *parser);