#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#define C_ERR 0
#define C_OK 1
#define ACL_OK 0
#define ACL_DENIED_CMD 1
#define DISK_ERROR_TYPE_NONE 0
#define DISK_ERROR_TYPE_RDB 1
#define REPL_STATE_CONNECTED 1

#define CLIENT_CLOSE_AFTER_REPLY (1<<0)
#define CLIENT_MASTER (1<<1)
#define CLIENT_LUA (1<<2)
#define CLIENT_MULTI (1<<3)
#define CLIENT_PUBSUB (1<<4)
#define USER_FLAG_NOPASS (1<<0)
#define USER_FLAG_DISABLED (1<<1)
#define CMD_WRITE (1<<0)
#define CMD_DENYOOM (1<<1)
#define CMD_STALE (1<<2)
#define CMD_LOADING (1<<3)
#define CMD_NO_AUTH (1<<4)
#define CMD_CALL_FULL (1<<5)

typedef struct redisObject {
    char *ptr;
} redisObject;

typedef struct multiState {
    int cmd_flags;
    int cmd_inv_flags;
} multiState;

typedef struct client {
    int argc;
    redisObject **argv;
    struct redisCommand *cmd;
    struct redisCommand *lastcmd;
    int flags;
    int authenticated;
    int resp;
    long long woff;
    multiState mstate;
    char *masterhost;
} client;

typedef struct redisCommand {
    char *name;
    int arity;
    int flags;
    int (*getkeys_proc)(void);
    int firstkey;
    void (*proc)(client *c);
} redisCommand;

typedef struct clusterNode {
    // dummy definition
} clusterNode;

typedef struct clusterState {
    clusterNode *myself;
} clusterState;

typedef struct sds {
    char *ptr;
    size_t len;
} sds;

typedef struct {
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
} sharedObjectsStruct;

typedef struct user {
    int flags;
} user;

extern sharedObjectsStruct shared;
extern struct redisServer {
    int cluster_enabled;
    clusterState *cluster;
    int maxmemory;
    int lua_timedout;
    client *current_client;
    client *lua_caller;
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
    int aof_last_write_errno;
    long long master_repl_offset;
    struct list *ready_keys;
} server;

extern struct redisCommand *lookupCommand(char *name);
extern void moduleCallCommandFilters(client *c);
extern void addReply(client *c, char *reply);
extern void rejectCommand(client *c, char *err);
extern void rejectCommandFormat(client *c, char *fmt, ...);
extern sds sdsempty(void);
extern size_t sdslen(sds s);
extern sds sdscatprintf(sds s, const char *fmt, ...);
extern void sdsfree(sds s);
extern int ACLCheckCommandPerm(client *c, int *keypos);
extern void addACLLogEntry(client *c, int retval, int keypos, char *reason);
extern clusterNode *getNodeByQuery(client *c, struct redisCommand *cmd, redisObject **argv, int argc, int *hashslot, int *error_code);
extern void discardTransaction(client *c);
extern void flagTransaction(client *c);
extern void clusterRedirectClient(client *c, clusterNode *n, int hashslot, int error_code);
extern int freeMemoryIfNeededAndSafe(void);
extern void trackingLimitUsedSlots(void);
extern int writeCommandsDeniedByDiskError(void);
extern void queueMultiCommand(client *c);
extern void call(client *c, int flags);
extern void handleClientsBlockedOnKeys(void);
extern int listLength(struct list *list);

extern void execCommand(client *c);
extern void discardCommand(client *c);
extern void multiCommand(client *c);
extern void watchCommand(client *c);
extern void unwatchCommand(client *c);
extern void shutdownCommand(client *c);
extern void scriptCommand(client *c);
extern void authCommand(client *c);
extern void helloCommand(client *c);
extern void replconfCommand(client *c);
extern void pingCommand(client *c);
extern void subscribeCommand(client *c);
extern void unsubscribeCommand(client *c);
extern void psubscribeCommand(client *c);
extern void punsubscribeCommand(client *c);
extern void evalCommand(client *c);
extern void evalShaCommand(client *c);
extern user *DefaultUser;