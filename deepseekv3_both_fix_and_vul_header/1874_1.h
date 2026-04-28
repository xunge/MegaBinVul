#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <syslog.h>
#include <errno.h>

struct list_head {
    struct list_head *next, *prev;
};

struct delayed_request {
    struct list_head list;
};

struct connection {
    struct list_head list;
    struct list_head delayed;
    int pollfd_idx;
};

extern int orig_argc;
extern char **orig_argv;
extern struct option options[];
extern int quota_nb_entry_per_domain;
extern int quota_max_entry_size;
extern int quota_max_transaction;
extern int quota_nb_watch_per_domain;
extern int quota_nb_perms_per_node;
extern int quota_max_path_len;
extern bool recovery;
extern char *tracefile;
extern int tdb_flags;
extern bool keep_orphans;
extern bool verbose;
extern int dom0_event;
extern int dom0_domid;
extern int priv_domid;
extern struct pollfd *fds;
extern int nr_fds;
extern int reopen_log_pipe0_pollfd_idx;
extern int xce_pollfd_idx;
extern int sock;
extern struct list_head connections;
extern bool delayed_requests;
extern int reopen_log_pipe[2];

#define XENSTORE_REL_PATH_MAX 1024
#define NO_LIVE_UPDATE
#define __MINIOS__
#define XEN_SYSTEMD_ENABLED
#define NO_SOCKETS
#define TDB_INTERNAL 0
#define TDB_NOLOCK 0

void usage(void);
void barf(const char *fmt, ...);
void barf_perror(const char *msg);
void set_quota(const char *optarg, bool b);
void set_timeout(const char *optarg);
void reopen_log(void);
const char *xs_daemon_rundir(void);
const char *xs_daemon_rootdir(void);
void daemonize(void);
void write_pidfile(const char *pidfile);
void init_sockets(void);
void init_pipe(int pipefd[2]);
void domain_init(int i);
void dom0_init(void);
void finish_daemonize(void);
void trace(const char *fmt, ...);
void trigger_reopen_log(int sig);
void lu_read_state(void);
void initialize_fds(int *sock_pollfd_idx, int *timeout);
void accept_connection(int sock);
void handle_event(void);
bool conn_can_read(struct connection *conn);
void handle_input(struct connection *conn);
bool conn_can_write(struct connection *conn);
void handle_output(struct connection *conn);
void call_delayed(struct delayed_request *req);

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define offsetof(type, member) ((size_t)&((type *)0)->member)

static inline int min(int a, int b) { return a < b ? a : b; }

void *talloc_enable_leak_report_full(void);
void talloc_enable_null_tracking(void);
void *talloc_strdup(void *ctx, const char *str);
int talloc_free(void *ptr);
void talloc_increase_ref_count(void *ptr);

int sd_notify(int unset_environment, const char *state);
#define SD_NOTICE "<5>"