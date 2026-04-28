#include <locale.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <libintl.h>

#define ENABLE_NLS 1
#define PACKAGE ""
#define LOCALEDIR ""
#define _(x) x
#define EXECUTABLE ""
#define BIN_DIR ""
#define SBIN_DIR ""
#define LARGE_DATA_TMP_DIR "/tmp"
#define IGNORE_RESULT(x) (void)(x)

int g_verbose;

struct options {
    int dummy;
};

#define OPT__VERBOSE(x) {0}
#define OPT_BOOL(a,b,c,d) {0}
#define OPT_STRING(a,b,c,d,e) {0}
#define OPT_END() {0}

unsigned parse_opts(int argc, char **argv, struct options *program_options, const char *program_usage_string);
void abrt_init(char **argv);
void perror_msg_and_die(const char *fmt, ...);
void error_msg_and_die(const char *fmt, ...);
char *xasprintf(const char *fmt, ...);
void xsetenv(const char *name, const char *value);
int clearenv(void);
char *xstrdup(const char *s);
void log_info(const char *fmt, ...);
pid_t safe_waitpid(pid_t pid, int *status, int options);