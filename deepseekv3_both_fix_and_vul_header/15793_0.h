#include <locale.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define ENABLE_NLS 1
#define PACKAGE ""
#define LOCALEDIR ""
#define BIN_DIR ""
#define SBIN_DIR ""
#define EXECUTABLE ""

extern void abrt_init(char **argv);
extern const char *_(const char *str);
extern void perror_msg_and_die(const char *fmt, ...);
extern void error_msg_and_die(const char *fmt, ...);
extern char *xasprintf(const char *fmt, ...);
extern char *xstrdup(const char *str);
extern void xsetenv(const char *name, const char *value);
extern unsigned parse_opts(int argc, char **argv, struct options *opts, const char *usage);
extern int g_verbose;

#define IGNORE_RESULT(x) (void)(x)

struct options {
    const char *short_name;
    const char *long_name;
    void *value;
    const char *arg_name;
    const char *desc;
};

#define OPT__VERBOSE(x) { NULL, NULL, x, NULL, NULL }
#define OPT_BOOL(s, l, v, d) { #s, l, v, NULL, d }
#define OPT_STRING(s, l, v, a, d) { #s, l, v, a, d }
#define OPT_END() { NULL, NULL, NULL, NULL, NULL }