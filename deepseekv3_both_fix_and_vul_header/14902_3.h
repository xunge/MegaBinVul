#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stddef.h>
#include <stdarg.h>

struct iax2_peer {
    int maxms;
    struct sockaddr_in addr;
    void *dnsmgr;
    int lastms;
    int historicms;
    int pokeexpire;
    int callno;
    int sockfd;
    char *name;
    int pokefreqnotok;
    int pingtime;
    struct iax2_peer *peerpoke;
};

extern struct iax2_peer **iaxs;
extern int *iaxsl;
extern void *sched;

void iax2_poke_noanswer(void *data);

#define AST_FRAME_IAX 0
#define IAX_COMMAND_POKE 0
#define LOG_NOTICE 0
#define LOG_WARNING 0
#define NEW_FORCE 0
#define DEFAULT_MAXMS 0