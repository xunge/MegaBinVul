#include <stdint.h>
#include <stdio.h>

typedef void* yyscan_t;
#define RE_YY_INPUT(yyscanner) getc(yyscanner)

uint8_t escaped_char_value(char text[4]);