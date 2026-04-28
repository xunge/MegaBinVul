#include <stdbool.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <syslog.h>
#include <fcntl.h>
#include <strings.h>

#define PROG_TYPE_PARENT 0
#define DAEMON_VRRP 0
#define DAEMON_CHECKERS 0
#define DAEMON_BFD 0
#define NO_SYSLOG_BIT 0
#define LOG_CONSOLE_BIT 0
#define CONFIG_TEST_BIT 0
#define DONT_FORK_BIT 0
#define PACKAGE_NAME ""
#define KEEPALIVED_PID_DIR ""
#define KEEPALIVED_PID_FILE ""
#define CHECKERS_PID_FILE ""
#define VRRP_PID_FILE ""
#define BFD_PID_FILE ""
#define PID_EXTENSION ""
#define PID_DIR ""
#define GIT_COMMIT ""
#define LINUX_VERSION_CODE 0
#define KERNEL_VERSION(a,b,c) 0
#define HAVE_DECL_CLONE_NEWNET 0
#define THREAD_DUMP 0
#define _MEM_CHECK_ 0
#define _MEM_CHECK_LOG_ 0
#define _DEBUG_ 0
#define _WITH_VRRP_ 0
#define _WITH_LVS_ 0
#define _WITH_BFD_ 0

extern int debug;
extern unsigned os_major;
extern unsigned os_minor;
extern unsigned os_release;
extern char *config_id;
extern char *version_string;
extern char *conf_file;
extern char *log_file_name;
extern char *syslog_ident;
extern char *main_pidfile;
extern char *checkers_pidfile;
extern char *vrrp_pidfile;
extern char *bfd_pidfile;
extern char *override_namespace;
extern char *orig_core_dump_pattern;
extern bool free_main_pidfile;
extern bool free_checkers_pidfile;
extern bool free_vrrp_pidfile;
extern bool free_bfd_pidfile;
extern bool use_pid_dir;
extern int log_facility;
extern int umask_val;
extern unsigned long daemon_mode;
extern void *master;

struct global_data {
    char *network_namespace;
    char *instance_name;
    int umask;
};

extern struct global_data *global_data;

void set_time_now(void);
void save_cmd_line_options(int argc, char **argv);
void __set_bit(int nr, volatile unsigned long *addr);
bool __test_bit(int nr, volatile unsigned long *addr);
void log_message(int priority, const char *format, ...);
void openlog(const char *ident, int option, int facility);
void closelog(void);
void enable_console_log(void);
void core_dump_init(void);
void log_command_line(int priority);
bool check_conf_file(const char *file);
void config_test_exit(void);
struct global_data *alloc_global_data(void);
void read_config_file(void);
void init_global_data(struct global_data *data, void *arg);
char *make_syslog_ident(const char *name);
void open_log_file(const char *name, const char *dir, const char *ns, const char *instance);
void set_child_finder_name(void (*func)(void));
void create_pid_dir(void);
bool set_namespaces(const char *ns);
char *make_pidfile_name(const char *dir, const char *file, const char *ext);
bool keepalived_running(unsigned long mode);
int xdaemon(bool nochdir, bool noclose, bool exit_parent);
void close_std_fd(void);
void enable_mem_log_termination(void);
void validate_config(void);
bool pidfile_write(const char *file, pid_t pid);
void *thread_make_master(void);
void signal_init(void);
bool start_keepalived(void);
void initialise_debug_options(void);
void register_parent_thread_addresses(void);
void launch_thread_scheduler(void *master);
void stop_keepalived(void);
void deregister_thread_addresses(void);
void clear_namespaces(void);
void remove_pid_dir(void);
void update_core_dump_pattern(const char *pattern);
void free_parent_mallocs_startup(bool partial);
void free_parent_mallocs_exit(void);
void free_global_data(struct global_data *data);
void mem_log_init(const char *name, const char *desc);
void *find_keepalived_child_name(void);
int parse_cmdline(int argc, char **argv);
#define MALLOC malloc
#define FREE free
#define FREE_PTR(ptr) free(ptr)
#define KEEPALIVED_EXIT_OK 0