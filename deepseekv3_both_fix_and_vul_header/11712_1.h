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
extern int optopt;

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
extern bool create_core_dump;
extern bool set_core_dump_pattern;
extern int snmp;
extern int perf_run;
extern mode_t umask_val;
extern bool umask_cmdline;
extern int log_facility;

#define LOG_CONSOLE_BIT 0
#define DONT_FORK_BIT 1
#define DUMP_CONF_BIT 2
#define DONT_RELEASE_VRRP_BIT 3
#define DONT_RELEASE_IPVS_BIT 4
#define LOG_DETAIL_BIT 5
#define LOG_EXTRA_DETAIL_BIT 6
#define DONT_RESPAWN_BIT 7
#define RELEASE_VIPS_BIT 8
#define NO_SYSLOG_BIT 9
#define CONFIG_TEST_BIT 10
#define MEM_CHECK_LOG_BIT 11
#define LOG_ADDRESS_CHANGES 12
#define RUN_ALL_CHILDREN 13
#define DAEMON_VRRP 14
#define DAEMON_CHECKERS 15
#define DAEMON_BFD 16

#define LOG_FACILITY_MAX 23

struct {
    int facility;
} LOG_FACILITY[LOG_FACILITY_MAX + 1];

#define LINUX_VERSION_CODE 0
#define GIT_COMMIT ""

#define _WITH_VRRP_
#define _WITH_LVS_
#define _WITH_BFD_
#define _WITH_SNMP_
#define _MEM_CHECK_LOG_
#define _WITH_PERF_
#define WITH_DEBUG_OPTIONS
#define HAVE_DECL_CLONE_NEWNET 1

#define PERF_RUN 0
#define PERF_ALL 1
#define PERF_END 2

#define MALLOC malloc
#define FREE_PTR free
#define __set_bit(bit, var) (*(var) |= (1UL << (bit)))
#define __clear_bit(bit, var) (*(var) &= ~(1UL << (bit)))
#define __test_bit(bit, var) (*(var) & (1UL << (bit)))

void usage(const char *progname);
mode_t set_umask(const char *optarg);
void set_flush_log_file();
void open_log_file(const char *filename, const char *header, const char *detail_header, const char *extra_detail_header);
bool read_unsigned(const char *optarg, unsigned *value, unsigned min, unsigned max, bool hex);
int get_signum(const char *optarg);
void log_message(int priority, const char *format, ...);
void set_debug_options(const char *options);