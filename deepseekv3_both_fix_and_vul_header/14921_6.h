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
    char buf[1024];
    int pos;
};

struct iax2_registry {
    char *username;
    int regstate;
    int refresh;
    int callno;
    struct sockaddr_in addr;
    void *dnsmgr;
    void *expire;
};

struct iax2_session {
    struct iax2_registry *reg;
};

extern int iaxdebug;
extern struct iax2_session *iaxs[];
extern pthread_mutex_t iaxsl[];
extern void *sched;
extern int defaultsockfd;
extern void (*iax2_do_register_s)(struct iax2_registry *);

void ast_debug(int level, const char *fmt, ...);
void ast_dnsmgr_refresh(void *dnsmgr);
int ast_dnsmgr_changed(void *dnsmgr);
void ast_mutex_lock(pthread_mutex_t *mutex);
void ast_mutex_unlock(pthread_mutex_t *mutex);
void ast_log(int level, const char *fmt, ...);
void iax2_destroy(int callno);
int find_callno_locked(int a, int b, struct sockaddr_in *addr, int c, int d);
void *iax2_sched_replace(void *a, void *b, int c, void (*d)(struct iax2_registry *), void *e);
void iax_ie_append_str(struct iax_ie_data *ied, int type, const char *str);
void iax_ie_append_short(struct iax_ie_data *ied, int type, int val);
void send_command(void *a, int b, int c, int d, char *e, int f, int g);

#define find_callno_locked(a, b, addr, c, d, ...) find_callno_locked(a, b, addr, c, d)