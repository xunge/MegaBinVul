#include <unistd.h>
#include <stdlib.h>

struct fpm_worker_pool_s;
struct fpm_worker_pool_config_s {
    char *name;
    int pm_max_requests;
};

struct fpm_worker_pool_s {
    int listening_socket;
    struct fpm_worker_pool_config_s *config;
};

struct fpm_globals_s {
    int max_requests;
    int listening_socket;
} fpm_globals;

enum {
    ZLOG_ERROR,
    FPM_EXIT_SOFTWARE
};

int fpm_stdio_init_child(struct fpm_worker_pool_s *wp);
int fpm_log_init_child(struct fpm_worker_pool_s *wp);
int fpm_status_init_child(struct fpm_worker_pool_s *wp);
int fpm_unix_init_child(struct fpm_worker_pool_s *wp);
int fpm_signals_init_child(void);
int fpm_env_init_child(struct fpm_worker_pool_s *wp);
int fpm_php_init_child(struct fpm_worker_pool_s *wp);
void zlog(int level, const char *format, ...);