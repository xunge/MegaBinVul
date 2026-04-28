#include <sys/types.h>
#include <sys/param.h>
#include <sys/resource.h>
#include <sys/syslog.h>
#include <sys/wait.h>

#include <err.h>
#include <errno.h>
#include <grp.h>
#include <limits.h>
#include <pwd.h>
#include <paths.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DOAS_CONF "/etc/doas.conf"

enum {
    NOPASS = 0x01,
    PERSIST = 0x02,
    NOLOG = 0x04
};

struct rule {
    int options;
    const char *cmd;
};

extern char *__progname;
#define setprogname(x) (__progname = (x))

extern char *formerpath;
extern char *optarg;
extern int optind;

int parseuid(const char *, uid_t *);
void usage(void);
int mygetpwuid_r(uid_t, struct passwd *, struct passwd **);
void checkconfig(const char *, int, char **, uid_t, gid_t *, int, uid_t);
void parseconfig(const char *, int);
int permit(uid_t, gid_t *, int, const struct rule **, uid_t, const char *, const char **);
char **prepenv(const struct rule *, struct passwd *, struct passwd *);
void shadowauth(const char *, int);
void pamauth(const char *, const char *, int, int, int);