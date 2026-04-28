#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define IAX_IE_USERNAME 1
#define IAX_IE_REFRESH 2
#define REG_STATE_TIMEOUT 1
#define REG_STATE_REGSENT 2
#define NEW_FORCE 1
#define AST_FRAME_IAX 1
#define IAX_COMMAND_REGREQ 1
#define LOG_WARNING 1

struct iax_ie_data {
    char buf[256];
    int pos;
};

struct iax2_registry {
    char *username;
    int regstate;
    void *dnsmgr;
    struct sockaddr_in addr;
    int callno;
    int refresh;
    void *expire;
};

extern int iaxdebug;
extern void *sched;
extern void *defaultsockfd;
extern pthread_mutex_t iaxsl[];
extern struct iax2_call **iaxs;

void ast_debug(int level, const char *fmt, ...);
void ast_dnsmgr_refresh(void *dnsmgr);
int ast_dnsmgr_changed(void *dnsmgr);
void ast_mutex_lock(pthread_mutex_t *mutex);
void ast_mutex_unlock(pthread_mutex_t *mutex);
void iax2_destroy(int callno);
void *iax2_sched_replace(void *expire, void *sched, int interval, void (*callback)(void *), void *data);
int find_callno_locked(int callno, int flags, struct sockaddr_in *addr, int force, void *sockfd, ...);
void ast_log(int level, const char *fmt, ...);
void iax_ie_append_str(struct iax_ie_data *ied, int type, const char *str);
void iax_ie_append_short(struct iax_ie_data *ied, int type, short value);
void send_command(void *call, int frame_type, int command, int subclass, char *buf, int len, int fd);
void iax2_do_register_s(void *reg);

struct iax2_call {
    struct iax2_registry *reg;
};