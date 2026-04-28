#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct parser_context_t {
    struct {
        uint8_t type;
        uint8_t keyword_type;
        struct {
            uint8_t type;
        } lit_location;
        uint16_t line;
        uint16_t column;
    } token;
    uint8_t stack_top_uint8;
    uint32_t status_flags;
    struct {
        void *source_p;
        uint8_t type;
        uint8_t u8_arg;
    } *next_scanner_info_p;
    struct {
        uint16_t index;
        struct lexer_literal_t *literal_p;
    } lit_object;
    uint8_t scope_stack_top;
    struct parser_scope_stack_t *scope_stack_p;
    uint8_t scope_stack_global_end;
    void *source_p;
} parser_context_t;

typedef struct lexer_literal_t {
    uint8_t type;
    uint8_t status_flags;
    union {
        void *bytecode_p;
        uint8_t *char_p;
    } u;
    struct {
        size_t length;
    } prop;
} lexer_literal_t;

typedef struct ecma_compiled_code_t ecma_compiled_code_t;

typedef struct parser_stack_iterator_t {
    void *data;
} parser_stack_iterator_t;

typedef struct parser_label_statement_t {
    uint8_t type;
} parser_label_statement_t;

typedef struct parser_scope_stack_t {
    uint16_t map_from;
    uint16_t map_to;
} parser_scope_stack_t;

typedef enum {
    LEXER_KEYW_FUNCTION,
    LEXER_LITERAL,
    LEXER_NEW_IDENT_LITERAL,
    LEXER_FIRST_NON_STRICT_ARGUMENTS
} lexer_token_type_t;

typedef enum {
    LEXER_IDENT_LITERAL,
    LEXER_UNUSED_LITERAL,
    LEXER_FUNCTION_LITERAL
} lexer_literal_type_t;

typedef enum {
    PARSER_STATEMENT_IF,
    PARSER_STATEMENT_ELSE,
    PARSER_STATEMENT_LABEL,
    PARSER_STATEMENT_PRIVATE_SCOPE,
    PARSER_STATEMENT_PRIVATE_CONTEXT
} parser_statement_type_t;

typedef enum {
    SCANNER_TYPE_ERR_REDECLARED,
    SCANNER_TYPE_FUNCTION
} scanner_type_t;

typedef enum {
    PARSER_ERR_LEXICAL_SINGLE_STATEMENT,
    PARSER_ERR_LABELLED_FUNC_NOT_IN_BLOCK,
    PARSER_ERR_VARIABLE_REDECLARED
} parser_error_t;

typedef enum {
    CBC_ASSIGN_LITERAL_SET_IDENT,
    CBC_COPY_TO_GLOBAL
} cbc_opcode_t;

typedef uint8_t parser_line_counter_t;

#define ENABLED(x) (x)
#define JERRY_ES2015 1
#define JERRY_DEBUGGER 1
#define JERRY_ES2015_MODULE_SYSTEM 1
#define JERRY_UNLIKELY(x) (x)
#define JERRY_ASSERT(x)
#define PARSER_STATM_SINGLE_STATM 0
#define PARSER_STATM_HAS_BLOCK 0
#define PARSER_IS_STRICT 0
#define PARSER_SCOPE_STACK_FUNC 0
#define PARSER_SCOPE_STACK_NO_FUNCTION_COPY 0
#define PARSER_REGISTER_START 0
#define PARSER_FUNCTION_CLOSURE 0
#define PARSER_HAS_NON_STRICT_ARG 0
#define PARSER_IS_GENERATOR_FUNCTION 0
#define PARSER_DISALLOW_AWAIT_YIELD 0
#define PARSER_IS_ASYNC_FUNCTION 0
#define PARSER_MODULE_STORE_IDENT 0
#define SCANNER_FUNCTION_ASYNC 0
#define JERRY_DEBUGGER_CONNECTED 0
#define JERRY_DEBUGGER_FUNCTION_NAME 0
#define JERRY_DEBUGGER_NO_SUBTYPE 0
#define PARSER_GET_LITERAL(x) ((lexer_literal_t*)(x))
#define JERRY_CONTEXT(x) (x)

extern uint8_t parser_statement_flags[];
extern uint8_t debugger_flags;

void parser_raise_error(parser_context_t *context_p, parser_error_t error);
void parser_push_block_context(parser_context_t *context_p, bool flag);
void parser_stack_iterator_init(parser_context_t *context_p, parser_stack_iterator_t *iterator);
void parser_stack_iterator_skip(parser_stack_iterator_t *iterator, size_t size);
uint8_t parser_stack_iterator_read_uint8(parser_stack_iterator_t *iterator);
bool lexer_consume_generator(parser_context_t *context_p);
void lexer_expect_identifier(parser_context_t *context_p, lexer_token_type_t type);
void parser_module_append_export_name(parser_context_t *context_p);
void parser_emit_cbc_literal_value(parser_context_t *context_p, cbc_opcode_t opcode, uint16_t a, uint16_t b);
void parser_flush_cbc(parser_context_t *context_p);
void parser_pop_block_context(parser_context_t *context_p);
ecma_compiled_code_t *parser_parse_function(parser_context_t *context_p, uint32_t flags);
void ecma_bytecode_deref(ecma_compiled_code_t *bytecode_p);
void parser_compiled_code_set_function_name(parser_context_t *context_p, ecma_compiled_code_t *compiled_code_p, uint16_t index, uint8_t flags);
void lexer_next_token(parser_context_t *context_p);
void jerry_debugger_send_string(uint8_t type, uint8_t subtype, const uint8_t *str, size_t length);
uint16_t scanner_decode_map_to(parser_scope_stack_t *stack_p);