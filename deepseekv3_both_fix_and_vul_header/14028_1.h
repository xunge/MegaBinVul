#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <err.h>
#include <errno.h>
#include <locale.h>
#include <libintl.h>
#include <sys/types.h>

#define PACKAGE ""
#define LOCALEDIR ""
#define _PATH_BSHELL "/bin/sh"
#define _PATH_SHELLS "/etc/shells"
#define _PATH_PASSWD "/etc/passwd"
#define HAVE_LIBUSER 0
#define HAVE_LIBSELINUX 0
#define CHFN_CHSH_PASSWORD 0
#define PASSWD__CHSH 0
#define LU_LOGINSHELL ""

typedef char *security_context_t;

struct sinfo {
    char *username;
    char *shell;
};

extern void sanitize_env(void);
extern void close_stdout(void);
extern void parse_argv(int argc, char **argv, struct sinfo *info);
extern int is_local(const char *username);
extern int get_shell_list(const char *shell);
extern char *ask_new_shell(const char *prompt, const char *oldshell);
extern void check_shell(const char *shell);
extern int setpwnam(struct passwd *pw);
extern int auth_pam(const char *service, uid_t uid, const char *username);
extern int set_value_libuser(const char *action, const char *username, uid_t uid, const char *field, const char *value);
extern int is_selinux_enabled(void);
extern int checkAccess(const char *name, int permission);
extern int getprevcon(security_context_t *context);
extern int setupDefaultContext(const char *path);