#include <string.h>

#define char_u unsigned char
#define NUL '\0'
#define STRCAT strcat
#define STRLEN strlen
#define STRCPY strcpy
#define IOSIZE 1024
#define IObuff iobuff
static char_u iobuff[IOSIZE];
static int enc_utf8;
static int (*mb_ptr2len)(const char_u *);
#define MB_COPY_CHAR(s, d) (*d++ = *s++)