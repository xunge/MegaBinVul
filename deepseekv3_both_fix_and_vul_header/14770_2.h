#include <stdbool.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define NIH_MUST(expr) (expr)
#define nih_local

char *nih_strdup(void *parent, const char *str);
char *nih_strcat(char **dest, void *parent, const char *src);

bool dir_exists(const char *path);
void ERROR(const char *fmt, ...);
void SYSERROR(const char *fmt, ...);