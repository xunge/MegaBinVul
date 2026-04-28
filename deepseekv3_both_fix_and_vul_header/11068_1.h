#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <syslog.h>

#define max_ls_depth 100
#define max_ls_files 1000
#define opt_a 0
#define opt_R 0
#define matches 0
#define PATH_MAX 4096
#define MSG_CANT_READ_FILE "Can't read file"
#define LOG_ERR 3

#define ALLOCA(size) alloca(size)
#define ALLOCA_FREE(ptr)
#define wd "."

typedef struct {
    size_t name_offset;
} PureFileInfo;

#define FI_NAME(s) ((char *)(s) + (s)->name_offset)

static PureFileInfo *sreaddir(char **names);
static void addreply(int code, const char *msg, const char *name);
static int listfile(PureFileInfo *s, void *arg);
static void outputfiles(int f, void *tls_fd);
static void wrstr(int f, void *tls_fd, const char *str);
static void die(int code, int priority, const char *fmt, const char *msg);

#define SNCHECK(x, size) ((x) < 0 || (size_t)(x) >= (size))