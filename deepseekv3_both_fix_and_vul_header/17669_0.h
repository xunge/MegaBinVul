#include <stdbool.h>

#define TRUE 1
#define FALSE 0

extern int restricted;
extern void emsg(const char *msg);
#define _(x) x