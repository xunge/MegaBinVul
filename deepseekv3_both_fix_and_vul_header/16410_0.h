#include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>

typedef struct {
    char *cwd;
} ctrl_t;

extern int chrooted;
extern char *home;

#define PATH_MAX 4096
#define DBG(fmt, ...)
#define INFO(fmt, ...)