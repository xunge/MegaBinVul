#include <sys/types.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>

#define DEFAULT_ALLOWED_PROVIDERS ""
#define SSH_AGENTPID_ENV_NAME "SSH_AGENT_PID"
#define SSH_AUTHSOCKET_ENV_NAME "SSH_AUTH_SOCK"
#define SSH_LISTEN_BACKLOG 128
#define AUTH_SOCKET 0
#define SYSLOG_LEVEL_DEBUG3 7
#define SYSLOG_LEVEL_INFO 6
#define SYSLOG_FACILITY_AUTH (4<<3)

extern char *__progname;
extern int optind;
extern char *optarg;

int fingerprint_hash;
int restrict_websafe = 1;
int remote_add_provider = 0;
char *allowed_providers;
pid_t parent_pid;
pid_t cleanup_pid;
int parent_alive_interval = 0;
long lifetime = 0;
char socket_dir[PATH_MAX];
char socket_name[PATH_MAX];

struct pollfd;
void prepare_poll(struct pollfd **, size_t *, int *, u_int);
void after_poll(struct pollfd *, size_t, u_int);
void cleanup_handler(int);
void cleanup_exit(int);
void fatal(const char *, ...);
void error(const char *, ...);
void error_f(const char *, ...);
void usage(void);
void sanitise_stdfd(void);
int stdfd_devnull(int, int, int);
int unix_listener(const char *, int, int);
void new_socket(int, int);
void idtab_init(void);
int reaper(void);
void check_parent_exists(void);
void log_init(const char *, int, int, int);
void ssh_signal(int, void (*)(int));
long convtime(const char *);
char *xstrdup(const char *);
int strtonum(const char *, long, long, const char **);
void mktemp_proto(char *, size_t);
int ssh_digest_alg_by_name(const char *);
size_t strlcpy(char *, const char *, size_t);
int pledge(const char *, const char *);