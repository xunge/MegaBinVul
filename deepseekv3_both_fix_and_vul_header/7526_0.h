#include <stddef.h>

#define OGS_SBI_MAX_NUM_OF_PART 16

typedef struct multipart_parser multipart_parser;

typedef struct {
    int num_of_part;
} multipart_parser_data_t;

static inline void ogs_assert(void *ptr) { (void)ptr; }
static multipart_parser_data_t *multipart_parser_get_data(multipart_parser *parser) { (void)parser; return NULL; }