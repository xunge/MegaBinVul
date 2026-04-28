#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct cmd_rec cmd_rec;
typedef struct server_rec server_rec;
typedef struct pool pool;
typedef struct session_rec session_rec;
typedef struct table table;

struct cmd_rec {
    int argc;
    char **argv;
    char *arg;
    pool *tmp_pool;
    server_rec *server;
    int group;
};

struct server_rec {
    void *conf;
};

struct pool {};

struct session_rec {
    pool *pool;
    table *notes;
};

struct table {};

#define MODRET int
#define PR_DECLINED(cmd) 0
#define PR_ERROR(cmd) -1
#define PR_HANDLED(cmd) 1
#define FALSE 0
#define TRUE 1
#define R_530 530
#define R_550 550
#define R_350 350
#define EPERM 1
#define CURRENT_CONF NULL
#define MOD_COPY_VERSION ""
#define DEBUG2 2
#define DEBUG8 8
#define G_READ 0
#define FSIO_DECODE_FL_TELL_ERRORS 0
#define PR_FILTER_ERR_FAILS_ALLOW_FILTER 1
#define PR_FILTER_ERR_FAILS_DENY_FILTER 2

extern int copy_engine;
extern session_rec session;
extern int trace_channel;

unsigned char *get_param_ptr(void *conf, const char *name, int bool);
void pr_response_add_err(int code, const char *fmt, ...);
void pr_response_add(int code, const char *fmt, ...);
void pr_cmd_set_errno(cmd_rec *cmd, int err);
void pr_cmd_set_name(cmd_rec *cmd, const char *name);
char *pr_fs_decode_path2(pool *p, char *path, int flags);
char *pstrcat(pool *p, const char *str, ...);
char *pstrdup(pool *p, const char *str);
int dir_check(pool *p, cmd_rec *cmd, int mode, const char *path, void *arg);
int dir_check_canon(pool *p, cmd_rec *cmd, int group, const char *path, void *arg);
int exists2(pool *p, const char *path);
int pr_filter_allow_path(void *conf, const char *path);
char *dir_canonical_vpath(pool *p, const char *path);
int pr_table_add(table *tab, const char *key, void *val, int flags);
void pr_log_debug(int level, const char *fmt, ...);
void pr_trace_msg(int channel, int level, const char *fmt, ...);

#define CHECK_CMD_MIN_ARGS(cmd, n) do { } while(0)