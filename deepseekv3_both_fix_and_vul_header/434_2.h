#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

typedef struct modret {
    int dummy;
} MODRET;

typedef struct cmd_rec {
    int argc;
    char **argv;
    char *arg;
    void *tmp_pool;
    struct server_rec *server;
} cmd_rec;

typedef struct server_rec {
    void *conf;
} server_rec;

typedef struct session_rec {
    void *notes;
} session_rec;

typedef struct pool pool;

#define FALSE 0
#define TRUE 1
#define PR_DECLINED(cmd) ((MODRET) {0})
#define PR_ERROR(cmd) ((MODRET) {0})
#define PR_HANDLED(cmd) ((MODRET) {0})
#define R_530 "530"
#define R_503 "503"
#define R_550 "550"
#define R_552 "552"
#define R_250 "250"
#define DEBUG7 7
#define DEBUG8 8
#define MOD_COPY_VERSION "1.0"
#define G_WRITE 0
#define FSIO_DECODE_FL_TELL_ERRORS 0
#define CHECK_CMD_MIN_ARGS(cmd, n) do {} while(0)

extern int copy_engine;
extern session_rec session;

unsigned char *get_param_ptr(void *conf, const char *name, int b);
void pr_response_add_err(const char *code, const char *fmt, ...);
void pr_response_add(const char *code, const char *fmt, ...);
void pr_cmd_set_errno(cmd_rec *cmd, int err);
void pr_log_debug(int level, const char *fmt, ...);
void pr_cmd_set_name(cmd_rec *cmd, const char *name);
char *pr_fs_decode_path2(pool *p, const char *path, int flags);
char *pstrcat(pool *p, ...);
char *dir_canonical_vpath(pool *p, const char *path);
int dir_check(pool *p, cmd_rec *cmd, int mode, const char *path, void *arg);
int copy_paths(pool *p, const char *from, const char *to);
const char *pr_table_get(void *notes, const char *key, const char *def);