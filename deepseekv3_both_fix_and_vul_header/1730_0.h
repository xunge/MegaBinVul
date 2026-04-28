#include <stdlib.h>
#include <string.h>

#define DROPBEAR_SUCCESS 0
#define DROPBEAR_CLI_ANYTCPFWD 1
#define DISABLE_SYSLOG 0

#define LOG_INFO 0
#define LOG_WARNING 1

struct {
    int usingsyslog;
} opts;

struct {
    int exit_on_fwd_failure;
    int disable_trivial_auth;
    int exit_on_trivial_auth;
    const char* remoteport;
} cli_opts;

void dropbear_log(int level, const char* format, ...);
int match_extendedopt(const char** optstr, const char* option);
int parse_flag_value(const char* optstr);