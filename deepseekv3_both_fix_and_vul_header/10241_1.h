#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

typedef struct pool pool;
typedef struct config_rec config_rec;
typedef struct server_rec server_rec;

struct server_rec {
    void *conf;
};

extern server_rec *main_server;

#define PR_TUNABLE_PATH_MAX 4096
#define PR_LOG_WARNING 0
#define PR_LOG_NOTICE 0
#define FALSE 0
#define CONF_PARAM 0

struct config_rec {
    int argc;
    char **argv;
    struct config_rec *next;
};

int pr_expr_eval_group_and(char **);
config_rec *find_config(server_rec *, int, const char *, int);
config_rec *find_config_next(config_rec *, config_rec *, int, const char *, int);
void pr_signals_handle(void);
char *path_subst_uservar(pool *, char **);
char *dir_realpath(pool *, const char *);
int pr_fs_interpolate(const char *, char *, size_t);
void pr_fs_clear_cache(void);
int pr_fsio_lstat(const char *, struct stat *);
void pr_log_pri(int, const char *, ...);

#define PRIVS_USER
#define PRIVS_RELINQUISH