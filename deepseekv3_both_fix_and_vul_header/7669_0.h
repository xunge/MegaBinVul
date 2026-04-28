#include <string.h>

#define NUL '\0'
#define STRCAT(d, s) strcat((d), (s))
#define STRLEN(s) strlen((s))
#define STRCPY(d, s) strcpy((d), (s))
#define IOSIZE 1024
#define MB_COPY_CHAR(s, d) (*(d)++ = *(s)++)

typedef unsigned char char_u;

static char_u IObuff[IOSIZE];
static int enc_utf8;

int (*mb_ptr2len)(char_u *);