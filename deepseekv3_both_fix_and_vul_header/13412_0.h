#include <stdint.h>

typedef struct RedisModuleCtx RedisModuleCtx;
typedef struct RedisModuleString RedisModuleString;
typedef struct RedisRaftCtx RedisRaftCtx;

#define REDISMODULE_APIVER_1 1
#define REDISMODULE_OK 0
#define REDISMODULE_ERR 1
#define REDISMODULE_LOGLEVEL_NOTICE 0
#define REDISMODULE_LOGLEVEL_WARNING 1

#define REDISRAFT_VERSION "0.0.0"
#define REDISRAFT_GIT_SHA1 "unknown"

#define RR_ERROR 1

enum RedisModuleEvent {
    RedisModuleEvent_ClientChange,
    RedisModuleEvent_EventLoop,
    RedisModuleEvent_Config,
    RedisModuleEvent_ModuleChange
};

extern RedisRaftCtx redis_raft;
extern void *redisraft_log_ctx;

int RedisModule_Init(RedisModuleCtx *ctx, const char *name, int ver, int apiver);
int RedisModule_GetServerVersion(void);
void RedisModule_Log(RedisModuleCtx *ctx, int level, const char *fmt, ...);
void *RedisModule_GetDetachedThreadSafeContext(RedisModuleCtx *ctx);
void RedisModule_RegisterInfoFunc(RedisModuleCtx *ctx, void (*cb)(RedisModuleCtx *ctx));
void RedisModule_RegisterCommandFilter(RedisModuleCtx *ctx, void (*filter)(RedisModuleCtx *ctx, void *userdata), int flags);
int RedisModule_SubscribeToServerEvent(RedisModuleCtx *ctx, enum RedisModuleEvent event, void (*callback)(RedisModuleCtx *ctx, void *userdata));

int registerRaftCommands(RedisModuleCtx *ctx);
void handleInfo(RedisModuleCtx *ctx);
void interceptRedisCommands(RedisModuleCtx *ctx, void *userdata);
void handleClientEvent(RedisModuleCtx *ctx, void *userdata);
void beforeSleep(RedisModuleCtx *ctx, void *userdata);
void ConfigRedisEventCallback(RedisModuleCtx *ctx, void *userdata);
void moduleChangeCallback(RedisModuleCtx *ctx, void *userdata);
const char *getStateStr(RedisRaftCtx *rr);
int RedisRaftCtxInit(RedisRaftCtx *rr, RedisModuleCtx *ctx);
void RedisRaftFreeGlobals(void);
void LOG_WARNING(const char *fmt, ...);
void LOG_NOTICE(const char *fmt, ...);

#define RMAPI_FUNC_SUPPORTED(func) (1)