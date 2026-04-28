#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define JERRY_ASSERT(expr) ((void)0)
#define LEXER_IDENT_LITERAL 0
#define LEXER_STRING_LITERAL 1
#define PARSER_MAXIMUM_IDENT_LENGTH 0
#define PARSER_MAXIMUM_STRING_LENGTH 0
#define PARSER_MAXIMUM_NUMBER_OF_LITERALS 0
#define LEXER_FLAG_UNUSED_IDENT 0
#define LEXER_FLAG_SOURCE_PTR 0
#define PARSER_ERR_LITERAL_LIMIT_REACHED 0

typedef struct parser_context_t parser_context_t;
typedef struct parser_list_iterator_t parser_list_iterator_t;
typedef struct lexer_literal_t lexer_literal_t;

struct parser_context_t {
    struct {
        lexer_literal_t *literal_p;
        uint16_t index;
    } lit_object;
    size_t literal_count;
    struct {
        /* literal_pool definition */
    } literal_pool;
};

struct parser_list_iterator_t {
    /* iterator fields */
};

struct lexer_literal_t {
    uint8_t type;
    struct {
        uint16_t length;
    } prop;
    union {
        uint8_t *char_p;
    } u;
    uint8_t status_flags;
};

void parser_list_iterator_init(void *pool, parser_list_iterator_t *iterator);
void *parser_list_iterator_next(parser_list_iterator_t *iterator);
void *parser_list_append(parser_context_t *context, void *pool);
void parser_raise_error(parser_context_t *context, int error_code);
void *jmem_heap_alloc_block(size_t size);