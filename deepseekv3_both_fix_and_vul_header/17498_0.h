#include <ctype.h>
#include <stddef.h>

typedef unsigned char char_u;

struct regexp {
    int reg_ic;
};

extern struct regexp rex;
extern int enc_utf8;
extern int has_mbyte;

#define MB_ISUPPER(c) isupper(c)
#define MB_ISLOWER(c) islower(c)
#define MB_TOLOWER(c) tolower(c)
#define MB_TOUPPER(c) toupper(c)
#define NUL '\0'

extern char_u *vim_strchr(char_u *s, int c);
extern int mb_char2len(int c);
extern int (*mb_ptr2len)(char_u *p);
extern int utf_fold(int c);
extern int utf_ptr2char(char_u *p);