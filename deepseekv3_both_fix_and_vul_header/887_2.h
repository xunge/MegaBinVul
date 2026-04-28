#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <errno.h>
#include <limits.h>
#include <syslog.h>
#include <grp.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define SAFE_PATH "/bin:/usr/bin:/usr/local/bin"
#define _PW_NAME_LEN 31
#define LINE_MAX 2048
#define PATH_MAX 4096
#define DOAS_CONF "/etc/doas.conf"
#define ROOT_UID 0
#define USE_PAM 1

#define NOPASS 0x01
#define PERSIST 0x02
#define PAM_SUCCESS 0
#define PAM_SILENT 1
#define PAM_AUTH_ERR 2
#define PAM_USER_UNKNOWN 3
#define PAM_MAXTRIES 4
#define PAM_NEW_AUTHTOK_REQD 5
#define PAM_CHANGE_EXPIRED_AUTHTOK 6

struct rule {
    int options;
    const char *cmd;
};

struct pam_handle;
typedef struct pam_handle pam_handle_t;

struct pam_conv {
    int (*conv)(int, const void **, void **, void *);
    void *appdata_ptr;
};

extern struct pam_conv pamc;

extern char *optarg;
extern int optind;

void usage(void);
int parseuid(const char *, uid_t *);
void checkconfig(const char *, int, char **, uid_t, gid_t *, int, uid_t);
void parseconfig(const char *, int);
int permit(uid_t, gid_t *, int, struct rule **, uid_t, const char *, const char **);
char **prepenv(struct rule *, struct passwd *, struct passwd *);
size_t strlcpy(char *, const char *, size_t);
size_t strlcat(char *, const char *, size_t);
void errc(int, int, const char *);
const char *pam_strerror(pam_handle_t *, int);
int pam_start(const char *, const char *, const struct pam_conv *, pam_handle_t **);
int pam_authenticate(pam_handle_t *, int);
int pam_acct_mgmt(pam_handle_t *, int);
int pam_chauthtok(pam_handle_t *, int);
int pam_end(pam_handle_t *, int);