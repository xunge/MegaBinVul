#include <string.h>
#include <stddef.h>

#define ERR_BUFLEN 80
#define VIM_ISDIGIT(c) ((c) >= '0' && (c) <= '9')
#define STL_TRUNCMARK '#'
#define STL_SEPARATE '='
#define STL_USER_HL '*'
#define STL_ALL "%#=*-0123456789()."

typedef unsigned char char_u;

static inline char *vim_strchr(const char *s, int c) {
    return strchr(s, c);
}

extern char *illegal_char_3args(char *errbuf, int errbuflen, int c);
extern char *illegal_char_2args(char *errbuf, int c);
extern char *e_unclosed_expression_sequence;
extern char *e_unbalanced_groups;