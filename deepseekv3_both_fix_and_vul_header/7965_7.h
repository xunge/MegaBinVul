#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int uerr_t;

struct url {
    char *dir;
};

struct fileinfo {
    char *name;
    int type;
    struct fileinfo *next;
};

typedef struct ccon {
    int st;
} ccon;

enum {
    FT_DIRECTORY,
    DONE_CWD,
    GLOB_GETALL,
    QUOTEXC,
    RETROK,
    LOG_VERBOSE
};

struct {
    int quota;
} opt;

long total_downloaded_bytes;

void DEBUGP(const char *fmt, ...);
void logprintf(int level, const char *fmt, ...);
char *quote(const char *str);
int accdir(const char *dir);
void url_set_dir(struct url *u, const char *dir);
char *xstrdup(const char *str);
void xfree(void *ptr);
const char *_(const char *str);

uerr_t ftp_retrieve_glob_full(struct url *u, struct url *original_url, ccon *con, int flags);
uerr_t ftp_retrieve_glob_simple(struct url *u, ccon *con, int flags);