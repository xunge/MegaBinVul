#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define IAX_IE_USERNAME 0
#define IAX_IE_REFRESH 0
#define AST_FRAME_IAX 0
#define IAX_COMMAND_REGREQ 0
#define NEW_FORCE 0
#define REG_STATE_TIMEOUT 0
#define REG_STATE_REGSENT 0
#define LOG_WARNING 0

struct iax2_registry {
    char *username;
    int regstate;
    int refresh;
    int callno;
    struct sockaddr_in addr;
    void *dnsmgr;
    void *expire;
};

struct iax_ie_data {
    char buf[256];
    int pos;
};

struct iax_call {
    struct iax2_registry *reg;
};

extern int iaxdebug;
extern void *sched;
extern void *iaxsl[];
extern struct iax_call *iaxs[];
extern int defaultsockfd;

void ast_debug(int level, const char *fmt, ...);
void ast_dnsmgr_refresh(void *dnsmgr);
int ast_dnsmgr_changed(void *dnsmgr);
void ast_mutex_lock(void *mutex);
void ast_mutex_unlock(void *mutex);
void iax2_destroy(int callno);
int find_callno_locked(int a, int b, struct sockaddr_in *addr, int flag, int sockfd, ...);
void *iax2_sched_replace(void *expire, void *sched, int time, void (*func)(void *), void *arg);
void iax_ie_append_str(struct iax_ie_data *ied, int type, const char *str);
void iax_ie_append_short(struct iax_ie_data *ied, int type, int val);
void send_command(struct iax_call *iax, int frame_type, int command, int a, char *buf, int pos, int b);
void ast_log(int level, const char *fmt, ...);
void iax2_do_register_s(void *arg);