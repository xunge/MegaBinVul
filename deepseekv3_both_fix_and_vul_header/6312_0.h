#include <stdlib.h>
#include <string.h>

#define NUL '\0'
#define OK 1
#define FAIL 0
#define TRUE 1
#define FALSE 0

typedef unsigned char char_u;

#define _(x) x
#define e_positive "Epositive"
#define e_invarg "Einvarg"
#define e_invarg2 "Einvarg2"

#define VIM_ISDIGIT(c) ((c) >= '0' && (c) <= '9')

#define ALLOC_MULT(type, count) ((type *)malloc((count) * sizeof(type)))

void emsg(const char *msg);
void semsg(const char *msg, const char *arg);