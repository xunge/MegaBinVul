#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define NEW_FORCE 1
#define LOG_WARNING 4
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

struct iax2_registry {
    char *username;
    int regstate;
    struct sockaddr_in addr;
    void *dnsmgr;
    int callno;
    int refresh;
    void *expire;
};

struct iax_ie_data {
    char *buf;
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
extern void iax2_do_register_s(void *reg);