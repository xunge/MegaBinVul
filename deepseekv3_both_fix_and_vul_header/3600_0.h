#include <assert.h>
#include <limits.h>
#include <string.h>

#define DIS_BUFSIZ 256
#define FALSE 0
#define DIS_EOD -1
#define DIS_NONDIGIT -2
#define DIS_LEADZRO -3
#define DIS_EOF -4
#define DIS_OVERFLOW -5
#define DIS_SUCCESS 0

extern int (*dis_getc)(int);
extern int (*dis_gets)(int, char *, unsigned);
extern unsigned dis_umaxd;
extern char *dis_umax;
extern void disiui_(void);