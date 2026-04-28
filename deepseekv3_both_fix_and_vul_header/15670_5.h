#include <stddef.h>

typedef struct optset {
    void *os_varp;
    char *os_errbuf;
    size_t os_errbuflen;
} optset_T;

typedef unsigned char char_u;

#define COM_ALL "nmb"
#define VIM_ISDIGIT(c) ((c) >= '0' && (c) <= '9')
#define NUL '\0'

extern char *e_missing_colon;
extern char *e_zero_length_string;

char *illegal_char(char *buf, ...);
char_u *vim_strchr(const char_u *str, int c);
char_u *skip_to_option_part(char_u *s);