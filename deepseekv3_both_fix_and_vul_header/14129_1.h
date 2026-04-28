#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

extern char *applet;
extern void eerrorx(const char *fmt, ...);
extern void *xmalloc(size_t size);
extern char *xstrdup(const char *s);