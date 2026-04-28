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

#define TYPE_OVERFLOW(type, val) (0)
#define pflag (0)
#define verbose_mode (0)
#define iamremote (0)
static int errs = 0;
#define targetshouldbedirectory (0)
#define remout (1)
#define remin (0)
#define vwrite write
#define STDERR_FILENO 2
#define COPY_BUFLEN (1024*1024)
#define showprogress (0)
#define iamrecursive (0)
#define O_WRONLY 01
#define O_CREAT 0100
#define EPIPE 32

extern int atomicio(ssize_t (*)(int, const void *, size_t), int, void *, size_t);
extern int atomicio6(ssize_t (*)(int, const void *, size_t), int, void *, size_t, void *, void *);
extern void run_err(const char *, ...);
extern void fmprintf(FILE *, const char *, ...);
extern void verifydir(const char *);
extern BUF *allocbuf(BUF *, int, size_t);
extern void set_nonblock(int);
extern void unset_nonblock(int);
extern void start_progress_meter(const char *, off_t, off_t *);
extern void stop_progress_meter();
extern int scpio(void *, void *, size_t);
extern int response(void);
extern char *xstrdup(const char *);
extern void *xmalloc(size_t);
extern char *curfile;