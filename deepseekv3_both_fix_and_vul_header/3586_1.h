#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>

struct fpm_worker_pool_config_s {
    char *name;
    char *listen_owner;
    char *listen_group;
    char *listen_mode;
};

struct fpm_worker_pool_s {
    struct fpm_worker_pool_config_s *config;
    int socket_uid;
    int socket_gid;
    int socket_mode;
};

enum {
    ZLOG_SYSERROR
};

void zlog(int level, const char *format, ...);