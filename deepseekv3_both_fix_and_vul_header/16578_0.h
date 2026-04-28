#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

typedef struct {
    char *buf;
    size_t cnt;
} BUF;

extern int pflag;
extern int verbose_mode;
extern int iamremote;
extern int errs;
extern int targetshouldbedirectory;
extern int iamrecursive;
extern int showprogress;
extern int limit_rate;
extern char *curfile;
extern int remout;
extern int remin;

void run_err(const char *fmt, ...);
void verifydir(char *);
void xfree(void *);
void *xmalloc(size_t);
char *xstrdup(const char *);
void bwlimit(int);
void response(void);
size_t atomicio(ssize_t (*)(int, void *, size_t), int, void *, size_t);
ssize_t vwrite(int, const void *, size_t);
ssize_t read(int, void *, size_t);
BUF *allocbuf(BUF *, int, int);