#include <locale.h>
#include <libintl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>

#define PACKAGE ""
#define LOCALEDIR ""
#define ENABLE_NLS 1
#define EXECUTABLE ""
#define BIN_DIR ""
#define SBIN_DIR ""

extern int g_verbose;

struct options {
    char short_opt;
    const char *long_opt;
    void *value;
    const char *arg_name;
    const char *description;
};

#define OPT__VERBOSE(x) {'\0', NULL, x, NULL, NULL}
#define OPT_BOOL(a,b,c,d) {a, b, c, NULL, d}
#define OPT_STRING(a,b,c,d,e) {a, b, c, d, e}
#define OPT_END() {'\0', NULL, NULL, NULL, NULL}

#define _(x) gettext(x)

extern void abrt_init(char **argv);
extern unsigned parse_opts(int argc, char **argv, struct options *opts, const char *usage);
extern char *xasprintf(const char *format, ...);
extern void perror_msg_and_die(const char *format, ...);
extern void error_msg_and_die(const char *format, ...);
extern void xsetenv(const char *name, const char *value);
extern int clearenv(void);
extern int setregid(gid_t rgid, gid_t egid);
extern int setreuid(uid_t ruid, uid_t euid);
extern int putenv(char *string);

static inline char *xstrdup(const char *s) { return strdup(s); }
#define IGNORE_RESULT(x) (void)(x)