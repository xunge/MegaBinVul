#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#endif

struct fpm_worker_pool_s {
    int listening_socket;
};

struct fpm_globals_s {
    int error_log_fd;
};

extern struct fpm_globals_s fpm_globals;

#define ZLOG_SYSLOG 1
#define ZLOG_SYSERROR 2

void zlog_set_fd(int fd);
void zlog(int level, const char *message);