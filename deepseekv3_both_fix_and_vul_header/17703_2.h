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
#include <fnmatch.h>

typedef struct {
    char *buf;
    size_t cnt;
} BUF;

#define TYPE_OVERFLOW(type, val) \
    ((val) < (type)0 && (val) != (type)(val))

extern int pflag;
extern int Tflag;
extern int iamrecursive;
extern int iamremote;
extern int verbose_mode;
extern int targetshouldbedirectory;
extern int showprogress;
extern int errs;
extern int remout;
extern int remin;
#define STDERR_FILENO 2
extern int COPY_BUFLEN;
extern char *curfile;

extern int atomicio(ssize_t (*)(int, void *, size_t), int, void *, size_t);
extern int atomicio6(ssize_t (*)(int, void *, size_t), int, void *, size_t, void *, off_t *);
extern void fmprintf(FILE *, const char *, ...);
extern void run_err(const char *, ...);
extern int note_err(const char *, ...);
extern void fatal(const char *, ...);
extern int brace_expand(const char *, char ***, size_t *);
extern void verifydir(const char *);
extern void set_nonblock(int);
extern void unset_nonblock(int);
extern void start_progress_meter(const char *, off_t, off_t *);
extern void stop_progress_meter(void);
extern int response(void);
extern int scpio(void *, off_t *);
extern ssize_t vwrite(int, void *, size_t);
extern ssize_t read(int, void *, size_t);
extern char *xstrdup(const char *);
extern void *xmalloc(size_t);
extern BUF *allocbuf(BUF *, int, size_t);
extern int snmprintf(char *, size_t, void *, const char *, ...);