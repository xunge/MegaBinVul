#include <stddef.h>
#include <string.h>

#define NUL '\0'
#define TRUE 1
#define FALSE 0

typedef unsigned char char_u;

int has_mbyte;
int enc_dbcs;
int enc_utf8;

int ptr2cells(char_u *p);
int utf_iscomposing(int c);
int utf_ptr2char(char_u *p);
int utf_head_off(char_u *s, char_u *p);
int (*mb_ptr2len)(char_u *p);
size_t vim_strsize(char_u *s);
size_t STRLEN(const char_u *s);
void mch_memmove(void *dest, const void *src, size_t n);