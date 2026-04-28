#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <locale.h>

extern char *tmp_file;
extern FILE *xfmkstemp(char **tmpname, const char *dir, ...);
extern void ulckpwdf(void);
extern void copyfile(int srcfd, int destfd);
extern const char *_(const char *str);