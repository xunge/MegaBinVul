#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>

#define DROPBEAR_CLI_PUBKEY_AUTH 1
#define DROPBEAR_CLI_LOCALTCPFWD 1
#define DROPBEAR_CLI_REMOTETCPFWD 1
#define DROPBEAR_CLI_NETCAT 1
#define DROPBEAR_CLI_ANYTCPFWD 1
#define DROPBEAR_CLI_AGENTFWD 1
#define DROPBEAR_CLI_PROXYCMD 1
#define DROPBEAR_USER_ALGO_LIST 1
#define DROPBEAR_CLI_MULTIHOP 1
#define DEBUG_TRACE 1
#define DISABLE_ZLIB 1
#define DISABLE_SYSLOG 1

#define DEFAULT_RECV_WINDOW 0
#define DEFAULT_KEEPALIVE 0
#define DEFAULT_IDLE_TIMEOUT 0
#define MAX_RECV_WINDOW 0
#define DROPBEAR_COMPRESS_ON 0
#define DROPBEAR_DEFAULT_CLI_AUTHKEY ""

#define LOG_INFO 6

struct cli_opts {
    char *progname;
    char *remotehost;
    char *remoteport;
    char *username;
    char *cmd;
    int no_cmd;
    int backgrounded;
    int wantpty;
    int always_accept_key;
    int no_hostkey_check;
    int is_subsystem;
#if DROPBEAR_CLI_PUBKEY_AUTH
    void *privkeys;
#endif
#if DROPBEAR_CLI_ANYTCPFWD
    int exit_on_fwd_failure;
#endif
    int exit_on_trivial_auth;
#if DROPBEAR_CLI_LOCALTCPFWD
    void *localfwds;
#endif
#if DROPBEAR_CLI_REMOTETCPFWD
    void *remotefwds;
#endif
#if DROPBEAR_CLI_AGENTFWD
    int agent_fwd;
    int agent_fd;
    int agent_keys_loaded;
#endif
#if DROPBEAR_CLI_PROXYCMD
    char *proxycmd;
#endif
    char *bind_address;
    char *bind_port;
#if DROPBEAR_CLI_NETCAT
    char *netcat_host;
#endif
};

struct options {
    int compress_mode;
#if DROPBEAR_USER_ALGO_LIST
    char *cipher_list;
    char *mac_list;
#endif
#ifndef DISABLE_SYSLOG
    int usingsyslog;
#endif
    unsigned int recv_window;
    unsigned int keepalive_secs;
    unsigned int idle_timeout_secs;
#if DROPBEAR_CLI_LOCALTCPFWD
    int listen_fwd_all;
#endif
};

extern struct cli_opts cli_opts;
extern struct options opts;
extern int debug_trace;

void dropbear_exit(const char* format, ...);
void printhelp(void);
void print_version(void);
void fill_own_user(void);
void add_extendedopt(char* opt);
#if DROPBEAR_CLI_PUBKEY_AUTH
void loadidentityfile(char* filename, int warnfail);
#endif
#if DROPBEAR_CLI_REMOTETCPFWD || DROPBEAR_CLI_LOCALTCPFWD
void addforward(char* str, void* list);
#endif
#if DROPBEAR_CLI_NETCAT
void add_netcat(char* str);
#endif
void parse_ciphers_macs(void);
void parse_hostname(char* hostname);
#if DROPBEAR_CLI_MULTIHOP
void parse_multihop_hostname(char* hostname, char* progname);
#endif
char* expand_homedir_path(const char* path);
void* list_new(void);
void* m_malloc(size_t size);
char* m_strdup(const char* str);
void m_free(void* ptr);
size_t strlcat(char* dst, const char* src, size_t size);
int m_str_to_uint(const char* str, unsigned int* val);
void dropbear_log(int priority, const char* format, ...);
#define TRACE(x)
#define DROPBEAR_FAILURE 0