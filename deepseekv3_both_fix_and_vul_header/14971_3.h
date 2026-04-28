#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <syslog.h>
#include <pthread.h>

#define LOG_WARNING 4
#define NEW_FORCE 1
#define AST_FRAME_IAX 1
#define IAX_COMMAND_REGREQ 1

enum {
    REG_STATE_TIMEOUT,
    REG_STATE_REGSENT
};

enum {
    IAX_IE_USERNAME,
    IAX_IE_REFRESH
};

struct iax_ie_data {
    unsigned char *buf;
    int pos;
};

struct iax2_call {
    struct iax2_registry *reg;
};

struct iax2_registry {
    char *username;
    void *dnsmgr;
    int regstate;
    struct sockaddr_in addr;
    int callno;
    int expire;
    int refresh;
};

extern int iaxdebug;
extern void *sched;
extern struct iax2_call **iaxs;
extern pthread_mutex_t *iaxsl;
extern int defaultsockfd;

void iax2_do_register_s(void *data);