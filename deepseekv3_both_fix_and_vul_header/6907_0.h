#include <stddef.h>

typedef unsigned char char_u;

extern int enc_utf8;
extern int enc_dbcs;
extern int has_mbyte;

#define NUL '\0'

int utfc_ptr2len(const char_u *p);
int utf_ptr2char(const char_u *p);
int (*mb_ptr2len)(const char_u *p);