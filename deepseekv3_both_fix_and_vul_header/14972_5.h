#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define DEFAULT_MAXMS 1000
#define LOG_NOTICE 5
#define LOG_WARNING 4
#define AST_FRAME_IAX 1
#define IAX_COMMAND_POKE 2
#define NEW_FORCE 1

struct iax2_peer {
    int maxms;
    struct sockaddr_in addr;
    int dnsmgr;
    int lastms;
    int historicms;
    int pokeexpire;
    int callno;
    char *name;
    int sockfd;
    int pokefreqnotok;
};

struct iax2_session {
    int pingtime;
    struct iax2_peer *peerpoke;
};

extern pthread_mutex_t iaxsl[];
extern struct iax2_session *iaxs[];
extern void *sched;

int find_callno(int a, int b, struct sockaddr_in *addr, int c, int sockfd, ...);
void iax2_destroy(int callno);
void ast_log(int level, const char *format, ...);
void ast_mutex_lock(pthread_mutex_t *mutex);
void ast_mutex_unlock(pthread_mutex_t *mutex);
int ast_sched_del(void *sched, int id);
int iax2_sched_add(void *sched, int timeout, void (*callback)(void *), void *data);
void peer_unref(struct iax2_peer *peer);
struct iax2_peer *peer_ref(struct iax2_peer *peer);
void iax2_poke_noanswer(void *data);
int send_command(struct iax2_session *session, int frame_type, int command, int subclass, void *data, int datalen, int retry);