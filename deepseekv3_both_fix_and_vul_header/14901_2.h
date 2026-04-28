#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <syslog.h>

struct iax2_registry {
    char *username;
    int regstate;
    void *dnsmgr;
    struct sockaddr_in addr;
    int callno;
    int expire;
    int refresh;
};

struct iax_ie_data {
    char *buf;
    int pos;
};

struct iax2_sock {
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
    NEW_FORCE = 1
};

enum {
    AST_FRAME_IAX,
    IAX_COMMAND_REGREQ
};

#define LOG_WARNING 4
#define LOG_DEBUG 7

extern int iaxdebug;
extern struct iax2_sock *iaxs[];
extern pthread_mutex_t iaxsl[];
extern void *sched;
extern int defaultsockfd;

#define ast_debug(level, format, ...) do { if (iaxdebug) syslog(LOG_DEBUG, format, ##__VA_ARGS__); } while(0)
#define ast_dnsmgr_refresh(dnsmgr) (0)
#define ast_dnsmgr_changed(dnsmgr) (0)
#define ast_mutex_lock(mutex) pthread_mutex_lock(mutex)
#define ast_mutex_unlock(mutex) pthread_mutex_unlock(mutex)
#define ast_log(priority, format, ...) syslog(priority, format, ##__VA_ARGS__)
#define iax_ie_append_str(ied, type, str) do { } while(0)
#define iax_ie_append_short(ied, type, value) do { } while(0)
#define iax2_sched_replace(id, sched, when, callback, data) (0)
#define find_callno_locked(...) (0)
#define iax2_destroy(callno) do { } while(0)
#define send_command(s, frametype, subclass, dlink, buf, len, retransmit) (0)
#define iax2_do_register_s(data) (0)