#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

typedef struct Authctxt Authctxt;
struct ssh_sandbox;

struct monitor {
    struct kex **m_pkex;
    pid_t m_pid;
    int m_sendfd;
    int m_log_recvfd;
};

struct kex {
    int kex;
};

enum { PRIVSEP_ON = 1 };

extern struct monitor *pmonitor;
extern int use_privsep;
extern int have_agent;
extern int auth_sock;
extern int privsep_is_preauth;
extern struct kex *active_state;

int ssh_get_authentication_socket(int *);
void fatal(const char *, ...);
void error(const char *, ...);
void debug2(const char *, ...);
const char *ssh_err(int);
void monitor_child_preauth(Authctxt *, struct monitor *);
void monitor_sync(struct monitor *);
void set_log_handler(void (*)(void), struct monitor *);
void mm_log_handler(void);
void privsep_preauth_child(void);
void setproctitle(const char *, ...);
struct monitor *monitor_init(void);
struct ssh_sandbox *ssh_sandbox_init(void);
void ssh_sandbox_parent_preauth(struct ssh_sandbox *, pid_t);
void ssh_sandbox_parent_finish(struct ssh_sandbox *);
void ssh_sandbox_child(struct ssh_sandbox *);