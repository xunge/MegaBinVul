#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <sys/mount.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/eventfd.h>
#include <sys/wait.h>
#include <linux/sched.h>
#include <linux/filter.h>
#include <linux/seccomp.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define UNUSED __attribute__((unused))
#define cleanup_free __attribute__((cleanup(free_cleanup)))
#define cleanup_fd __attribute__((cleanup(close_cleanup)))
#define TRUE 1
#define FALSE 0
#define PRIV_SEP_OP_DONE 0
#define O_PATH 010000000
#define __debug__(x) (void)0

extern uid_t real_uid;
extern gid_t real_gid;
extern char *argv0;
extern char *host_tty_dev;
extern int proc_fd;
extern int opt_info_fd;
extern int opt_block_fd;
extern int opt_seccomp_fd;
extern int opt_sync_fd;
extern bool is_privileged;
extern bool opt_unshare_user;
extern bool opt_unshare_user_try;
extern bool opt_unshare_pid;
extern bool opt_unshare_net;
extern bool opt_unshare_ipc;
extern bool opt_unshare_uts;
extern bool opt_unshare_cgroup;
extern bool opt_unshare_cgroup_try;
extern bool opt_needs_devpts;
extern uid_t opt_sandbox_uid;
extern gid_t opt_sandbox_gid;
extern char *opt_sandbox_hostname;
extern char *opt_chdir_path;
extern char *opt_exec_label;
extern char **lock_files;

static inline void free_cleanup(void *p) { free(*(void**)p); }
static inline void close_cleanup(int *fd) { if (*fd != -1) close(*fd); }

void acquire_privs(void);
void die_with_error(const char *fmt, ...);
void read_overflowids(void);
void usage(int status, FILE *stream);
void parse_args(int *argc, char ***argv);
char *xasprintf(const char *fmt, ...);
void block_sigchild(void);
pid_t raw_clone(unsigned long flags, void *child_stack);
void write_uid_gid_map(uid_t ns_uid, uid_t real_uid, gid_t ns_gid, gid_t real_gid, pid_t pid, bool map_root, bool needs_devpts);
void drop_privs(void);
void monitor_child(int event_fd);
void switch_to_user_with_privs(void);
int loopback_setup(void);
void resolve_symlinks_in_ops(void);
void setup_newroot(bool unshare_pid, int privsep_socket);
uint32_t read_priv_sec_op(int fd, uint32_t *buffer, size_t size, uint32_t *flags, const char **arg1, const char **arg2);
void privileged_op(int fd, uint32_t op, uint32_t flags, const char *arg1, const char *arg2);
void unblock_sigchild(void);
int label_exec(const char *label);
int do_init(int event_fd, pid_t pid);
void fdwalk(int proc_fd, void (*cb)(void *data, int fd), void *data);
void close_extra_fds(void *data, int fd);
void die(const char *fmt, ...);
void xsetenv(const char *name, const char *value, int overwrite);
char *get_current_dir_name(void);
char *load_file_at(int dirfd, const char *path);
char *load_file_data(int fd, size_t *len);
int pivot_root(const char *new_root, const char *put_old);
int unshare(int flags);