#include <string.h>

typedef struct {
    int tk;
} Lexer;

extern Lexer *lex;
extern char *jslGetTokenValueAsString(void);
extern void jslTokenAsString(int tk, char *str, size_t len);

#define LEX_ID 0
#define LEX_STR 1