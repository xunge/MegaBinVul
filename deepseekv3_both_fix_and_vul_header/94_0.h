#include <stddef.h>

#define TRUE 1
#define FALSE 0
#define NUL '\0'
#define K_SPECIAL 0x80
#define KS_MODIFIER 0x80
#define IS_SPECIAL(c) ((c) >= K_SPECIAL)
#define TO_SPECIAL(x, y) ((x) << 8 | (y))
#define MB_BYTE2LEN(c) 1

typedef unsigned char char_u;

extern int has_mbyte;
extern char_u *mb_unescape(char_u **);
extern char_u *get_special_key_name(int, int);
extern int (*mb_ptr2char)(char_u *);