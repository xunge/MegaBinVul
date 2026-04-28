#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <time.h>

#define DEFAULT_PKCS11_WHITELIST "/usr/lib*/*,/usr/local/lib*/*"
#define SSH_AGENTPID_ENV_NAME "SSH_AGENT_PID"
#define SSH_AUTHSOCKET_ENV_NAME "SSH_AUTH_SOCK"
#define SSH_LISTEN_BACKLOG 128
#define _PATH_DEVNULL "/dev/null"
#define AUTH_SOCKET 0
#define SYSLOG_LEVEL_DEBUG3 7
#define SYSLOG_LEVEL_INFO 6
#define SYSLOG_FACILITY_AUTH (4<<3)

extern char *__progname;
extern int fingerprint_hash;
extern int max_fd;
extern int parent_alive_interval;
extern int lifetime;
extern pid_t cleanup_pid;
extern pid_t parent_pid;
extern char *pkcs11_whitelist;
extern char socket_dir[1024];
extern char socket_name[1024];

void cleanup_exit(int);
void cleanup_handler(int);
void error(const char *, ...);
void fatal(const char *, ...);
void log_init(const char *, int, int, int);
void new_socket(int, int);
void prepare_select(fd_set **, fd_set **, int *, u_int *, struct timeval **);
void after_select(fd_set *, fd_set *);
void ssh_malloc_init(void);
void sanitise_stdfd(void);
void usage(void);
void idtab_init(void);
int check_parent_exists(void);
int convtime(const char *);
int reaper(void);
int unix_listener(const char *, int, int);
int mktemp_proto(char *, size_t);
char *xstrdup(const char *);
int ssh_digest_alg_by_name(const char *);
long strtonum(const char *, long, long, const char **);
size_t strlcpy(char *, const char *, size_t);
int pledge(const char *, const char *);
#ifdef ENABLE_PKCS11
void pkcs11_init(int);
#endif