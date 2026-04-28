#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>
#include <limits.h>
#include <stddef.h>

#define TDB_INTERNAL 1
#define TDB_NOLOCK 2
#define XENSTORE_REL_PATH_MAX PATH_MAX

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(*pos)*)((char*)((head)->next) - offsetof(typeof(*pos), member)), \
        n = (typeof(*pos)*)((char*)(pos->member.next) - offsetof(typeof(*pos), member)); \
        &pos->member != (head); \
        pos = n, n = (typeof(*pos)*)((char*)(n->member.next) - offsetof(typeof(*pos), member)))

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(*pos)*)((char*)((head)->next) - offsetof(typeof(*pos), member)); \
        &pos->member != (head); \
        pos = (typeof(*pos)*)((char*)(pos->member.next) - offsetof(typeof(*pos), member)))

extern int orig_argc;
extern char **orig_argv;
extern struct option options[];
extern int quota_nb_entry_per_domain;
extern int quota_max_entry_size;
extern int quota_max_transaction;
extern char *tracefile;
extern int tdb_flags;
extern bool keep_orphans;
extern bool verbose;
extern int quota_nb_watch_per_domain;
extern int quota_nb_perms_per_node;
extern int quota_max_path_len;
extern int dom0_event;
extern int dom0_domid;
extern int priv_domid;
extern bool recovery;
extern struct pollfd *fds;
extern int nr_fds;
extern int reopen_log_pipe[2];
extern int reopen_log_pipe0_pollfd_idx;
extern int xce_pollfd_idx;
extern int sock;
extern struct list_head connections;
extern bool delayed_requests;
extern void (*xprintf)(const char *fmt, ...);

static inline int min(int a, int b) { return a < b ? a : b; }

struct connection {
    struct list_head list;
    struct list_head delayed;
    int pollfd_idx;
};

struct delayed_request {
    struct list_head list;
    void (*func)(struct delayed_request *);
};

void usage(void);
void barf(const char *fmt, ...);
void barf_perror(const char *msg);
void set_quota(const char *optarg, bool b);
void set_timeout(const char *optarg);
void reopen_log(void);
char *xs_daemon_rundir(void);
char *xs_daemon_rootdir(void);
void daemonize(void);
void write_pidfile(const char *pidfile);
void init_sockets(void);
void init_pipe(int pipefd[2]);
void domain_init(int fd);
void dom0_init(void);
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
void finish_daemonize(void);
void trace(const char *fmt, ...);
void talloc_enable_leak_report_full(void);
void talloc_enable_null_tracking(void);
void *talloc_strdup(void *ctx, const char *str);
void talloc_increase_ref_count(void *ptr);
int talloc_free(void *ptr);