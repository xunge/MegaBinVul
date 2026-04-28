#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define INFINITE_RECURSION (-1)
#define LOG_VERBOSE 1
#define LOG_NOTQUIET 2

typedef long long wgint;
typedef enum uerr_t uerr_t;
typedef struct ccon ccon;
typedef struct stat struct_stat;

enum uerr_t {
    RETROK,
    QUOTEXC,
    HOSTERR,
    FWRITEERR,
    WARC_ERR,
    WARC_TMP_FOPENERR,
    WARC_TMP_FWRITEERR,
    RECLEVELEXC
};

enum filetype {
    FT_PLAINFILE,
    FT_DIRECTORY,
    FT_SYMLINK,
    FT_UNKNOWN
};

enum server_type {
    ST_UNIX,
    ST_WINNT
};

enum con_state {
    ON_YOUR_OWN,
    DONE_CWD
};

enum con_cmd {
    DO_CWD,
    DO_RETR,
    LEAVE_PENDING,
    DO_LOGIN
};

struct fileinfo {
    char *name;
    char *linkto;
    time_t tstamp;
    wgint size;
    mode_t perms;
    enum filetype type;
    struct fileinfo *next;
};

struct url {
    char *file;
};

struct ccon {
    char *target;
    int csock;
    enum server_type rs;
    enum con_state st;
    enum con_cmd cmd;
};

struct options {
    int reclevel;
    bool recursive;
    bool timestamping;
    bool retr_symlinks;
    bool preserve_perm;
    bool useservertimestamps;
    wgint quota;
};

extern struct options opt;
extern wgint total_downloaded_bytes;

char *xstrdup(const char *s);
void url_set_file(struct url *u, const char *file);
char *url_file_name(struct url *u, const char *default_name);
void DEBUGP(const char *fmt, ...);
void logprintf(int level, const char *fmt, ...);
const char *quote(const char *str);
const char *number_to_static_string(wgint num);
void set_local_file(const char **actual_target, const char *target);
bool file_exists_p(const char *file);
void touch(const char *file, time_t tstamp);
void xfree(void *ptr);