#include <assert.h>
#include <string.h>
#include <stdio.h>

#define LEX_EOF 0
#define LEX_ID 1
#define LEX_INT 2
#define LEX_FLOAT 3
#define LEX_STR 4
#define LEX_UNFINISHED_STR 5
#define LEX_TEMPLATE_LITERAL 6
#define LEX_UNFINISHED_TEMPLATE_LITERAL 7
#define LEX_REGEX 8
#define LEX_UNFINISHED_REGEX 9
#define LEX_UNFINISHED_COMMENT 10

#define _LEX_OPERATOR_START 11
#define _LEX_R_LIST_END 50

int espruino_snprintf(char *str, size_t len, const char *format, ...);