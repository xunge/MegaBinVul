#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <syslog.h>

struct iax2_registry {
    char *username;
    int regstate;
    void *dnsmgr;
    struct sockaddr_in addr;
    int callno;
    int refresh;
    void *expire;
};

struct iax_ie_data {
    char buf[256];
    int pos;
};

struct iax_call {
    struct iax2_registry *reg;
};

enum {
    REG_STATE_TIMEOUT,
    REG_STATE_REGSENT
};

enum {
    IAX_IE_USERNAME,
    IAX_IE_REFRESH
};

enum {
    AST_FRAME_IAX,
    IAX_COMMAND_REGREQ
};

#define NEW_FORCE 1

extern int iaxdebug;
extern void *sched;
extern void *iaxsl[];
extern struct iax_call *iaxs[];
extern int defaultsockfd;
extern void iax2_do_register_s(void *arg);

void ast_debug(int level, const char *fmt, ...);
void ast_dnsmgr_refresh(void *dnsmgr);
int ast_dnsmgr_changed(void *dnsmgr);
void ast_mutex_lock(void *mutex);
void ast_mutex_unlock(void *mutex);
void iax2_destroy(int callno);
int find_callno_locked(int a, int b, struct sockaddr_in *addr, int force, int sockfd, ...);
void *iax2_sched_replace(void *expire, void *sched, int time, void (*callback)(void *), void *arg);
void iax_ie_append_str(struct iax_ie_data *ied, int type, const char *str);
void iax_ie_append_short(struct iax_ie_data *ied, int type, int val);
void send_command(void *iax, int frame_type, int command, int a, char *buf, int pos, int b);
void ast_log(int level, const char *fmt, ...);