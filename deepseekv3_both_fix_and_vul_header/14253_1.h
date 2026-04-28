#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

struct tmate_settings {
    char *bind_addr;
    char *tmate_host;
    char *keys_dir;
    int ssh_port;
    int ssh_port_advertized;
    char *websocket_hostname;
    int websocket_port;
    bool use_proxy_protocol;
    int log_level;
};

extern struct tmate_settings *tmate_settings;
extern char *cmdline;
extern char *cmdline_end;
extern void *tmate_session;

#define TMATE_WORKDIR "/tmp/tmate"

char *xstrdup(const char *s);
void usage(void);
void init_logging(int level);
void setup_locale(void);
char *get_full_hostname(void);
void tmate_preload_trace_lib(void);
void tmate_catch_sigsegv(void);
void tmate_init_rand(void);
void tmate_fatal(const char *msg);
void tmate_ssh_server_main(void *session, const char *keys_dir, const char *bind_addr, int port);