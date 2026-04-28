#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>

extern char *optarg;
extern int optind;
extern char *version_string;
extern char *COPYRIGHT_STRING;
extern char *KEEPALIVED_CONFIGURE_OPTIONS;
extern char *CONFIGURATION_OPTIONS;
extern char *SYSTEM_OPTIONS;
extern unsigned long debug;
extern unsigned long daemon_mode;
extern char *log_file_name;
extern char *conf_file;
extern char *main_pidfile;
extern char *checkers_pidfile;
extern char *vrrp_pidfile;
extern char *bfd_pidfile;
extern char *snmp_socket;
extern char *override_namespace;
extern char *config_id;
extern char *core_dump_pattern;
extern mode_t umask_val;
extern bool umask_cmdline;
extern bool create_core_dump;
extern bool set_core_dump_pattern;
extern int snmp;
extern int perf_run;
extern int log_facility;

struct facility_t {
    int facility;
};

struct facility_t LOG_FACILITY[24];

#define LOG_FACILITY_MAX (sizeof(LOG_FACILITY)/sizeof(LOG_FACILITY[0]))
#define MALLOC malloc
#define FREE_PTR free
#define __set_bit(n, p) (*(p) |= (1UL << (n)))
#define __clear_bit(n, p) (*(p) &= ~(1UL << (n)))
#define __test_bit(n, p) (*(p) & (1UL << (n)))
#define LINUX_VERSION_CODE 0
#define GIT_COMMIT ""

enum {
    LOG_CONSOLE_BIT,
    DONT_FORK_BIT,
    DUMP_CONF_BIT,
    DONT_RELEASE_VRRP_BIT,
    DONT_RELEASE_IPVS_BIT,
    LOG_DETAIL_BIT,
    LOG_EXTRA_DETAIL_BIT,
    DONT_RESPAWN_BIT,
    RELEASE_VIPS_BIT,
    NO_SYSLOG_BIT,
    CONFIG_TEST_BIT,
    LOG_ADDRESS_CHANGES,
    MEM_CHECK_LOG_BIT,
    RUN_ALL_CHILDREN,
    DAEMON_VRRP,
    DAEMON_CHECKERS,
    DAEMON_BFD
};

enum {
    PERF_RUN,
    PERF_ALL,
    PERF_END
};

void usage(char *prog);
int get_signum(char *optarg);
mode_t set_umask(char *optarg);
void set_flush_log_file();
void open_log_file(char *name, char *format, char *user, char *group);
void log_message(int priority, const char *format, ...);
bool read_unsigned(char *optarg, unsigned *facility, unsigned min, unsigned max, bool hex);
void set_debug_options(char *optarg);