#include <limits.h>
#include <stddef.h>

#define FAIL 1
#define OK 0
#define FALSE 0
#define TRUE 1

typedef char char_u;
typedef long varnumber_T;

extern char_u *skipwhite(char_u *);
extern int vim_isdigit(int);
extern void vim_str2nr(char_u *, char **, int *, int, varnumber_T *, char **, int, int, int *);