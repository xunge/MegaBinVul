#include <stdint.h>

typedef struct parser_context_t parser_context_t;

#define JERRY_UNUSED(x) ((void) (x))
#define JERRY_ASSERT(x) ((void) 0)
#define ENABLED(x) 1

enum {
    CBC_ASSIGN,
    CBC_PUSH_LITERAL,
    CBC_PUSH_TWO_LITERALS,
    CBC_PUSH_THIS_LITERAL,
    CBC_PUSH_THREE_LITERALS,
    CBC_ASSIGN_SET_IDENT,
    CBC_INIT_LET,
    CBC_ASSIGN_LET_CONST,
    CBC_INIT_CONST,
    CBC_INIT_ARG_OR_CATCH,
    CBC_PUSH_PROP,
    CBC_ASSIGN_PROP_LITERAL,
    CBC_PUSH_PROP_LITERAL,
    CBC_PUSH_PROP_LITERAL_LITERAL,
    CBC_PUSH_PROP_THIS_LITERAL,
    CBC_ASSIGN_PROP_THIS_LITERAL,
    CBC_PUSH_THIS,
    CBC_EXT_PUSH_SUPER_PROP_LITERAL,
    CBC_EXT_SUPER_PROP_LITERAL_ASSIGNMENT_REFERENCE,
    CBC_EXT_PUSH_SUPER_PROP,
    CBC_EXT_SUPER_PROP_ASSIGNMENT_REFERENCE,
    CBC_ASSIGN_SUPER,
    CBC_EXT_THROW_REFERENCE_ERROR
};

#define PARSER_IS_PUSH_LITERALS_WITH_THIS(x) 0
#define PARSER_CBC_UNAVAILABLE 0
#define PARSER_TO_EXT_OPCODE(x) (x)
#define CBC_SAME_ARGS(x, y) 1

#define LEXER_IDENT_LITERAL 0
#define LEXER_ASSIGN_GROUP_EXPR 0
#define LEXER_ASSIGN_CONST 0
#define LEXER_ASSIGN 0

#define PARSER_PATTERN_GROUP_EXPR 0
#define PARSER_PATTERN_LET 0
#define PARSER_PATTERN_CONST 0
#define PARSER_PATTERN_LOCAL 0
#define PARSER_REGISTER_START 0

struct parser_context_t {
    uint8_t last_cbc_opcode;
    struct {
        uint8_t literal_type;
        uint16_t literal_index;
        uint16_t value;
        uint16_t third_literal_index;
    } last_cbc;
};

static void parser_check_invalid_assign(parser_context_t *context_p);
static void parser_flush_cbc(parser_context_t *context_p);
static void parser_stack_push_uint8(parser_context_t *context_p, uint8_t value);
static void parser_stack_push_uint16(parser_context_t *context_p, uint16_t value);
static int scanner_literal_is_const_reg(parser_context_t *context_p, uint16_t literal_index);
static int scanner_literal_is_created(parser_context_t *context_p, uint16_t literal_index);
static void parser_emit_cbc_ext(parser_context_t *context_p, uint8_t opcode);
static void parser_check_invalid_new_target(parser_context_t *context_p, uint8_t opcode);