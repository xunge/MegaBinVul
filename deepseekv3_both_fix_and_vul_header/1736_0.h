#include <stdlib.h>
#include <string.h>

#define DROPBEAR_SUCCESS 0
#define DROPBEAR_CLI_ANYTCPFWD 1
#define DISABLE_SYSLOG 0

#define LOG_INFO 0
#define LOG_WARNING 0

struct {
    int exit_on_fwd_failure;
    const char* remoteport;
    int exit_on_trivial_auth;
} cli_opts;

struct {
    int usingsyslog;
} opts;

static int match_extendedopt(const char** optstr, const char* option);
static int parse_flag_value(const char* optstr);
static void dropbear_log(int priority, const char* format, ...);