#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <syslog.h>
#include <pthread.h>

struct iax2_registry {
    char *username;
    int regstate;
    struct ast_dnsmgr *dnsmgr;
    struct sockaddr_in addr;
    int callno;
    int refresh;
    int expire;
};

struct iax_ie_data {
    unsigned char buf[1024];
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
    NEW_FORCE = 1
};

enum {
    IAX_IE_USERNAME,
    IAX_IE_REFRESH
};

enum {
    AST_FRAME_IAX,
    IAX_COMMAND_REGREQ
};

typedef pthread_mutex_t ast_mutex_t;

extern int option_debug;
extern int iaxdebug;
extern struct iax2_sock *iaxs[];
extern ast_mutex_t iaxsl[];
extern int defaultsockfd;
extern struct sched_context *sched;

int iax2_do_register_s(void *data);