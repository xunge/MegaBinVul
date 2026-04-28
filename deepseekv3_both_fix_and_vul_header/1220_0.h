#include <stddef.h>

#define NUL '\0'
#define FAIL 1
#define OK 0

typedef unsigned char char_u;

extern char_u *vim_strchr(char_u *str, int c);
extern int script_is_vim9(void);
extern void semsg(const char *msg, ...);

#define _(x) x
#define e_argument_required_for_str ""
#define e_cannot_unlet_str ""