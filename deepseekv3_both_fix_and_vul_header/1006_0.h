#include <stdlib.h>
#include <string.h>

#define NUL '\0'
#define OK 1
#define FAIL 0
#define TABSTOP_MAX 9999

typedef unsigned char char_u;

#define _(x) x
#define e_argument_must_be_positive "Argument must be positive"
#define e_invalid_argument_str "Invalid argument: %s"

#define VIM_ISDIGIT(c) ((c) >= '0' && (c) <= '9')

#define ALLOC_MULT(type, count) ((type *)malloc((count) * sizeof(type)))

void vim_free(void *ptr);
void emsg(const char *msg);
void semsg(const char *msg, const char *s);