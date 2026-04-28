#include <stdint.h>
#include <stddef.h>

#define ECMA_PARSE_DIRECT_EVAL (1 << 0)
#define SCANNER_PRIVATE_FIELD_ACTIVE (1 << 0)
#define SCANNER_SUCCESSFUL_CLASS_SCAN (1 << 1)
#define PARSER_ERR_UNDECLARED_PRIVATE_FIELD 0
#define LEXER_STRING_LITERAL 0

typedef struct lexer_lit_location_t {
    // implementation details
} lexer_lit_location_t;

typedef struct scanner_class_private_member_t {
    lexer_lit_location_t loc;
    struct scanner_class_private_member_t *prev_p;
} scanner_class_private_member_t;

typedef struct parser_private_context_t {
    uint32_t opts;
    scanner_class_private_member_t *members_p;
    struct parser_private_context_t *prev_p;
} parser_private_context_t;

typedef struct parser_token_t {
    lexer_lit_location_t lit_location;
} parser_token_t;

typedef struct parser_context_t {
    uint32_t global_status_flags;
    parser_private_context_t *private_context_p;
    parser_token_t token;
} parser_context_t;

int parser_resolve_private_identifier_eval(parser_context_t *context_p);
void parser_raise_error(parser_context_t *context_p, int error_code);
int lexer_compare_identifiers(parser_context_t *context_p, lexer_lit_location_t *a, lexer_lit_location_t *b);
void lexer_construct_literal_object(parser_context_t *context_p, lexer_lit_location_t *loc, int type);