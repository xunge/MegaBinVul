#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define REDIS_NOTUSED(V) ((void) V)
#define REDIS_OK 0
#define REDIS_ERR -1
#define REDIS_WARNING 0
#define REDIS_VERBOSE 0
#define REDIS_NOTICE 0

struct aeEventLoop;
struct dict;
struct saveparam {
    int changes;
    int seconds;
};

struct redisDb {
    struct dict *dict;
    struct dict *expires;
};

struct redisServer {
    int cronloops;
    time_t unixtime;
    int shutdown_asap;
    int dbnum;
    struct redisDb *db;
    pid_t bgsavechildpid;
    pid_t bgrewritechildpid;
    int activerehashing;
    void *clients;
    void *slaves;
    int maxidletime;
    int bpop_blocked_clients;
    int saveparamslen;
    struct saveparam *saveparams;
    int dirty;
    time_t lastsave;
    char *dbfilename;
    char *masterhost;
    int ds_enabled;
    size_t cache_max_memory;
    int vm_enabled;
    size_t vm_max_memory;
    int vm_max_threads;
};

extern struct redisServer server;

void updateLRUClock(void);
int prepareForShutdown(void);
void redisLog(int level, const char *fmt, ...);
long long dictSlots(struct dict *d);
long long dictSize(struct dict *d);
size_t listLength(void *list);
void tryResizeHashTables(void);
void incrementallyRehash(void);
size_t zmalloc_used_memory(void);
void closeTimedoutClients(void);
void backgroundSaveDoneHandler(int statloc);
void backgroundRewriteDoneHandler(int statloc);
void updateDictResizePolicy(void);
int rdbSaveBackground(char *filename);
void activeExpireCycle(void);
void cacheFreeOneEntry(void);
void replicationCron(void);
int vmCanSwapOut(void);
int vmSwapOneObjectBlocking(void);
int vmSwapOneObjectThreaded(void);