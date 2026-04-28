#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct pool pool;

struct config_rec {
    int argc;
    char **argv;
    struct config_rec *next;
};

typedef struct config_rec config_rec;

struct server_rec {
    void *conf;
};

extern struct server_rec *main_server;

#define FALSE 0
#define PR_LOG_WARNING 0
#define PR_LOG_NOTICE 0
#define PR_TUNABLE_PATH_MAX 4096
#define CONF_PARAM 0

#define PRIVS_USER
#define PRIVS_RELINQUISH

struct config_rec *find_config(void *conf, int type, const char *name, int recurse);
struct config_rec *find_config_next(struct config_rec *prev, struct config_rec *next, int type, const char *name, int recurse);
int pr_expr_eval_group_and(char **args);
const char *path_subst_uservar(pool *p, const char **path);
char *pstrdup(pool *p, const char *str);
int pr_fs_interpolate(const char *src, char *dst, size_t dstsz);
void pr_fs_clear_cache2(const char *path);
int pr_fsio_lstat(const char *path, struct stat *st);
char *dir_realpath(pool *p, const char *path);
void pr_log_pri(int priority, const char *fmt, ...);
void pr_signals_handle(void);