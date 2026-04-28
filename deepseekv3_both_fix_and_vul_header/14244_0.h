#include <stdlib.h>
#include <string.h>

#define NUL '\0'
#define STRNICMP strncasecmp
#define STRCMP strcmp
#define STRCPY strcpy
#define ARRAY_LENGTH(x) (sizeof(x) / sizeof((x)[0]))
#define OK 1
#define MAXCOL 1000
#define TAG_HELP 0x01
#define TAG_REGEXP 0x02
#define TAG_NAMES 0x04
#define TAG_VERBOSE 0x08
#define TAG_NO_TAGFUNC 0x10
#define TAG_KEEP_LANG 0x20
#define TAG_MANY 100
#define IOSIZE 1024
#define ASCII_ISALPHA(c) (isalpha((unsigned char)(c)))

typedef unsigned char char_u;

char_u IObuff[IOSIZE];

int find_tags(char_u *name, int *num_matches, char_u ***matches, int flags, int maxcount, char_u *buf);
int help_compare(const void *s1, const void *s2);
void *mch_memmove(void *dest, const void *src, size_t n);
char_u *vim_strchr(const char_u *string, int c);
void vim_free(void *ptr);