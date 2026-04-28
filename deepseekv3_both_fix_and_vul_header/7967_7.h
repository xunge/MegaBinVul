#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>

typedef int uerr_t;

#define RETROK 0
#define ON_YOUR_OWN (1 << 0)
#define DO_LIST (1 << 1)
#define LEAVE_PENDING (1 << 2)
#define DO_RETR (1 << 3)

#define LIST_FILENAME ".listing"

#define LOG_NOTQUIET 0
#define LOG_VERBOSE 1

#define _(x) x
#define quote(x) x
#define DEBUGP(x)

struct url {
    char *file;
};

struct fileinfo {
};

typedef struct ccon {
    char *target;
    int st;
    int cmd;
    char *rs;
} ccon;

struct {
    int remove_listing;
} opt;

char *url_file_name(struct url *u, void *arg);
char *file_merge(const char *base, const char *file);
void xfree(void *ptr);
char *xstrdup(const char *s);
uerr_t ftp_loop_internal(struct url *u, struct url *original_url, ccon *con, void *arg, bool flag, ...);
struct fileinfo *ftp_parse_ls(char *lf, char *rs);
void logprintf(int level, const char *fmt, ...);