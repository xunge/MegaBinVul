#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#define RPMERR_ENOENT 1
#define RPMERR_UNLINK_FAILED 2

typedef struct rpmfi_s *rpmfi;
typedef unsigned int mode_t;

extern int fsmStat(const char *path, int follow, struct stat *sb);
extern int fsmRename(const char *oldpath, const char *newpath);
extern int fsmUnlink(const char *path);
extern int fsmReadLink(const char *path, char *buf, size_t bufsiz, size_t *len);
extern char *rstrscat(char *str, ...);
extern mode_t rpmfiFMode(rpmfi fi);
extern const char *rpmfiFLink(rpmfi fi);
extern dev_t rpmfiFRdev(rpmfi fi);
extern int rstreq(const char *s1, const char *s2);