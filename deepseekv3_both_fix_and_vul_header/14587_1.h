#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct parser_context_t parser_context_t;

typedef struct scanner_literal_pool_t {
    struct scanner_literal_pool_t *prev_p;
    uint16_t status_flags;
    void *literal_pool;
} scanner_literal_pool_t;

typedef struct scanner_context_t {
    scanner_literal_pool_t *active_literal_pool_p;
} scanner_context_t;

typedef struct parser_list_iterator_t {
    void *current;
    void *list;
} parser_list_iterator_t;

typedef struct lexer_lit_location_t {
    uint8_t type;
} lexer_lit_location_t;

#define SCANNER_LITERAL_POOL_CAN_EVAL (1 << 0)
#define SCANNER_LITERAL_POOL_NO_ARGUMENTS (1 << 1)
#define SCANNER_LITERAL_POOL_ARGUMENTS_IN_ARGS (1 << 2)
#define SCANNER_LITERAL_POOL_MAY_HAVE_ARGUMENTS(flags) ((flags) & 0x4)

#define SCANNER_LITERAL_EARLY_CREATE (1 << 0)
#define SCANNER_LITERAL_NO_REG (1 << 1)
#define SCANNER_LITERAL_IS_ARG (1 << 2)
#define SCANNER_LITERAL_IS_DESTRUCTURED_ARG (1 << 3)
#define SCANNER_LITERAL_IS_ARROW_DESTRUCTURED_ARG (1 << 4)
#define SCANNER_LITERAL_IS_USED (1 << 5)

#define JERRY_ASSERT(expr) ((void)0)

void *scanner_malloc(parser_context_t *context_p, size_t size);
void scanner_free(void *ptr, size_t size);
void parser_list_init(void *list, size_t element_size, uint32_t elements);
void parser_list_iterator_init(void *list, parser_list_iterator_t *iterator);
void *parser_list_iterator_next(parser_list_iterator_t *iterator);
void *parser_list_append(parser_context_t *context_p, void *list);
void parser_list_free(void *list);
bool scanner_literal_is_arguments(lexer_lit_location_t *literal_p);
lexer_lit_location_t *scanner_add_custom_literal(parser_context_t *context_p, scanner_literal_pool_t *pool_p, lexer_lit_location_t *literal_p);