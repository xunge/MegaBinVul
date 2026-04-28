#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef enum {
    LEXER_LEFT_BRACE,
    LEXER_RIGHT_BRACE,
    LEXER_HASHMARK,
    LEXER_KEYW_STATIC,
    LEXER_LITERAL,
    LEXER_PROPERTY_GETTER,
    LEXER_PROPERTY_SETTER,
    LEXER_KEYW_ASYNC,
    LEXER_MULTIPLY,
    LEXER_RIGHT_SQUARE,
    LEXER_NUMBER_LITERAL,
    LEXER_IDENT_LITERAL,
    LEXER_STRING_LITERAL,
    LEXER_FUNCTION_LITERAL
} lexer_token_type_t;

typedef enum {
    PARSER_CLASS_LITERAL_CTOR_PRESENT,
    PARSER_CLASS_LITERAL_HERTIAGE_PRESENT
} parser_class_literal_opts_t;

typedef enum {
    CBC_PUSH_LITERAL,
    CBC_SET_LITERAL_PROPERTY
} cbc_opcode_t;

typedef enum {
    CBC_EXT_PUSH_IMPLICIT_CONSTRUCTOR_HERITAGE,
    CBC_EXT_PUSH_IMPLICIT_CONSTRUCTOR,
    CBC_EXT_SET_CLASS_NAME,
    CBC_EXT_INIT_CLASS,
    CBC_EXT_SET_COMPUTED_GETTER,
    CBC_EXT_SET_COMPUTED_SETTER,
    CBC_EXT_SET_STATIC_GETTER,
    CBC_EXT_SET_STATIC_SETTER,
    CBC_EXT_COLLECT_PRIVATE_GETTER,
    CBC_EXT_COLLECT_PRIVATE_SETTER,
    CBC_EXT_COLLECT_PRIVATE_STATIC_GETTER,
    CBC_EXT_COLLECT_PRIVATE_STATIC_SETTER,
    CBC_EXT_SET_COMPUTED_GETTER_NAME,
    CBC_EXT_SET_COMPUTED_SETTER_NAME,
    CBC_EXT_SET_STATIC_COMPUTED_GETTER,
    CBC_EXT_SET_STATIC_COMPUTED_SETTER,
    CBC_EXT_SET_COMPUTED_FUNCTION_NAME,
    CBC_EXT_SET_STATIC_COMPUTED_PROPERTY,
    CBC_EXT_SET_COMPUTED_PROPERTY,
    CBC_EXT_COLLECT_PRIVATE_STATIC_METHOD,
    CBC_EXT_COLLECT_PRIVATE_METHOD,
    CBC_EXT_SET_STATIC_PROPERTY_LITERAL,
    CBC_EXT_COLLECT_PRIVATE_STATIC_FIELD,
    CBC_EXT_COLLECT_PRIVATE_FIELD,
    CBC_EXT_PUSH_STATIC_COMPUTED_FIELD_FUNC,
    CBC_EXT_ADD_STATIC_COMPUTED_FIELD,
    CBC_EXT_ADD_COMPUTED_FIELD,
    CBC_EXT_SET_FIELD_INIT,
    CBC_EXT_PUSH_STATIC_FIELD_FUNC,
    CBC_EXT_SET_GETTER,
    CBC_EXT_SET_SETTER
} cbc_ext_opcode_t;

typedef enum {
    PARSER_FUNCTION_CLOSURE,
    PARSER_ALLOW_SUPER,
    PARSER_CLASS_CONSTRUCTOR,
    PARSER_LEXICAL_ENV_NEEDED,
    PARSER_ALLOW_SUPER_CALL,
    PARSER_INSIDE_WITH,
    PARSER_IS_PROPERTY_GETTER,
    PARSER_IS_PROPERTY_SETTER,
    PARSER_IS_ASYNC_FUNCTION,
    PARSER_DISALLOW_AWAIT_YIELD,
    PARSER_IS_METHOD,
    PARSER_PRIVATE_FUNCTION_NAME,
    PARSER_IS_GENERATOR_FUNCTION
} parser_status_flags_t;

typedef enum {
    LEXER_OBJ_IDENT_CLASS_IDENTIFIER,
    LEXER_OBJ_IDENT_SET_FUNCTION_START,
    LEXER_OBJ_IDENT_CLASS_NO_STATIC,
    LEXER_OBJ_IDENT_CLASS_PRIVATE,
    LEXER_OBJ_IDENT_ONLY_IDENTIFIERS
} lexer_obj_ident_flags_t;

typedef enum {
    SCANNER_PRIVATE_FIELD_PROPERTY_GETTER_SETTER,
    SCANNER_PRIVATE_FIELD_GETTER,
    SCANNER_PRIVATE_FIELD_SETTER
} scanner_private_field_type_t;

typedef enum {
    SCANNER_TYPE_CLASS_STATIC_BLOCK_END,
    SCANNER_TYPE_CLASS_FIELD_INITIALIZER_END,
    SCANNER_TYPE_FUNCTION
} scanner_type_t;

typedef enum {
    PARSER_CLASS_FIELD_END,
    PARSER_CLASS_FIELD_STATIC,
    PARSER_CLASS_FIELD_NORMAL,
    PARSER_CLASS_FIELD_INITIALIZED,
    PARSER_CLASS_FIELD_STATIC_BLOCK
} parser_class_field_type_t;

typedef enum {
    PARSER_ERR_CLASS_PRIVATE_CONSTRUCTOR,
    PARSER_ERR_MULTIPLE_CLASS_CONSTRUCTORS,
    PARSER_ERR_CLASS_STATIC_PROTOTYPE,
    PARSER_ERR_CLASS_CONSTRUCTOR_AS_ACCESSOR,
    PARSER_ERR_INVALID_CLASS_CONSTRUCTOR,
    PARSER_ERR_ARGUMENT_LIST_EXPECTED,
    PARSER_ERR_TOO_MANY_CLASS_FIELDS,
    PARSER_ERR_SEMICOLON_EXPECTED
} parser_error_t;

typedef struct scanner_location_t {
    uint8_t *source_p;
    uint16_t line;
    uint16_t column;
} scanner_location_t;

typedef struct scanner_range_t {
    scanner_location_t start_location;
    uint8_t *source_end_p;
} scanner_range_t;

typedef struct scanner_location_info_t {
    scanner_location_t location;
    scanner_type_t type;
    uint8_t *source_p;
} scanner_location_info_t;

typedef struct parser_context_t {
    struct {
        lexer_token_type_t type;
        struct {
            uint8_t type;
            uint8_t *char_p;
        } lit_location;
        uint8_t flags;
        uint16_t line;
        uint16_t column;
    } token;
    uint16_t literal_count;
    struct {
        uint16_t index;
    } lit_object;
    uint8_t status_flags;
    scanner_location_info_t *next_scanner_info_p;
    uint8_t *source_p;
    uint8_t stack_top_uint8;
    struct {
        cbc_opcode_t opcode;
        uint16_t literal_index;
        uint16_t value;
    } last_cbc;
    cbc_opcode_t last_cbc_opcode;
} parser_context_t;

typedef struct lexer_literal_t {
    uint8_t type;
    union {
        struct ecma_compiled_code_t *bytecode_p;
    } u;
} lexer_literal_t;

typedef struct ecma_compiled_code_t {
    // Placeholder for compiled code structure
} ecma_compiled_code_t;

#define PARSER_INVALID_LITERAL_INDEX UINT16_MAX
#define ECMA_INTEGER_NUMBER_MAX UINT32_MAX
#define LEXER_NO_SKIP_SPACES (1 << 0)
#define LEXER_WAS_NEWLINE (1 << 1)
#define LEXER_IS_IDENT_OR_STRING(type) ((type) == LEXER_IDENT_LITERAL || (type) == LEXER_STRING_LITERAL)
#define LIT_CHAR_LEFT_PAREN '('
#define LIT_CHAR_SEMICOLON ';'
#define LIT_CHAR_RIGHT_BRACE '}'
#define LIT_CHAR_HASHMARK '#'
#define LIT_CHAR_LEFT_BRACE '{'
#define LIT_CHAR_RIGHT_SQUARE ']'
#define PARSE_EXPR_NO_COMMA 0
#define JERRY_ASSERT(expr) ((void)0)
#define PARSER_TO_EXT_OPCODE(opcode) ((cbc_opcode_t)((opcode) + 0x100))

/* Function declarations */
lexer_literal_t *lexer_construct_unused_literal(parser_context_t *context_p);
void parser_emit_cbc_literal(parser_context_t *context_p, cbc_opcode_t opcode, uint16_t literal_index);
void parser_emit_cbc_ext(parser_context_t *context_p, cbc_ext_opcode_t opcode);
void parser_emit_cbc_ext_literal(parser_context_t *context_p, cbc_ext_opcode_t opcode, uint16_t literal_index);
void lexer_skip_empty_statements(parser_context_t *context_p);
void lexer_expect_object_literal_id(parser_context_t *context_p, uint32_t flags);
void lexer_next_token(parser_context_t *context_p);
void parser_check_duplicated_private_field(parser_context_t *context_p, scanner_private_field_type_t type);
bool parser_is_constructor_literal(parser_context_t *context_p);
bool lexer_check_next_character(parser_context_t *context_p, uint8_t character);
void parser_raise_error(parser_context_t *context_p, parser_error_t error);
void parser_flush_cbc(parser_context_t *context_p);
ecma_compiled_code_t *parser_parse_function(parser_context_t *context_p, uint32_t status_flags);
uint16_t lexer_construct_function_object(parser_context_t *context_p, uint32_t status_flags);
void parser_set_function_name(parser_context_t *context_p, uint16_t function_literal_index, uint16_t literal_index, uint32_t status_flags);
void parser_stack_push_uint8(parser_context_t *context_p, uint8_t value);
void parser_stack_push(parser_context_t *context_p, void *data, size_t size);
void parser_reverse_class_fields(parser_context_t *context_p, size_t fields_size);
void parser_stack_pop_uint8(parser_context_t *context_p);
void lexer_construct_literal_object(parser_context_t *context_p, void *lit_location, uint8_t type);
void parser_emit_cbc_ext_literal_from_token(parser_context_t *context_p, cbc_ext_opcode_t opcode);
void scanner_get_location(scanner_location_t *location, parser_context_t *context_p);
void scanner_set_location(parser_context_t *context_p, scanner_location_t *location);
void scanner_release_next(parser_context_t *context_p, size_t size);
void scanner_seek(parser_context_t *context_p);
void lexer_consume_next_character(parser_context_t *context_p);
bool lexer_consume_assign(parser_context_t *context_p);
void parser_parse_expression(parser_context_t *context_p, int flags);
bool lexer_check_next_characters(parser_context_t *context_p, uint8_t char1, uint8_t char2);
void parser_parse_class_static_block(parser_context_t *context_p);
void parser_resolve_private_identifier(parser_context_t *context_p);
void lexer_construct_number_object(parser_context_t *context_p, bool is_hex, bool is_binary);
bool lexer_consume_generator(parser_context_t *context_p);
bool lexer_compare_identifier_to_string(void *lit_location, uint8_t *str, size_t length);
bool lexer_compare_literal_to_string(parser_context_t *context_p, const char *str, size_t length);
ecma_compiled_code_t *parser_parse_class_fields(parser_context_t *context_p);