#include <stdlib.h>
#include <string.h>

#define MAXCOL 1000
#define _(x) x
#define e_resulting_text_too_long "E123: Resulting text too long"

typedef char char_u;

extern char_u *reg_prev_sub;
extern int has_mbyte;

void *alloc(size_t size);
void vim_free(void *ptr);
char_u *vim_strsave(const char_u *str);
void emsg(const char *msg);
size_t STRLEN(const char_u *str);
void STRMOVE(char_u *dst, char_u *src);
void STRCPY(char_u *dst, char_u *src);
void *mch_memmove(void *dest, const void *src, size_t n);
int (*mb_ptr2len)(const char_u *p);