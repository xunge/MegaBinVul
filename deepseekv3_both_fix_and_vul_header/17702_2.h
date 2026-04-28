#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fnmatch.h>
#include <ctype.h>

typedef struct {
    char *buf;
    size_t cnt;
} BUF;

#define TYPE_OVERFLOW(type, val) (0)
extern int pflag;
extern int Tflag;
extern int targetshouldbedirectory;
extern int iamrecursive;
extern int iamremote;
extern int verbose_mode;
extern int remout;
extern int remin;
extern int showprogress;
extern char *curfile;
extern int errs;
extern ssize_t read(int, void *, size_t);
extern ssize_t write(int, const void *, size_t);
#define vwrite write
extern int atomicio(ssize_t (*)(int, void *, size_t), int, void *, size_t);
extern int atomicio6(ssize_t (*)(int, void *, size_t), int, void *, size_t, void *, off_t *);
extern void run_err(const char *, ...);
extern void fatal(const char *, ...);
extern void fmprintf(FILE *, const char *, ...);
extern void verifydir(const char *);
extern int brace_expand(const char *, char ***, size_t *);
extern BUF *allocbuf(BUF *, int, size_t);
extern void scpio(void);
extern void set_nonblock(int);
extern void unset_nonblock(int);
extern void start_progress_meter(const char *, off_t, off_t *);
extern void stop_progress_meter(void);
extern int response(void);
extern void *xmalloc(size_t);
extern char *xstrdup(const char *);
#define COPY_BUFLEN (8192)
#define snmprintf snprintf