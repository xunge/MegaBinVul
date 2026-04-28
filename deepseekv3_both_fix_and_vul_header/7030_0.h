#include <stddef.h>

#define linenr_T int
#define char_u unsigned char
#define FALSE 0
#define TRUE 1
#define COM_FIRST 'f'
#define COM_END 'e'
#define COM_START 's'
#define COM_MIDDLE 'm'
#define NUL '\0'

#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')

char_u *ml_get(linenr_T lnum);
char_u *vim_strsave(const char_u *str);
void vim_free(void *ptr);