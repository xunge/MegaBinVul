#include <stddef.h>

typedef unsigned long OnigOptionType;
typedef struct _OnigSyntaxType OnigSyntaxType;

typedef struct _php_mb_regex_globals {
    OnigOptionType regex_default_options;
    OnigSyntaxType *regex_default_syntax;
} php_mb_regex_globals;

#define MBREX(v) (mb_regex_globals.v)
#define TSRMLS_DC

extern php_mb_regex_globals mb_regex_globals;