#include <stddef.h>

typedef unsigned long OnigOptionType;

typedef struct OnigSyntaxType {
    int dummy;
} OnigSyntaxType;

#define ONIG_OPTION_IGNORECASE       (1<<0)
#define ONIG_OPTION_EXTEND           (1<<1)
#define ONIG_OPTION_MULTILINE        (1<<2)
#define ONIG_OPTION_SINGLELINE       (1<<3)
#define ONIG_OPTION_FIND_LONGEST     (1<<4)
#define ONIG_OPTION_FIND_NOT_EMPTY   (1<<5)

extern OnigSyntaxType *ONIG_SYNTAX_JAVA;
extern OnigSyntaxType *ONIG_SYNTAX_GNU_REGEX;
extern OnigSyntaxType *ONIG_SYNTAX_GREP;
extern OnigSyntaxType *ONIG_SYNTAX_EMACS;
extern OnigSyntaxType *ONIG_SYNTAX_RUBY;
extern OnigSyntaxType *ONIG_SYNTAX_PERL;
extern OnigSyntaxType *ONIG_SYNTAX_POSIX_BASIC;
extern OnigSyntaxType *ONIG_SYNTAX_POSIX_EXTENDED;