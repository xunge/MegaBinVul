#include <stdint.h>

typedef uint32_t parser_line_counter_t;

typedef enum
{
  LEXER_LITERAL,
  /* other token types */
} lexer_token_type_t;

typedef enum
{
  LEXER_IDENT_LITERAL,
  /* other literal types */
} lexer_literal_type_t;

typedef struct
{
  const char *char_p;
  lexer_literal_type_t type;
} lexer_lit_location_t;

typedef struct
{
  lexer_token_type_t type;
  lexer_lit_location_t lit_location;
} lexer_token_t;

typedef struct parser_context_t
{
  const char *source_p;
  parser_line_counter_t line;
  parser_line_counter_t column;
  lexer_token_t token;
} parser_context_t;

typedef enum
{
  PARSER_ERR_IDENTIFIER_EXPECTED,
  /* other error codes */
} parser_error_t;

void lexer_next_token(parser_context_t *context_p);
void lexer_construct_literal_object(parser_context_t *context_p,
                                   lexer_lit_location_t *lit_location_p,
                                   lexer_literal_type_t literal_type);
void parser_raise_error(parser_context_t *context_p, parser_error_t error);