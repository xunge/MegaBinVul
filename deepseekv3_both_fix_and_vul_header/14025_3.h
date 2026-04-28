#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PASSWD_FILE "/etc/passwd"
#define false 0
#define true 1

extern int lckpwdf(void);
extern int ulckpwdf(void);
extern int putpwent(const struct passwd *p, FILE *stream);
extern int pw_init(void);
extern FILE *xfmkstemp(char **name, const char *dir, ...);
extern int close_stream(FILE *stream);
extern int ignore_result(int x);