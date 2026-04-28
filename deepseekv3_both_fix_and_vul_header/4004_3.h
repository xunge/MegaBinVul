#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/time.h>

typedef struct client client;
typedef struct clusterNode clusterNode;
typedef struct clusterState clusterState;
typedef struct redisCommand redisCommand;
typedef struct redisObject redisObject;
typedef char *sds;

#define C_ERR 0
#define C_OK 1
#define ACL_OK 0
#define ACL_DENIED_CMD 1
#define ACL_DENIED_KEY 2
#define ACL_DENIED_CHANNEL 3
#define EVICT_FAIL 0
#define DISK_ERROR_TYPE_NONE 0
#define DISK_ERROR_TYPE_RDB 1
#define CLIENT_CLOSE_AFTER_REPLY (1<<0)
#define CLIENT_MASTER (1<<1)
#define CLIENT_LUA (1<<2)
#define CLIENT_MULTI (1<<3)
#define CLIENT_PUBSUB (1<<4)
#define CLIENT_SLAVE (1<<5)
#define CLIENT_PAUSE_ALL 0
#define CLIENT_PAUSE_WRITE 1
#define CMD_READONLY (1<<0)
#define CMD_WRITE (1<<1)
#define CMD_DENYOOM (1<<2)
#define CMD_STALE (1<<3)
#define CMD_LOADING (1<<4)
#define CMD_NO_AUTH (1<<5)
#define CMD_MAY_REPLICATE (1<<6)
#define USER_FLAG_NOPASS (1<<0)
#define USER_FLAG_DISABLED (1<<1)
#define REPL_STATE_CONNECTED 0
#define BLOCKED_PAUSE 0
#define CMD_CALL_FULL 0

struct sharedObjectsStruct {
    char *ok;
    char *noautherr;
    char *oomerr;
    char *bgsaveerr;
    char *noreplicaserr;
    char *roslaveerr;
    char *masterdownerr;
    char *loadingerr;
    char *slowscripterr;
    char *queued;
} shared;

struct redisServer {
    int lua_timedout;
    int propagate_in_transaction;
    int in_exec;
    int in_eval;
    int cluster_enabled;
    int maxmemory;
    int lua_oom;
    int tracking_clients;
    char *masterhost;
    int repl_min_slaves_to_write;
    int repl_min_slaves_max_lag;
    int repl_good_slaves_count;
    int repl_slave_ro;
    int repl_state;
    int repl_serve_stale_data;
    int loading;
    int client_pause_type;
    int aof_last_write_errno;
    long long master_repl_offset;
    clusterState *cluster;
    client *lua_caller;
    client *current_client;
    struct list *ready_keys;
};

extern struct redisServer server;

struct multiState {
    int cmd_flags;
    int cmd_inv_flags;
};

struct blockingState {
    long long timeout;
};

struct client {
    int flags;
    int authenticated;
    int argc;
    int resp;
    long long woff;
    redisCommand *cmd;
    redisCommand *lastcmd;
    struct multiState mstate;
    redisObject **argv;
    struct blockingState bpop;
};

struct redisCommand {
    char *name;
    int arity;
    int flags;
    int (*proc)(client *c);
    int firstkey;
    int rejected_calls;
};

struct redisObject {
    char *ptr;
};

struct clusterState {
    clusterNode *myself;
};

struct clusterNode {
    int dummy;
};

struct user {
    int flags;
};

extern struct user *DefaultUser;

int (*execCommand)(client *c);
int (*discardCommand)(client *c);
int (*resetCommand)(client *c);
int (*evalCommand)(client *c);
int (*evalShaCommand)(client *c);
int (*pingCommand)(client *c);
int (*subscribeCommand)(client *c);
int (*unsubscribeCommand)(client *c);
int (*psubscribeCommand)(client *c);
int (*punsubscribeCommand)(client *c);
int (*authCommand)(client *c);
int (*helloCommand)(client *c);
int (*replconfCommand)(client *c);
int (*multiCommand)(client *c);
int (*watchCommand)(client *c);
int (*unwatchCommand)(client *c);
int (*shutdownCommand)(client *c);
int (*scriptCommand)(client *c);

size_t sdslen(const sds s);
sds sdsempty(void);
sds sdscatprintf(sds s, const char *fmt, ...);
void sdsfree(sds s);

void serverAssert(int condition);
void moduleCallCommandFilters(client *c);
void addReply(client *c, char *reply);
redisCommand *lookupCommand(char *name);
void rejectCommandFormat(client *c, const char *fmt, ...);
void rejectCommand(client *c, char *reply);
int ACLCheckAllPerm(client *c, int *errpos);
void addACLLogEntry(client *c, int retval, int errpos, char *reason);
int cmdHasMovableKeys(redisCommand *cmd);
clusterNode *getNodeByQuery(client *c, redisCommand *cmd, redisObject **argv, int argc, int *hashslot, int *error_code);
void discardTransaction(client *c);
void flagTransaction(client *c);
void clusterRedirectClient(client *c, clusterNode *n, int hashslot, int error_code);
int performEvictions();
void trackingLimitUsedSlots();
int writeCommandsDeniedByDiskError();
void blockClient(client *c, int type);
void queueMultiCommand(client *c);
void call(client *c, int flags);
void handleClientsBlockedOnKeys();
unsigned long listLength(struct list *list);