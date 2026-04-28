#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

typedef double Sfdouble_t;

typedef struct Shell_t {
    int inarith;
} Shell_t;

extern bool Varsubscript;
extern int SH_DICT;
extern int arith;
extern const char *e_lexbadchar;

Sfdouble_t number(const char *, char **, int, void *);
Sfdouble_t strval(Shell_t *, const char *, char **, int, int);
int ERROR_exit(int);
void errormsg(int, int, const char *, char, const char *);
int sh_isstate(Shell_t *, int);
#define SH_INIT 1