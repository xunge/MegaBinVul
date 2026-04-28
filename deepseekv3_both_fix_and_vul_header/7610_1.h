#include <syslog.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PAM_EXTERN extern
#define PAM_TAC_DEBUG 1
#define PAM_TAC_VMAJ 0
#define PAM_TAC_VMIN 0
#define PAM_TAC_VPAT 0
#define PAM_USER_UNKNOWN 0
#define PAM_AUTH_ERR 0
#define PAM_SUCCESS 0
#define PAM_PERM_DENIED 0

#define AUTHOR_STATUS_PASS_ADD 0
#define AUTHOR_STATUS_PASS_REPL 0

typedef void pam_handle_t;

struct areply {
    int status;
    char *msg;
    struct tac_attrib *attr;
};

struct tac_attrib {
    char *attr;
    size_t attr_len;
    struct tac_attrib *next;
};

extern int _pam_parse(int argc, const char **argv);
extern char *_pam_get_user(pam_handle_t *pamh);
extern char *_pam_get_terminal(pam_handle_t *pamh);
extern char *_pam_get_rhost(pam_handle_t *pamh);
extern void _pam_log(int priority, const char *format, ...);
extern char *tac_ntop(void *addr);
extern void tac_add_attrib(struct tac_attrib **attr, const char *name, const char *value);
extern int tac_connect_single(void *addr, const char *key, void *unused, int timeout);
extern int tac_author_send(int fd, const char *user, const char *tty, const char *rhost, struct tac_attrib *attr);
extern void tac_free_attrib(struct tac_attrib **attr);
extern void tac_author_read(int fd, struct areply *arep);
extern int pam_putenv(pam_handle_t *pamh, const char *name_value);

extern struct {
    struct addrinfo *addr;
    const char *key;
} active_server;

extern char tac_service[];
extern char tac_protocol[];
extern int tac_timeout;