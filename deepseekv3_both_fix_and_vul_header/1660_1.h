#include <stdio.h>
#include <string.h>

#define OS_FLSIZE 1024

extern char **exec_names;
extern char **exec_cmd;
extern int *exec_timeout;
extern int exec_size;
extern const char *AR_BINDIR;

void mwarn(const char *fmt, ...);