#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <syslog.h>

#define NEW_FORCE 1
#define AST_FRAME_IAX 1
#define IAX_COMMAND_REGREQ 1

struct iax2_registry {
    char *username;
    struct sockaddr_in addr;
    int regstate;
    int refresh;
    int callno;
    void *dnsmgr;
    void *expire;
};

struct iax_ie_data {
    char *buf;
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

extern int iaxdebug;
extern void *sched;
extern void *iaxsl[];
extern struct iax_call *iaxs[];
extern int defaultsockfd;

void iax2_do_register_s(void *data);