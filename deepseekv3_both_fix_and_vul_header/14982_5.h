#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_MAXMS 1000
#define NEW_FORCE 1
#define AST_FRAME_IAX 1
#define IAX_COMMAND_POKE 1
#define LOG_NOTICE 0
#define LOG_WARNING 0

struct iax2_peer {
    int maxms;
    struct sockaddr_in addr;
    void *dnsmgr;
    int lastms;
    int historicms;
    int pokeexpire;
    int callno;
    char *name;
    int sockfd;
    int pokefreqnotok;
};

struct iax2_call {
    int pingtime;
    struct iax2_peer *peerpoke;
};

extern struct iax2_call **iaxs;
extern pthread_mutex_t *iaxsl;
extern void *sched;

static int find_callno(int a, int b, struct sockaddr_in *addr, int c, int d, ...) { return 0; }
static void iax2_destroy(int callno) {}
static int ast_log(int level, const char *format, ...) { return 0; }
static void ast_mutex_lock(pthread_mutex_t *mutex) {}
static void ast_mutex_unlock(pthread_mutex_t *mutex) {}
static int ast_sched_del(void *sched, int id) { return 0; }
static int iax2_sched_add(void *sched, int timeout, void (*callback)(void *), void *data) { return 0; }
static void peer_unref(struct iax2_peer *peer) {}
static struct iax2_peer *peer_ref(struct iax2_peer *peer) { return peer; }
static void iax2_poke_noanswer(void *data) {}
static int send_command(struct iax2_call *call, int type, int cmd, int subclass, void *data, int datalen, int retry) { return 0; }