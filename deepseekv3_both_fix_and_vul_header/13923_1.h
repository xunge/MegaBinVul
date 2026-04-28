#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#define PACKAGE ""
#define EX_SOFTWARE 70
#define EX_OSERR 71
#define TRUE 1
#define FILTER_ENABLE
#define LOG_INFO 0
#define LOG_WARNING 1

struct config {
    int godaemon;
    char *pidpath;
    int filter;
    char *listen_addrs;
    int port;
    char *config_file;
};

struct config_defaults {
    char *config_file;
};

struct config config;
struct config_defaults config_defaults;

typedef void (*sighandler_t)(int);

void log_message(int level, const char *format, ...);
int config_compile_regex(void);
void initialize_config_defaults(struct config_defaults *defaults);
void process_cmdline(int argc, char **argv, struct config_defaults *defaults);
int reload_config_file(char *file, struct config *conf, struct config_defaults *defaults);
void init_stats(void);
int is_anonymous_enabled(void);
void anonymous_insert(const char *header);
void makedaemon(void);
sighandler_t set_signal_handler(int sig, sighandler_t handler);
void takesig(int sig);
void filter_init(void);
void filter_destroy(void);
int child_listening_sockets(char *addrs, int port);
void change_user(char *name);
int setup_logging(void);
int pidfile_create(char *path);
int child_pool_create(void);
void child_main_loop(void);
void child_kill_children(int sig);
void child_close_sock(void);
void shutdown_logging(void);