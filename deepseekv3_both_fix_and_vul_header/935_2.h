#include <signal.h>
#include <syslog.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define ANET_ERR -1
#define REDIS_WARNING 1
#define AE_READABLE 1
#define AE_ERR -1

typedef struct redisDb {
    void *dict;
    void *expires;
    void *blocking_keys;
    void *watched_keys;
    void *io_keys;
    int id;
} redisDb;

struct redisServer {
    int syslog_enabled;
    char *syslog_ident;
    int syslog_facility;
    pthread_t mainthread;
    void *clients;
    void *slaves;
    void *monitors;
    void *unblocked_clients;
    void *el;
    redisDb *db;
    int dbnum;
    int ipfd;
    char *neterr;
    int port;
    char *bindaddr;
    char *unixsocket;
    int sofd;
    int appendonly;
    char *appendfilename;
    int appendfd;
    int vm_enabled;
    int ds_enabled;
    void *pubsub_channels;
    void *pubsub_patterns;
    int cronloops;
    int bgsavechildpid;
    int bgrewritechildpid;
    char *bgrewritebuf;
    char *aofbuf;
    time_t lastsave;
    int dirty;
    long long stat_numcommands;
    long long stat_numconnections;
    long long stat_expiredkeys;
    long long stat_evictedkeys;
    time_t stat_starttime;
    long long stat_keyspace_misses;
    long long stat_keyspace_hits;
    time_t unixtime;
};

struct dictType {
    /* dummy structure */
};

struct redisServer server;
struct dictType dbDictType;
struct dictType keyptrDictType;
struct dictType keylistDictType;

void setupSigSegvAction(void);
void *listCreate(void);
void createSharedObjects(void);
void *aeCreateEventLoop(void);
void *zmalloc(size_t);
int anetTcpServer(char *, int, char *);
int anetUnixServer(char *, char *);
void redisLog(int, const char *, ...);
void *dictCreate(struct dictType *, void *);
void listSetFreeMethod(void *, void (*)(void *));
void listSetMatchMethod(void *, int (*)(void *, void *));
char *sdsempty(void);
void *aeCreateTimeEvent(void *, long long, void *, void *, void *);
int aeCreateFileEvent(void *, int, int, void (*)(void), void *);
void oom(const char *);
void freePubsubPattern(void *);
int listMatchPubsubPattern(void *, void *);
void serverCron(void *, void *);
void acceptTcpHandler(void);
void acceptUnixHandler(void);
void vmInit(void);
void dsInit(void);