#include <stdlib.h>
#include <string.h>

typedef unsigned char char_u;

#define STRLEN strlen
#define STRCPY strcpy
#define STRMOVE(dest, src) memmove(dest, src, strlen(src) + 1)
#define alloc malloc
#define vim_free free
#define vim_strsave strdup

extern char_u *reg_prev_sub;
extern int has_mbyte;
int (*mb_ptr2len)(char_u *);
void *mch_memmove(void *dest, const void *src, size_t n);